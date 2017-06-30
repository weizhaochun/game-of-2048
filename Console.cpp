/*
 * project£º2048
 *
 *  Created on: May£¬ 4£¬ 2014
 *  Updated on: June, 9, 2017
 *      Author: yuangungun/BIOHAZARDX
 *
 */

/*
 * Disclaimer:
 * 1¡¢ This procedure can not be used for any commercial form£»
 * 2¡¢ This program is only for the open source community discussion£»
 * 3¡¢ The right of final interpretation for the 2048 game belongs to its service provider
 * 4¡¢ There are some bugs in it, don't use it incorectly
 */

/*
 *
 * copyright @2048 all right reserved
 * main.cpp
 * revise instruct:
 * 1¡¢If you wanna a UI interface please contract MFC or other tools£»
 * 2¡¢There is no random "4" in this game, but 2048 has, you can add yourself£»
 * 3¡¢ You can optimize the data structure for matrix, may be std::queue£»
 * 4¡¢ Some operating system does not support <curses.h>, so use it if you like£»
 * 5¡¢ You can use new method to improve control£»
 * 6¡¢ If you like, add a situation for gameover
 *
 */

#include <iostream>
#include <time.h>
#include <fstream>
#include "Matrix.h"
//#include <curses.h>
using namespace std;
int main()
{
  int best;
  Matrix m(0, 13);
  ifstream in;
  in.open("test.txt");

  in >> best;
  in.close();
  cout << m;
  cout << "history best: " << best << endl;

  char c;
  while (cin >> c)
  {
    bool flag = false;
    switch (c)
	{ // a, d, w, s stand for left, right, up and down
      case 'a':
        flag = m.moveLeft();
        break;
      case 'd':
        flag = m.moveRight();
        break;
      case 'w':
        flag = m.moveUp();
        break;
      case 's':
        flag = m.moveDown();
        break;
      default:
        cout << "Error input , please input 'w' 'a' 's' 'd' " << endl;
        break;
    }

    if(m.score>best){
        ofstream out;
        out.open("test.txt");
        out << m.score << endl;
        out.close();
    }
    if (flag){// if the matrix changes, add a 2 to the matrix
		m.updatematrix();
        system("cls");
        cout << m;
        cout << "history best: " << best << endl;
    }
  }
}
