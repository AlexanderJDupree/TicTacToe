#include "Opponent.h"

Opponent::Opponent()
{
    //constructor
}

vector2 Opponent::generateMove()
{
    vector2 computerMove;
    // Check if Opponent can win
    // TODO Turn this for statements into separate functions.
    for (unsigned int i = 0; i < m_computerTokens.size(); i++)
    {
        vector2 pos = m_computerTokens[i];
        if (checkRow(computerMove, pos, m_COMPUTER, m_PLAYER))
        {
            return computerMove;
        }
        else if (checkCol(computerMove, pos, m_COMPUTER, m_PLAYER))
        {
            return computerMove;
        }
        else if (checkDiag(computerMove, pos, m_COMPUTER, m_PLAYER))
        {
            continue;
        }
    }

    // Check if Player is about to win
    for (unsigned int i = 0; i < m_playerTokens.size(); i++)
    {
        vector2 pos = m_playerTokens[i];
        if (checkRow(computerMove, pos, m_COMPUTER, m_PLAYER))
        {
            return computerMove;
        }
        else if (checkCol(computerMove, pos, m_COMPUTER, m_PLAYER))
        {
            return computerMove;
        }
        else if (checkDiag(computerMove, pos, m_COMPUTER, m_PLAYER))
        {
            continue;
        }
    }

    // Check if a corner is available
    //  TODO Fix this garbage
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
bool Opponent::checkRow(vector2& compMove, vector2 pos, char token, char antiToken)
{
    int computer = 0;
    int player = 0;
    bool isOpen = false;

    for (int i = 0; i < m_COLUMNS; i++)
    {
        if (m_board[pos.x][i] == token) { computer += 1; }
        else if (m_board[pos.x][i] == antiToken) { player += 1; }
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

bool Opponent::checkCol(vector2& compMove, vector2 pos, char token, char antiToken)
{
    int computer = 0;
    int player = 0;
    bool isOpen = false;

    for (int i = 0; i < m_ROWS; i++)
    {
        if (m_board[i][pos.y] == token) { computer += 1; }
        else if (m_board[i][pos.y] == antiToken) { player += 1; }
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

// TODO Make this dynamic
bool Opponent::checkDiag(vector2& compMove, vector2 pos, char token, char antiToken)
{
    int computer = 0;
    //int player = 0;
    //bool isOpen = false;
    char diagonolChars[3] = {m_board[0][0], m_board[2][2], m_board[1][1]};
    for (int i = 0; i < 3; i++)
    {
        if (token == diagonolChars[i]) { computer += 1; }
    }
    if (computer == 2) { return true; }
    else { return false; }
}
