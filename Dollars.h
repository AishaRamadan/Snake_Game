#ifndef DOLLARS_H
#define DOLLARS_H
#include<iostream>
#include"Snake.h"
using namespace std;
class Dollars{
private:
    point dollar_pos;
public:
    void update_pos(vector<point>);
    point get_pos();
};
#endif