#include "GameBoard.h"

char GameBoard::m_board[m_ROWS][m_COLUMNS] = {0};
std::vector<vector2> GameBoard::m_playerTokens;
std::vector<vector2> GameBoard::m_computerTokens ;

GameBoard::GameBoard()
{
    char boardNumber = '1';
    for (unsigned int i = 0; i < m_ROWS; i++)
    {
        for (unsigned int j = 0; j < m_COLUMNS; j++)
        {
            m_board[i][j] = boardNumber;
            boardNumber++;
        }
    }
    m_maxTurns = m_ROWS * m_COLUMNS;
    m_turn = 0;

    m_playersTurn = false;
    // TODO Make this random, so either or can go first.
}

GameBoard::~GameBoard()
{
    // destructor
}

bool GameBoard::isTileValid(vector2 pos)
{

    if (pos.x > m_ROWS - 1 || pos.x < 0 || pos.y > m_COLUMNS - 1 || pos.y < 0)
    {
        return false;
    }
    else
    {
        if (m_board[pos.x][pos.y] == m_PLAYER || m_board[pos.x][pos.y] == m_COMPUTER)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool GameBoard::isGameWon()
{
    if (m_playersTurn)
    {
        for (unsigned int i = 0; i < m_playerTokens.size(); i++)
        {
            vector2 pos = m_playerTokens[i];
            if(isRowComplete(pos) || isColComplete(pos) || isDiagComplete(pos))
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        for (unsigned int i = 0; i < m_computerTokens.size(); i++)
        {
            vector2 pos = m_computerTokens[i];
            if(isRowComplete(pos) || isColComplete(pos) || isDiagComplete(pos))
            {
                return true;
            }
        }
        return false;
    }
}

bool GameBoard::isGameComplete()
{
    return (m_turn >= m_maxTurns);
}

//GETTERS
int GameBoard::getColumns()
{
    return m_COLUMNS;
}

int GameBoard::getRows()
{
    return m_ROWS;
}

bool GameBoard::isPlayersTurn()
{
    return m_playersTurn;
}

//SETTERS
void GameBoard::placeToken(vector2 pos)
{
    if (m_playersTurn)
    {
        m_board[pos.x][pos.y] = m_PLAYER;
        m_playerTokens.push_back(pos);
    }

    else
    {
        m_board[pos.x][pos.y] = m_COMPUTER;
        m_computerTokens.push_back(pos);
    }

    return;
}

void GameBoard::nextTurn()
{
    m_playersTurn = !m_playersTurn;
    return;
}

void GameBoard::incrementTurn()
{
    m_turn++;
    return;
}

//PRIVATE
bool GameBoard::isRowComplete(vector2 pos)
{
    int occurences = 0;
    char token;

    if (m_playersTurn) { token = m_PLAYER; }
    else { token = m_COMPUTER; }

    for (int i = 0; i < m_COLUMNS; i++)
    {
        if (m_board[pos.x][i] == token) { occurences += 1; }
    }

    if (occurences == m_COLUMNS) { return true; }
    else { return false; }
}

bool GameBoard::isColComplete(vector2 pos)
{
    int occurences = 0;
    char token;

    if (m_playersTurn) { token = m_PLAYER; }
    else { token = m_COMPUTER; }

    for (int i = 0; i < m_ROWS; i++)
    {
        if (m_board[i][pos.y] == token) { occurences += 1; }
    }

    if (occurences == m_ROWS) { return true; }
    else { return false; }
}

// TODO make this function dynamic
bool GameBoard::isDiagComplete(vector2 pos)
{
    char token;

    if (m_playersTurn) { token = m_PLAYER; }
    else { token = m_COMPUTER; }

    if (m_board[1][1] == token && m_board[0][0] == token && m_board[2][2] == token)
    {
        return true;
    }
    else if (m_board[1][1] == token && m_board[2][0] == token && m_board[0][2] == token)
    {
        return true;
    }
    else { return false; }

}
