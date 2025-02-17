#include"Dollars.h"
#include<cstdlib>
void Dollars::update_pos(vector<point>valid_pos) {
    if (valid_pos.empty()) {
        dollar_pos.r = -1;
        dollar_pos.c = -1;
        return;
    }
    srand(time(nullptr));
    int idx = rand() % valid_pos.size();
    dollar_pos.r = valid_pos[idx].r;
    dollar_pos.c = valid_pos[idx].c;
}

point Dollars::get_pos() {
    return dollar_pos;
}