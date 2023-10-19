//
// Created by fowle on 9/29/2023.
//


#include "cubes.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    cube c1 = cube();
    tunnel t1 = tunnel(1);
    room r1 = room(1);
    cout << t1.getDirection() << endl;

}
