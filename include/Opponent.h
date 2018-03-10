#ifndef OPPONENT_H
#define OPPONENT_H

#include "GameBoard.h"


class Opponent : public GameBoard

{
public:
    // Constructor
    Opponent();

    vector2 generateMove();

    // Destructor
    virtual ~Opponent();

protected:

private:
    // These functions have major side effects in that they not only check if the
    // row, col, or diag is complete but modify the computers move based on its
    // findings.
    bool checkRow(vector2& compMove, vector2 pos);
    bool checkCol(vector2& compMove, vector2 pos);
    bool checkDiag(vector2& compMove, vector2 pos);

};

#endif // OPPONENT_H
