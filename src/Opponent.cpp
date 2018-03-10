#include "Opponent.h"

Opponent::Opponent()
{
    //constructor
}

vector2 Opponent::generateMove()
{
    vector2 computerMove;
    // Check if Opponent can win
    for (unsigned int i = 0; i < m_computerTokens.size(); i++)
    {
        vector2 pos = m_computerTokens[i];
        if (checkRow(computerMove, pos))
        {
            return computerMove;
        }
        else if (checkCol(computerMove, pos))
        {
            return computerMove;
        }
        else if (checkDiag(computerMove, pos))
        {
            return computerMove;
        }
    }

    // Check if Player is about to win
    for (unsigned int i = 0; i < m_playerTokens.size(); i++)
    {
        vector2 pos = m_playerTokens[i];
        if (checkRow(computerMove, pos))
        {
            return computerMove;
        }
        else if (checkCol(computerMove, pos))
        {
            return computerMove;
        }
        else if (checkDiag(computerMove, pos))
        {
            continue;
        }
    }

    // Check if a corner is available
    //  TODO Fix this garbage move into a grabCorner function and optimize.
    if (m_board[0][0] == '1')
    {
        computerMove = (vector2){0, 0};
    }
    else if (m_board[0][2] == '3')
    {
        computerMove = (vector2){0, 2};
    }
    else if (m_board[2][0] == '7')
    {
        computerMove = (vector2){2, 0};
    }
    else if (m_board[2][2] == '9')
    {
        computerMove = (vector2){2, 2};
    }
    return computerMove;


    // grab any available tile
}


Opponent::~Opponent()
{
    // destructor
}

//Private
bool Opponent::checkRow(vector2& compMove, vector2 pos)
{
    int computer = 0;
    int player = 0;
    bool isOpen = false;

    for (int i = 0; i < m_COLUMNS; i++)
    {
        if (m_board[pos.x][i] == m_COMPUTER) { computer += 1; }
        else if (m_board[pos.x][i] == m_PLAYER) { player += 1; }
        else
        {
            compMove = (vector2) {pos.x, i};
            isOpen = true;
        }
    }

    if ((computer == m_COLUMNS - 1 || player == m_COLUMNS - 1) && isOpen)
    {
        return true;
    }
    else { return false; }

}

bool Opponent::checkCol(vector2& compMove, vector2 pos)
{
    int computer = 0;
    int player = 0;
    bool isOpen = false;

    for (int i = 0; i < m_ROWS; i++)
    {
        if (m_board[i][pos.y] == m_COMPUTER) { computer += 1; }
        else if (m_board[i][pos.y] == m_PLAYER) { player += 1; }
        else
        {
            compMove = (vector2){i, pos.y};
            isOpen = true;
        }
    }

    if ((computer == m_ROWS - 1 || player == m_ROWS - 1) && isOpen)
    {
        return true;
    }
    else { return false; }

}

// TODO Make this dynamic meaning this would be able to scale if the board was
// a 4 x 4 or 5 x 5 board instead of 3 x 3
bool Opponent::checkDiag(vector2& compMove, vector2 pos)
{
    int computer = 0;
    int player = 0;
    bool isOpen = false;

    for (int i = 0; i < 3; i++)
    {
        if (m_COMPUTER == m_board[i][i]) { computer += 1; }
        else if (m_PLAYER == m_board[i][i]) { player += 1; }
        else
        {
            compMove = (vector2){i, i};
            isOpen = true;
        }
    }

    if ((computer == 2 || player == 2) && isOpen) { return true; }
    else
    {
        computer = 0;
        player = 0;
        isOpen = false;
    }
    for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--)
    {
        if (m_COMPUTER == m_board[i][j]) { computer += 1; }
        else if (m_PLAYER == m_board[i][j]) { player += 1; }
        else
        {
            compMove = (vector2){i, j};
            isOpen = true;
        }
    }
    if ((computer == 2 || player == 2) && isOpen) { return true; }
    else { return false; }
}
