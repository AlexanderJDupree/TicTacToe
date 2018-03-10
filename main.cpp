#include <iostream>
#include "GameBoard.h"
#include "Opponent.h"

using namespace std;

void intro();
void drawBoard(const GameBoard &gameBoard);
void displayBadInput(); // TODO parameterize, make dynamic
void resetInputStream();
void getInput(string prompt, int &choice);
vector2 vectorConversion(GameBoard &gameBoard, int choice);

int main()
{

    int choice = 0;
    vector2 position;

    intro();
    GameBoard gameBoard;
    Opponent opponent;

    do {
        gameBoard.nextTurn();
        // TODO If play enters a bad input, the turn is still swapped.
        if (gameBoard.isPlayersTurn())
        {
            drawBoard(gameBoard);
            // gameBoard is passed by reference
            getInput("Enter your tile choice:  ", choice);
            // choice is passed by reference
            position = vectorConversion(gameBoard, choice);
            if (gameBoard.isTileValid(position))
            {
                gameBoard.placeToken(position);
                gameBoard.incrementTurn();
            }
            else { displayBadInput(); }
        }
        else
        {
            position = opponent.generateMove();
            if (gameBoard.isTileValid(position))
            {
                gameBoard.placeToken(position);
                gameBoard.incrementTurn();
            }
            else
            {
                cout << "COMPUTER INVALID MOVE" << endl;
                cout << position.x << " " << position.y;
            }
        }
    } while (!gameBoard.isGameWon() && !gameBoard.isGameComplete());

    // TODO Game Summary
    drawBoard(gameBoard);

    return 0;
}

// TODO make the intro interesting and engaging.
void intro()
{
    cout << "\t\tTIC TAC TOE\n" << endl;
    cout << "This is my Tic Tac Toe WIP. To feature a real AI Opponent.";
    cout << endl;
    return;
}


void drawBoard(const GameBoard &gameBoard)
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "-------------\n" << "|";
        for (int j = 0; j < 3; j++)
        {
            cout << ' ' << gameBoard.m_board[i][j] << " |";
        }
        cout << endl;
    }
    cout << "-------------" << endl;
    return;
}

void displayBadInput()
{
    cout << "\nInvalid selection. Try again." << endl;
    resetInputStream();
    return;
}

void resetInputStream()
{
    // get rid of failure state
    cin.clear();

    // discard 'bad' characters
    cin.ignore(100, '\n');
    return;
}

void getInput(string prompt, int &choice)
{
    cout << prompt;
    cin >> choice;
    return;
}

vector2 vectorConversion(GameBoard &gameBoard, int choice)
{
    vector2 position = {0, 0};
    int boardRows = gameBoard.getRows();

    position.x = (choice - 1) / boardRows;
    choice -= boardRows * position.x;
    position.y = choice - 1;

    return position;
}
