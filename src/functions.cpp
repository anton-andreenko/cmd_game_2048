// functions.cpp

#include "functions.hpp"

void Functions::ClearStdInBuffer()
{
    char value = 0;

    do
    {
        value = std::getchar();
    }
    while ((value != '\n') && (value != EOF));
}

user_action_t Functions::InputValue()
{
    char value = 0;
    std::scanf("%c", &value);
    ClearStdInBuffer();

    return static_cast<user_action_t>(value);
}

void Functions::InitField(field_t & arg_1, cell_t * arg_2)
{
    arg_1 = arg_2;
}

void Functions::ClearField(field_t field_1)
{
    // field_1 -- field_user

    for (int i = 0; (i < SIZE_XY); i++)
    {
        field_1[i] = CELL_0;
    }
}

void Functions::AddRandomCell(field_t field_1)
{
    // field_1 -- field_user

    std::vector<int> v_indexes;
    int random_index = 0;

    for (int i = 0; (i < SIZE_XY); i++)
    {
        if (field_1[i] == CELL_0)
        {
            v_indexes.push_back(i);
        }
    }

    if (v_indexes.size() > 0)
    {
        random_index = std::rand() % v_indexes.size();

        if ((std::rand() % 100) >= 10)
        {
            field_1[v_indexes[random_index]] = CELL_2;
        }
        else
        {
            field_1[v_indexes[random_index]] = CELL_4;
        }
    }
}

void Functions::RotationField(field_t field_1, int rotation_count)
{
    // field_1 -- field_user

    cell_t tmp_matrix[SIZE_XY] = {};

    for (int n = 0; (n < rotation_count); n++)
    {
        for (int y = 0, inv_y = (SIZE_Y - 1); (y < SIZE_Y); y++, inv_y--)
        {
            for (int x = 0; (x < SIZE_X); x++)
            {
                tmp_matrix[x * SIZE_Y + inv_y] = field_1[y * SIZE_X + x];
            }
        }

        for (int i = 0; (i < SIZE_XY); i++)
        {
            field_1[i] = tmp_matrix[i];
        }
    }
}

bool Functions::CheckUp(const field_t field_1)
{
    // field_1 -- field_user

    bool result = false;
    RotationField(field_1, 3);
    result = CheckLeft(field_1);
    RotationField(field_1, 1);

    return result;
}

bool Functions::CheckDown(const field_t field_1)
{
    // field_1 -- field_user

    bool result = false;
    RotationField(field_1, 1);
    result = CheckLeft(field_1);
    RotationField(field_1, 3);

    return result;
}

bool Functions::CheckLeft(const field_t field_1)
{
    // field_1 -- field_user

    cell_t tmp_cell = CELL_0;
    int tmp_x = 0;

    // check sum

    for (int y = 0; (y < SIZE_Y); y++)
    {
        for (int x = 0; (x < (SIZE_X - 1)); x++)
        {
            if (field_1[y * SIZE_X + x] > CELL_0)
            {
                tmp_cell = field_1[y * SIZE_X + x];
                tmp_x = x + 1;

                while (tmp_x < SIZE_X)
                {
                    if (field_1[y * SIZE_X + tmp_x] == tmp_cell)
                    {
                        return true;
                    }
                    else if (field_1[y * SIZE_X + tmp_x] == CELL_0)
                    {
                        tmp_x += 1;
                    }
                    else
                    {
                        x = tmp_x - 1;
                        tmp_x = SIZE_X;
                    }
                }
            }
        }
    }

    // check shift

    for (int y = 0; (y < SIZE_Y); y++)
    {
        for (int x = 0; (x < (SIZE_X - 1)); x++)
        {
            if (field_1[y * SIZE_X + x] == CELL_0)
            {
                tmp_x = x + 1;

                while (tmp_x < SIZE_X)
                {
                    if (field_1[y * SIZE_X + tmp_x] > CELL_0)
                    {
                        return true;
                    }
                    else
                    {
                        tmp_x += 1;
                    }
                }
            }
        }
    }

    return false;
}

bool Functions::CheckRight(const field_t field_1)
{
    // field_1 -- field_user

    bool result = false;
    RotationField(field_1, 2);
    result = CheckLeft(field_1);
    RotationField(field_1, 2);

    return result;
}

int Functions::MoveUp(field_t field_1)
{
    // field_1 -- field_user

    int sum = 0;
    RotationField(field_1, 3);
    sum = SumLeft(field_1);
    ShiftLeft(field_1);
    RotationField(field_1, 1);

    return sum;
}

