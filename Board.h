#ifndef BOARD_H
#define BOARD_H
#include<iostream>
#include"Snake.h"
#include"Dollars.h"
using namespace std;
class Board{
private:
    int rows,columns,score;
    char **ptr; // 2D array of Board
    Snake snake;
    Dollars dollar;
    bool is_lose();
    void print();
    void update_game();
    char take_dir(char ch='0');
    vector<point> get_empty_point();
    void reset_board();
    void restart_game();
public:
    Board(int r,int c);
    void play();
    ~Board();
};
#endif