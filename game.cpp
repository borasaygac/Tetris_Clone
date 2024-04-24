#include "game.h"
#include <cstdlib>

void Game::initGame()
{
    // init rand numbers
    std::srand((unsigned int)time(NULL));

    // init piece
    mPiece = getRand(0, 6);
    mRotation = getRand(0, 3);
    mPosX = (BOARD_WIDTH / 2) + mPieces->getXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->getYInitialPosition(mPiece, mRotation);

    // next piece
    mNextPiece = getRand(0, 6);
    mNextRotation = getRand(0, 3);
    mNextPosX = BOARD_WIDTH + 5;
    mNextPosY = 5;
}

int Game::getRand(int pA, int pB)
{
    return std::rand() % (pB - pA + 1) + pA;
}

void Game::createNewPiece()
{
    // new piece
    mPiece = getRand(0, 6);
    mRotation = getRand(0, 3);
    mPosX = (BOARD_WIDTH / 2) + mPieces->getXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->getYInitialPosition(mPiece, mRotation);

    // next random piece
    mNextPiece = getRand(0, 6);
    mNextRotation = getRand(0, 3);
}

void Game::drawPiece(int pX, int pY, int piece, int rotation)
{
    color mColor;

    int mPixelsX = mBoard->getXPosInPixels(pX);
    int mPixelsY = mBoard->getYPosInPixels(pY);

    // draw the boxes that are filled
    for (int i = 0; i < PIECE_BLOCKS; i++)
    {
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {
            switch (mPieces->getBlockType(piece, rotation, i, j))
            {
            case 1:
                mColor = GREEN;
                break;
            case 2:
                mColor = BLUE;
                break;
            }

            if (mPieces->getBlockType(piece, rotation, i, j) != 0)
            {
                mIO->DrawRectangle(mPixelsX + i * BlOCK_SIZE,
                                   mPixelsY + j * BlOCK_SIZE,
                                   (mPixelsX + i * BlOCK_SIZE) + BlOCK_SIZE - 1,
                                   (mPixelsY + j * BlOCK_SIZE) + BlOCK_SIZE - 1,
                                   mColor);
            }
        }
    }
}

void Game::drawBoard()
{

    // Calculate the limits of the board in pixels
    int mX1 = BOARD_POSITION – (BlOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION + (BlOCK_SIZE * (BOARD_WIDTH / 2));
    int mY = mScreenHeight – (BlOCK_SIZE * BOARD_HEIGHT);

    // Check that the vertical margin is not to small
    // assert (mY > MIN_VERTICAL_MARGIN);

    // Rectangles that delimits the board
    mIO->DrawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);

    mIO->DrawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

    // Check that the horizontal margin is not to small
    // assert (mX1 > MIN_HORIZONTAL_MARGIN);

    // Drawing the blocks that are already stored in the board
    mX1 += 1;
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            // Check if the block is filled, if so, draw it
            if (!mBoard->isFreeBlock(i, j))
                mIO->DrawRectangle(mX1 + i * BlOCK_SIZE,
                                   mY + j * BlOCK_SIZE,
                                   (mX1 + i * BlOCK_SIZE) + BlOCK_SIZE - 1,
                                   (mY + j * BlOCK_SIZE) + BlOCK_SIZE - 1,
                                   RED);
        }
    }
}

void Game::drawScene ()
{
drawBoard (); // Draw the delimitation lines and blocks stored in the board
drawPiece (mPosX, mPosY, mPiece, mRotation); // Draw the playing piece
drawPiece (mNextPosX, mNextPosY, mNextPiece, mNextRotation); // Draw the next piece
}
