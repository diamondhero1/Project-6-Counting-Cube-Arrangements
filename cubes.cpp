//
// Created by Christopher Lee on 10/18/23.
//

#include "cubes.h"
using namespace std;


cube::cube(){
    direction = 0;
}

int cube::getDirection(){
    return direction;
}

void cube::rotate90(){

}

tunnel::tunnel(int dir){
    direction = dir;
}

void tunnel::rotate90(){
    if(direction == 2)
    {
        direction = 1;
    }
    else {
        direction++;
    }
}

room::room(int dir){
    direction = dir;
}

void room::rotate90(){
    if(direction == 6)
    {
        direction = 3;
    }
    else {
        direction ++;
    }
}
