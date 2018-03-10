#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>

struct vector2
{
    int x;
    int y;
};


class GameBoard
{
public:
    //Destructor
    GameBoard();

    bool isTileValid(vector2 pos);
    bool isGameWon();
    bool isGameComplete();

    // GETTERS
    int getColumns();
    int getRows();
    bool isPlayersTurn();

    // SETTERS
    void placeToken(vector2 pos);
    void nextTurn();
    void incrementTurn();

    // destructor
    virtual ~GameBoard();

protected:

    static const int m_ROWS = 3;
    static const int m_COLUMNS = 3;
    static const char m_PLAYER = 'X';
    static const char m_COMPUTER = 'O';

    static std::vector<vector2> m_playerTokens;
    static std::vector<vector2> m_computerTokens;

private:

    int m_maxTurns;
    int m_turn;
    bool m_playersTurn;

    // TODO Fix prefix for member functions
    bool isRowComplete(vector2 pos);
    bool isColComplete(vector2 pos);
    bool isDiagComplete(vector2 pos);

public:
    // TODO figure out how to return a 2d array
    static char m_board[m_ROWS][m_COLUMNS];
};

#endif // GAMEBOARD_H
