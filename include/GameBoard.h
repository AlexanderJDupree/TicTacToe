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
// Protected members are inherited and these members are static because I want
// the inherited opponent class to have access to the original values of the
// parent class

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
    // TODO figure out how to return a pointer to a 2d array
    static char m_board[m_ROWS][m_COLUMNS];
};

#endif // GAMEBOARD_H
