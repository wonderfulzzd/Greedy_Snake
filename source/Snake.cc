// ---------------------------------------------------------------------
//
// Copyright (C) 2021 - 2021 by the Greedy snake authors
//
// Snake.cc
//
// This file is part of the Greedy snake project.
//
// The Greedy snake is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of LPBF.
//
// Author: Zhidong Brian Zhang
// Created on: Jun.05 2021
// Updated on: xxx.xx xxxx
//
// ---------------------------------------------------------------------

#include "Snake.h"

Snake::Snake ()
    : sleepTime(500),
      width(20),
      height(20),
      direction('d'),
      dx(1),
      dy(0),
      score(0),
      food(),
      map(width * height),
      snakeBody(4, Point())
{
}

void Snake::Run ()
{
  Init();

  while (!CheckCollision())
  {
    GenerateFood();
    GetDirection();
    Move();
    PrintMap();
    Sleep();
  }

  std::cout << "Game Over!" << std::endl;
}

void Snake::Init ()
{
  // initialize the map
  for (int j = 0; j < height; ++j)
    for (int i = 0; i < width; ++i)
    {
      if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
      {
        map[j * width + i] = '*';

      } else
      {
        map[j * width + i] = ' ';
      }
    }

  // initialize the snake body
  for (auto it = snakeBody.begin(); it != snakeBody.end(); ++it)
  {
    it->x = width / 2 + it - snakeBody.begin();
    it->y = height / 2;
    map[it->y * width + it->x] = 'o';
  }
  // head, the last element in the vector
  map[snakeBody.back().y * width + snakeBody.back().x] = '@';

  // initialize food
  food.x = std::rand() % (width - 3) + 1;
  food.y = std::rand() % (height - 3) + 1;
  auto p = std::find(snakeBody.begin(), snakeBody.end(), food);
  while (p != snakeBody.end()) // not found
  {
    food.x = std::rand() % (width - 3) + 1;
    food.y = std::rand() % (height - 3) + 1;
    p = std::find(snakeBody.begin(), snakeBody.end(), food);
  }
  map[food.y * width + food.x] = '$';
}

bool Snake::CheckCollision ()
{
  auto p = std::find(snakeBody.begin(), snakeBody.end() - 1, snakeBody.back());
  if (p != snakeBody.end() - 1) // collide with body
    return true;
  else if (snakeBody.back().x <= 0 || snakeBody.back().x >= width - 1
           || snakeBody.back().y <= 0 || snakeBody.back().y >= height - 1) // collide with walls
    return true;
  else
    return false; // no collison
}

void Snake::GenerateFood ()
{
  // if food is empty, then generate a new food, otherwise not generate
  if (food == Point(0, 0))
  {
    // generate a new food
    food.x = std::rand() % (width - 3) + 1;
    food.y = std::rand() % (height - 3) + 1;
    auto p = std::find(snakeBody.begin(), snakeBody.end(), food);

    std::cout << "p!=snakeBody.end(): " << (p != snakeBody.end()) << std::endl;

    while (p != snakeBody.end()) // not found
    {
      food.x = std::rand() % (width - 3) + 1;
      food.y = std::rand() % (height - 3) + 1;
      p = std::find(snakeBody.begin(), snakeBody.end(), food);
    }
  }
}

void Snake::GetDirection ()
{
#ifdef __linux__
  //Get the direction button, use a direction to store
  changemode(1);
  if (kbhit())
  {
    char kbhitInput;
    std::cin >> kbhitInput;
    if (kbhitInput == 'W' || kbhitInput == 'S' || kbhitInput == 'A'
        || kbhitInput == 'D' || kbhitInput == 'w' || kbhitInput == 's'
        || kbhitInput == 'a' || kbhitInput == 'd')
    {
      direction = kbhitInput;
    }
  }
  changemode(0);
#elif _WIN32
  //Get the direction button, use a direction to store
  if (kbhit())
  {
    char kbhitInput;
    kbhitInput = getch();
    if (kbhitInput == 'W' || kbhitInput == 'S' || kbhitInput == 'A'
        || kbhitInput == 'D' || kbhitInput == 'w' || kbhitInput == 's'
        || kbhitInput == 'a' || kbhitInput == 'd')
    {
      direction = kbhitInput;
    }
  }
#endif
}

/*
 * Move the snake
 */
void Snake::Move ()
{
  // get moving info.
  if (direction == 'D' || direction == 'd')
  {
    dx = 1;
    dy = 0;
  } else if (direction == 'W' || direction == 'w')
  {
    dx = 0;
    dy = -1;
  } else if (direction == 'A' || direction == 'a')
  {
    dx = -1;
    dy = 0;
  } else if (direction == 'S' || direction == 's')
  {
    dx = 0;
    dy = 1;
  }

  // move snake body
  if (snakeBody.back().x + dx == food.x && snakeBody.back().y + dy == food.y) // eat food
  {
    Point addPoint(snakeBody.back().x + dx, snakeBody.back().y + dy);
    snakeBody.push_back(addPoint);
    food = 0; // make food empty
    score++;
  } else // not eat food
  {
    for (auto it = snakeBody.begin(); it < snakeBody.end() - 1; ++it)
    {
      it->x = (it + 1)->x; // replaced by its previous x member
      it->y = (it + 1)->y; // replaced by its previous y member
    }
    // move the head, the last element in the vector
    snakeBody.back().x += dx;
    snakeBody.back().y += dy;
  }

  // initial the map
  for (int j = 0; j < height; ++j)
    for (int i = 0; i < width; ++i)
    {
      if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
      {
        map[j * width + i] = '*';

      } else
      {
        map[j * width + i] = ' ';
      }
    }

  // update the snake body in map
  for (auto it = snakeBody.begin(); it != snakeBody.end(); ++it)
  {
    map[it->y * width + it->x] = 'o';
  }
  map[snakeBody.back().y * width + snakeBody.back().x] = '@'; // head

  // update food in map
  if (food != Point(0, 0))
    map[food.y * width + food.x] = '$';

}

void Snake::PrintMap ()
{
#ifdef __linux__
  int sys_cls = system("clear");
#elif _WIN32
    int sys_cls = system("cls");
  #endif
  if (sys_cls)
    throw invalid_argument("Clearing terminal failed!");

  for (int j = 0; j < height; ++j)
    for (int i = 0; i < width; ++i)
    {
      std::cout << map[j * width + i] << ' ';
      if (i + 1 == width)
        std::cout << '\n';
    }
  std::cout << "Score: " << score << std::endl;
}

void Snake::Sleep ()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
}

