/*
 * glowny.cpp
 *
 *  Created on: 18 lis 2025
 *      Author: daniel
 */

#include "wektor.h"


int main() {
  wektor w1(3);
  w1.Ustaw(2, 1);
  w1.Drukuj();
  wektor w2;
  w2 = w1;
  w2.Ustaw(0, 2);
  w2.Drukuj();
  w2 = w1;
  w2.Drukuj();
  w2 = w1 + w2;
  w2.Drukuj();
  return 0;
}
