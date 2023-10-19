
//
// Created by Christopher Lee on 10/18/23.
//

#ifndef PROJECT_6_COUNTING_CUBE_ARRANGEMENTS_CUBES_H
#define PROJECT_6_COUNTING_CUBE_ARRANGEMENTS_CUBES_H

class cube {
public:
    cube();
    int direction = 0;
    void getDirection();
    virtual void rotate90();
};

class tunnel: public cube {
public:
    tunnel(int dir);
    void rotate90();
};

class room: public cube{
public:
    room(int dir);
    void rotate90();
};

#endif //PROJECT_6_COUNTING_CUBE_ARRANGEMENTS_CUBES_H
