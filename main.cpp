//
// Created by fowle on 9/29/2023.
//


#include "cubes.h"
#include "tower.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    cube c1 = cube();
    tunnel t1 = tunnel(1);
    room r1 = room(3);
    tower tower1 = tower(&c1, &t1, &r1);
    tower1.printtower();
    tower1.verticalFlip();
    tower1.printtower();
    cube c2 = cube();
    tunnel t2 = tunnel(2);
    room r2 = room(4);
    tower tower2 = tower(&r2, &t2, &c2);
    cout << tower1.Equals(tower2) << endl;
}
