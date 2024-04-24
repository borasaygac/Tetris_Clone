#ifndef _GAME_
#define _GAME_

// Includes

#include "board.hpp"
#include "pieces.hpp"
#include "IO.h"
#include <time.h>

// Defines

#define WAIT_TIME 700 // Number of milliseconds that the piece remains before going 1 block down

// Game itself

class Game {
    public:

    Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

    void drawScene();
    void createNewPiece();

    int mPosX, mPosY; // Pos of the piece that is falling down
    int mPiece, mRotation; // What kind and what rotation of the next piece

    private:

    int mScreenHeight; // Screen height in pixels
    int mNextPosX, mNextPosY; // Pos of the next piece
    int mNextPiece, mNextRotation; // Kind and rotation of the next piece

    Board *mBoard;
    Pieces *mPieces;
    IO *mIO;

    int getRand (int pA, int pB);
    void initGame();
    void drawPiece(int pX, int pY, int piece, int rotation);
    void drawBoard();
};



#endif _GAME_

