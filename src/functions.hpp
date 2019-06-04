// functions.hpp

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "aux_header.hpp"

namespace Functions
{
    void ClearStdInBuffer();
    user_action_t InputValue();
    void InitField(field_t & arg_1, cell_t * arg_2);
    void ClearField(field_t field_1);
    void AddRandomCell(field_t field_1);
    void RotationField(field_t field_1, int rotation_count);
    bool CheckUp(const field_t field_1);
    bool CheckDown(const field_t field_1);
    bool CheckLeft(const field_t field_1);
    bool CheckRight(const field_t field_1);
    int MoveUp(field_t field_1);
    int MoveDown(field_t field_1);
    int MoveLeft(field_t field_1);
    int MoveRight(field_t field_1);
    int SumLeft(field_t field_1);
    void ShiftLeft(field_t field_1);
    void PrintSceneDelimiter();
    void PrintSimpleText(text_t text);
    void PrintCustomText(text_t text, int arg);
    void PrintField(const field_t field_1);
    bool CheckEndGame(const move_check_t & r_move_check, const field_t field_1);
    void ExitDelay();
}

#endif // FUNCTIONS_H