int Functions::MoveDown(field_t field_1)
{
    // field_1 -- field_user

    int sum = 0;
    RotationField(field_1, 1);
    sum = SumLeft(field_1);
    ShiftLeft(field_1);
    RotationField(field_1, 3);

    return sum;
}

int Functions::MoveLeft(field_t field_1)
{
    // field_1 -- field_user

    int sum = 0;
    sum = SumLeft(field_1);
    ShiftLeft(field_1);

    return sum;
}

int Functions::MoveRight(field_t field_1)
{
    // field_1 -- field_user

    int sum = 0;
    RotationField(field_1, 2);
    sum = SumLeft(field_1);
    ShiftLeft(field_1);
    RotationField(field_1, 2);

    return sum;
}

int Functions::SumLeft(field_t field_1)
{
    // field_1 -- field_user

    int result = 0;
    cell_t tmp_cell = CELL_0;
    int tmp_x = 0;

    for (int y = 0; (y < SIZE_Y); y++)
    {
        for (int x = 0; (x < (SIZE_X - 1)); x++)
        {
            if (field_1[y * SIZE_X + x] > CELL_0)
            {
                tmp_cell = field_1[y * SIZE_X + x];
                tmp_x = x + 1;

                while (tmp_x < SIZE_X)
                {
                    if (field_1[y * SIZE_X + tmp_x] == tmp_cell)
                    {
                        field_1[y * SIZE_X + x] += tmp_cell;
                        field_1[y * SIZE_X + tmp_x] = CELL_0;
                        x = tmp_x;
                        tmp_x = SIZE_X;
                        result += static_cast<int>(tmp_cell) * 2;
                    }
                    else if (field_1[y * SIZE_X + tmp_x] == CELL_0)
                    {
                        tmp_x += 1;
                    }
                    else
                    {
                        x = tmp_x - 1;
                        tmp_x = SIZE_X;
                    }
                }
            }
        }
    }

    return result;
}

void Functions::ShiftLeft(field_t field_1)
{
    // field_1 -- field_user

    int tmp_x = 0;

    for (int y = 0; (y < SIZE_Y); y++)
    {
        for (int x = 0; (x < (SIZE_X - 1)); x++)
        {
            if (field_1[y * SIZE_X + x] == CELL_0)
            {
                tmp_x = x + 1;

                while (tmp_x < SIZE_X)
                {
                    if (field_1[y * SIZE_X + tmp_x] > CELL_0)
                    {
                        field_1[y * SIZE_X + x] = field_1[y * SIZE_X + tmp_x];
                        field_1[y * SIZE_X + tmp_x] = CELL_0;
                        tmp_x = SIZE_X;
                    }
                    else
                    {
                        tmp_x += 1;
                    }
                }
            }
        }
    }
}

void Functions::PrintSceneDelimiter()
{
    std::printf("====================================================================\n");
}

void Functions::PrintSimpleText(text_t text)
{
    std::printf(text);
}

void Functions::PrintCustomText(text_t text, int arg)
{
    std::printf(text, arg);
}

void Functions::PrintField(const field_t field_1)
{
    // field_1 -- field_user

    char c_buffer[256] = {};
    std::string s_buffer;

    // lines: 1 to N-1

    for (int y = 0; (y < SIZE_Y); y++)
    {
        s_buffer.append(" +------+------+------+------+\n |");

        for (int x = 0; (x < SIZE_X); x++)
        {
            if (field_1[y * SIZE_X + x] > CELL_0)
            {
                std::sprintf(c_buffer, " %4d |", field_1[y * SIZE_X + x]);
                s_buffer.append(c_buffer);
            }
            else
            {
                std::sprintf(c_buffer, " %4c |", ' ');
                s_buffer.append(c_buffer);
            }
        }

        s_buffer.append("\n");
    }

    // line: N

    s_buffer.append(" +------+------+------+------+\n");

    // end of lines

    std::printf("%s\n", s_buffer.c_str());
}

bool Functions::CheckEndGame(const move_check_t & r_move_check, const field_t field_1)
{
    // field_1 -- field_user

    bool result = false;
    result = !(r_move_check.is_up || r_move_check.is_down || r_move_check.is_left || r_move_check.is_right);

    for (int i = 0; ((false == result) && (i < SIZE_XY)); i++)
    {
        if (field_1[i] >= CELL_2048)
        {
            result = true;
        }
    }

    return result;
}

void Functions::ExitDelay()
{
    std::printf("Press \"Enter\" to exit...");
    std::getchar();
}
