// main.cpp

#include "aux_header.hpp"
#include "functions.hpp"

using namespace Functions;

int main()
{
    std::srand(std::time(0));
    user_action_t user_action = 0;
    field_t field_user = nullptr;
    cell_t core_matrix[SIZE_XY] = {};
    move_check_t move_check = {false, false, false, false};
    int step_count = 0;
    int user_score = 0;
    bool is_end_game = false;
    PrintSceneDelimiter();
    PrintSimpleText(" 2048 (console version)!\n\n");
    InitField(field_user, core_matrix);
    ClearField(field_user);
    AddRandomCell(field_user);
    AddRandomCell(field_user);

    do
    {
        move_check.is_up = CheckUp(field_user);
        move_check.is_down = CheckDown(field_user);
        move_check.is_left = CheckLeft(field_user);
        move_check.is_right = CheckRight(field_user);
        is_end_game = CheckEndGame(move_check, field_user);

        if (true == is_end_game)
        {
            PrintSceneDelimiter();
            PrintCustomText(" Steps: %d\n", step_count);
            PrintCustomText(" Score: %d\n\n", user_score);
            PrintField(field_user);
            PrintSimpleText(" Game over!\n");
            PrintSceneDelimiter();
            ExitDelay();

            return 0;
        }

        PrintSceneDelimiter();
        PrintCustomText(" Steps: %d\n", step_count);
        PrintCustomText(" Score: %d\n\n", user_score);
        PrintField(field_user);
        PrintSimpleText(" w - Move <up>\n");
        PrintSimpleText(" s - Move <down>\n");
        PrintSimpleText(" a - Move <left>\n");
        PrintSimpleText(" d - Move <right>\n");
        PrintSimpleText(" 1 - Reset\n");
        PrintSimpleText(" 0 - Exit\n\n");
        PrintSimpleText(" => ");
        user_action = InputValue();

        if (user_action == UA_MOVE_UP)
        {
            if (true == move_check.is_up)
            {
                step_count += 1;
                user_score += MoveUp(field_user);
                AddRandomCell(field_user);
            }
        }
        else if (user_action == UA_MOVE_DOWN)
        {
            if (true == move_check.is_down)
            {
                step_count += 1;
                user_score += MoveDown(field_user);
                AddRandomCell(field_user);
            }
        }
        else if (user_action == UA_MOVE_LEFT)
        {
            if (true == move_check.is_left)
            {
                step_count += 1;
                user_score += MoveLeft(field_user);
                AddRandomCell(field_user);
            }
        }
        else if (user_action == UA_MOVE_RIGHT)
        {
            if (true == move_check.is_right)
            {
                step_count += 1;
                user_score += MoveRight(field_user);
                AddRandomCell(field_user);
            }
        }
        else if (user_action == UA_RESET)
        {
            step_count = 0;
            user_score = 0;
            ClearField(field_user);
            AddRandomCell(field_user);
            AddRandomCell(field_user);
        }
    }
    while (user_action != UA_EXIT);

    PrintSceneDelimiter();
    PrintCustomText(" Steps: %d\n", step_count);
    PrintCustomText(" Score: %d\n\n", user_score);
    PrintField(field_user);
    PrintSimpleText(" Game over!\n");
    PrintSceneDelimiter();
    ExitDelay();

    return 0;
}
