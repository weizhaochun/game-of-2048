/*
 * project£º2048
 *
 *  Created on: May£¬ 4£¬ 2014
 *  Updated on: June, 9, 2017
 *      Author: yuangungun/BIOHAZARDX
 *
 *
 *  Matrix.cpp
 */

#include "Matrix.h"
#include <math.h>
#include <iomanip>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

// constructor p1 means the first random place for value 2, p2 means the second
// constructor define the initialized matrix for 2048 game
Matrix::Matrix(int p1, int p2)
{
	int *p = &num[0][0]; // defined a pointer
	memset(num, 0, sizeof(num)); // initialize the matrix num
	*(p + p1) = 2; // the first value
	*(p + p2) = 2; // the second
}

bool Matrix::moveLeft()
{
    bool flag=true;
	int i=0,j=0,k=0;
	for(i=0;i<4;i++){
        for(k=0;k<3;k++){
            for(j=0;j<3-k;j++){
                if(num[i][j]==0){
                   num[i][j]=num[i][j+1];
                   num[i][j+1]=0;
                   flag=false;
                }
                else{
                    if(num[i][j]==num[i][j+1]){
                        num[i][j]+=num[i][j+1];
                        num[i][j+1]=0;
                        score++;
                    }
                }
            }
            if(flag)
                break;
        }
	}
	step++;
	return true;
}

bool Matrix::moveRight()
{
    bool flag=true;
	int i=0,j=0,k=0;
	for(i=0;i<4;i++){
        for(k=0;k<3;k++){
            for(j=3;j>0+k;j--){
                if(num[i][j]==0){
                   num[i][j]=num[i][j-1];
                   num[i][j-1]=0;
                   flag=false;
                }
                else{
                    if(num[i][j]==num[i][j-1]){
                        num[i][j]+=num[i][j-1];
                        num[i][j-1]=0;
                        score++;
                    }
                }
            }
            if(flag)
                break;
        }
	}
	step++;
	return true;
}

bool Matrix::moveUp()
{
	bool flag=true;
	int i=0,j=0,k=0;
	for(j=0;j<4;j++){
        for(k=0;k<3;k++){
            for(i=0;i<3-k;i++){
                if(num[i][j]==0){
                   num[i][j]=num[i+1][j];
                   num[i+1][j]=0;
                   flag=false;
                }
                else{
                    if(num[i][j]==num[i+1][j]){
                        num[i][j]+=num[i+1][j];
                        num[i+1][j]=0;
                        score++;
                    }
                }
            }
            if(flag)
                break;
        }
	}
	step++;
	return true;
}

bool Matrix::moveDown()
{
	bool flag=true;
	int i=0,j=0,k=0;
	for(j=0;j<4;j++){
        for(k=0;k<3;k++){
            for(i=3;i>0+k;i--){
                if(num[i][j]==0){
                   num[i][j]=num[i-1][j];
                   num[i-1][j]=0;
                   flag=false;
                }
                else{
                    if(num[i][j]==num[i-1][j]){
                        num[i][j]+=num[i-1][j];
                        num[i-1][j]=0;
                        score++;
                    }
                }
            }
            if(flag)
                break;
        }
	}
	step++;
	return true;
}

bool Matrix::add(int p)
{
  int *q = &num[0][0];
  if (*(q + p) == 0)
  {
    *(q + p) = 2;
    return true;
  }
  return false;

}

ostream& operator<<(ostream& out, const Matrix& matirx)
{
  out << "---enjoy game   enjoy life---" << endl;
  out << "-----------------------------" << endl;
  for (int i = 0; i <= 3; i++)
  {
    for (int j = 0; j <= 3; j++)
	{
      out << "|" << setw(6);
      if (matirx.num[i][j] != 0)
        out << matirx.num[i][j];
      else
        out << " ";
    }
    out << "|" << endl;
  }
  out << "-----------------------------" << endl;
  out << "step: " << matirx.step <<"  score: " << matirx.score << endl;
  return out;
}
