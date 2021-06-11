// ---------------------------------------------------------------------
//
// Copyright (C) 2021 - 2021 by the Greedy snake authors
//
// kbhit.h
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
// Refs: https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
// ---------------------------------------------------------------------

#ifndef KBHIT_H_
#define KBHIT_H_


#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

inline void changemode(int dir)
{
  static struct termios oldt, newt;

  if ( dir == 1 )
  {
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  }
  else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}

inline int kbhit (void)
{
  struct timeval tv;
  fd_set rdfs;

  tv.tv_sec = 0;
  tv.tv_usec = 0;

  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);

  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);

}

#endif  /* KBHIT_H_ */
