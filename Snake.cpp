#include "Snake.h"
void Snake::move() {
    for (int i = tails.size() - 1; i >= 1; --i) {
        tails[i] = tails[i - 1];
    }
    if (!tails.empty()) {
        tails[0] = head_pos;
    }
    if (direction == 'u') {  // up
        head_pos.r--;
    }
    else if (direction == 'd') {  // down
        head_pos.r++;
    }
    else if (direction == 'l') {  // left
        head_pos.c--;
    }
    else head_pos.c++; // right
}
void Snake::set_head(point x) {
    head_pos.r = x.r;
    head_pos.c = x.c;
}
point Snake::get_head() {
    return head_pos;
}
void Snake::set_tails(vector<point> tails) {
    this->tails = tails;
}
vector<point>& Snake::get_tail() {
    return tails;
}
void Snake::set_dir(char x) {
    direction = x;
}
char Snake::get_dir() {
    return direction;
}
