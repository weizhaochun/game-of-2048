/*
 * project£º2048
 *
 *  Created on: May£¬ 4£¬ 2014
 *  Updated on: June, 9, 2017
 *      Author: yuangungun/BIOHAZARDX
 *
 *
 *  Matrix.h
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <time.h>
#include <stdlib.h>

#define rows 4
#define cols 4
#define L 6

using std::ostream;

class Matrix {
  friend ostream& operator<<(ostream& out, const Matrix& matirx);
  // here is an output example
  // -----------------------------
  // |    16|     8|     4|     2|
  // |     8|     8|     4|     2|
  // |      |     4|     8|     2|
  // |      |      |     2|     2|
  // -----------------------------
public:
  Matrix(int p1, int p2);
  ~Matrix(){ /* nop*/ }
  bool moveLeft(); // return true if the matrix changes
  bool moveRight(); // return true if the matrix changes
  bool moveUp(); // return true if the matrix changes
  bool moveDown(); // return true if the matrix changes
  bool add(int p); // return true if the matrix changes
  void updatematrix()
  { // add a 2 to the possible lowest position
    int i;
    while (1)
	{
      i = rand() % 15;
      if (add(i))
        return;
    }
  }
  int score=0;

private:
  int num[rows][cols];
  int step=0;
};

#endif
