// ---------------------------------------------------------------------
//
// Copyright (C) 2021 - 2021 by the Greedy snake authors
//
// Point.h
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

#ifndef POINT_H_
#define POINT_H_

#pragma once

struct Point
{
    Point ()
        : x(0),
          y(0)
    {
    }
    Point (int x0, int y0)
        : x(x0),
          y(y0)
    {
    }
    int x;
    int y;

    bool operator== (const Point &other) const
    {
      if (this->x == other.x && this->y == other.y)
        return true;
      else
        return false;
    }

    bool operator!= (const Point &other) const
    {
      if (this->x != other.x || this->y != other.y)
        return true;
      else
        return false;
    }

    Point& operator= (const Point &other)
    {
      this->x = other.x;
      this->y = other.y;
      return *this;
    }

    Point& operator= (const int &value)
    {
      this->x = value;
      this->y = value;
      return *this;
    }
};

#endif /* POINT_H_ */
