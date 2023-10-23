//
// Created by fowle on 9/29/2023.
//
#include "cubes.h"
#include "tower.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//cube is 1
//tunnel 1 and 2
//room

int main() {
    cube c1 = cube();
    tunnel t1 = tunnel(1);
    room r1 = room(3);
    cout << t1.getDirection() << endl;
    tower tower1 = tower(&c1, &t1, &r1);
    tower1.printtower();
    tower1.rotate90();
    tower1.printtower();
    tower1.showtower();
    tower tower2 = tower(&t1, &t1, &r1);
    tower2.showtower();
    cout << tower1.Equals(tower2) << endl;
}
