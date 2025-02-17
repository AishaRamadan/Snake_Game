#ifndef SNAKE_H
#define SNAKE_H
#include<iostream>
#include<vector>
using namespace std;
struct point{
    int r,c;    
};
class Snake{
private:
    point head_pos;
    vector<point>tails;
    char direction='u';
public:
    void move();
    void set_head(point x);
    point get_head();
    void set_tails(vector<point>tails);
    vector<point> &get_tail();
    void set_dir(char x);
    char get_dir();
};
#endif