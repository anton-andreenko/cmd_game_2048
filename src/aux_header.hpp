// aux_header.hpp

#ifndef AUX_HEADER_H
#define AUX_HEADER_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

// aliases

typedef char user_action_t;
typedef const char * text_t;
typedef int cell_t;
typedef cell_t * field_t;

// structs

struct move_check_t
{
    bool is_up;
    bool is_down;
    bool is_left;
    bool is_right;
};

// constants

const int SIZE_X = 4;
const int SIZE_Y = SIZE_X;
const int SIZE_XY = SIZE_X * SIZE_Y;

const cell_t CELL_2048 = 2048;
const cell_t CELL_0 = 0;
const cell_t CELL_2 = 2;
const cell_t CELL_4 = 4;

const user_action_t UA_EXIT = '0';
const user_action_t UA_RESET = '1';
const user_action_t UA_MOVE_UP = 'w';
const user_action_t UA_MOVE_DOWN = 's';
const user_action_t UA_MOVE_LEFT = 'a';
const user_action_t UA_MOVE_RIGHT = 'd';

#endif // AUX_HEADER_H
