// ---------------------------------------------------------------------
//
// Copyright (C) 2021 - 2021 by the Greedy snake authors
//
// main.h
//
// This file is part of the Greedy snake project.
//
// The Greedy snake is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file lesser.txt at
// the top level directory of the project.
//
// Author: Zhidong Brian Zhang
// Created on: Jun.05 2021
// Updated on: xxx.xx xxxx
//
// ---------------------------------------------------------------------

#include "Snake.h"

int main ()
{
  try
  {
    Snake snake;
    snake.Run();
  }
  catch (std::exception &exc)
  {
    std::cerr << std::endl << std::endl
              << "----------------------------------------------------"
              << std::endl;
    std::cerr << "Exception on processing: " << std::endl << exc.what()
              << std::endl << "Aborting!" << std::endl
              << "----------------------------------------------------"
              << std::endl;
    return 1;
  }
  catch (...)
  {
    std::cerr << std::endl << std::endl
              << "----------------------------------------------------"
              << std::endl;
    std::cerr << "Unknown exception!" << std::endl << std::endl << "Aborting!"
              << std::endl
              << "----------------------------------------------------"
              << std::endl;
    return 1;
  }
}
