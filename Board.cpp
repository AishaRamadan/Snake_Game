#undef byte.
#include<Windows.h>
#include"Board.h"
#include<conio.h>
#include<cstdlib>

Board::Board(int r, int c) {
    rows = r;
    columns = c;
    score = 0;
    ptr = new char *[r];
    for (int i = 0; i < r; i++) {
        ptr[i] = new char[c];
    }
    reset_board();
    snake.set_head({ rows / 2,columns / 2 });
    dollar.update_pos(get_empty_point());
}

Board::~Board() {
    for (int i = 0; i < rows; ++i) {
        delete[] ptr[i];
    }
    delete[] ptr;
}

void Board::play() {
    bool f = true;
    while (!is_lose()) {
        print();
        if (f) {
            cout << "press any key to start..";
            char x; x = _getch();
            x = take_dir(x);
            if (x != '0') {
                snake.set_dir(x);
            }
            f = 0;
        }
        else {
            char x = take_dir();
            if (x != '0') {
                snake.set_dir(x);
            }
        }
        snake.move();
        Sleep(60);
        update_game();

        system("cls");
    }
    print();
    cout << "Game over.. the final wealth is " << score << " $\n";
    cout << "Do you want to play again (y,n) ? .. ";
    char c; cin >> c;
   char x = tolower(c);
    while (x != 'y' && x != 'n') {
        cin >> c;
        x = c;
    }
    if (x == 'y') {
        restart_game();
    }
    else return;
}
void Board::update_game() {
    point sn = snake.get_head(), fruit = dollar.get_pos();
    vector<point>& tail = snake.get_tail();
    if (sn.r == fruit.r && sn.c == fruit.c) {
        score++;

        if (tail.empty()) {
            tail.push_back(sn);
        }
        else {
            tail.push_back(tail.back());
        }
        dollar.update_pos(get_empty_point());
    }
}

void Board::print() {
    reset_board();

    point dol_pos = dollar.get_pos(), sn_head = snake.get_head();
    ptr[dol_pos.r][dol_pos.c] = '$';
    ptr[sn_head.r][sn_head.c] = 'O';
    vector<point>&sn_tail = snake.get_tail();
    for (auto& i : sn_tail) {
        ptr[i.r][i.c] = 'o';
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << ptr[i][j];
        }
        cout << "\n";
    }
    cout << "the wealth of the snake = " << score << " $" << "\n";
}

char Board::take_dir(char x) {
    char c = '0', ch = snake.get_dir();
    if (x != '0') {
        c = tolower(x);
    }
    else if (_kbhit()) {
        c = tolower(_getch());
    }

    if (c == 'w' && ch != 'd') {
        return 'u';
    }
    else if (c == 's' && (ch != 'u' || x != '0')) {
        return 'd';
    }
    else if (c == 'd' && ch != 'l') {
        return 'r';
    }
    else if (c == 'a' && ch != 'r') {
        return 'l';
    }
    else return '0';
}

bool Board::is_lose() {
    int rr = snake.get_head().r, cc = snake.get_head().c;
    if (rr == 0 || rr == rows - 1) {
        return true;
    }
    if (cc == 0 || cc == columns - 1) {
        return true;
    }

    vector<point>&tails = snake.get_tail();
    for (auto& i : tails) {
        if (i.r == rr && i.c == cc && tails.size() >= 4) {
            return true;
        }
    }
    return false;
}

vector<point> Board::get_empty_point() {
    vector<point>v;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (ptr[i][j] == ' ') {
                v.push_back({ i,j });
            }
        }
    }
    return v;
}

void Board::reset_board() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                ptr[i][j] = '#';
            }
            else {
                ptr[i][j] = ' ';
            }
        }
    }
}

void Board::restart_game() {
    reset_board();
    snake.set_head({ rows / 2,columns / 2 });
    snake.set_dir('u');
    score = 0;
    dollar.update_pos(get_empty_point());
    snake.get_tail().clear();
    play();
}
