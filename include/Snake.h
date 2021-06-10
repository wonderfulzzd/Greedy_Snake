// ---------------------------------------------------------------------
//
// Copyright (C) 2021 - 2021 by the Greedy snake authors
//
// Snake.h
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

#ifndef SNAKE_H_
#define SNAKE_H_

#pragma once

#include <vector>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <random>
#include <algorithm>
#include "Point.h"

// Key board detection
#ifdef __linux__
#include "kbhit/kbhit.h"
#elif _WIN32
#include <conio.h>
#endif

using namespace std;

/*
 * Snake class
 */
class Snake
{
  public:

    /*
     * constructor
     */
    Snake ();

    /*
     * run function of the program
     */
    void Run ();

  private:

    /*
     * parameters and variables
     */
    const int sleepTime; // sleep time in milliseconds
    const int width; // domain width
    const int height; // domain depth
    char direction; // snake moving direction
    int dx; // x moving distance
    int dy; // y moving distance
    int score; // score
    Point food; // food location
    std::vector<char> map; // gaming domain map
    std::vector<Point> snakeBody; // gaming domain map
    std::random_device rex; // x random number generator
    std::random_device rey; // y random number generator
    uniform_int_distribution<int> udx; // x
    uniform_int_distribution<int> udy; // y

    /*
     * initialize the system
     */
    void Init ();

    /*
     * check collision
     */
    bool CheckCollision ();

    /*
     * generate food
     */
    void GenerateFood ();

    /*
     * get moving direction
     */
    void GetDirection ();

    /*
     * move snake
     */
    void Move ();

    /*
     * print the map
     */
    void PrintMap ();

    /*
     * sleep for a while
     */
    void Sleep ();
};

#endif /* SNAKE_H_ */
