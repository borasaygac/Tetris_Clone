#define BOARD
#ifdef BOARD

#include "pieces.hpp"

#define BOARD_LINE_WIDTH 6 // Width of the lines that delimit the board
#define BlOCK_SIZE 16      // Width and height of each block piece
#define BOARD_POSITION 320 // Initial position of the board on the screen from the left
#define BOARD_WIDTH 10     // Board width in blocks
#define BOARD_HEIGHT 20    // Board height in blocks
#define MIN_VERTICAL_MARGIN 20 // Minimum vertical margin for the board limit
#define MIN_HORIZONTAL_MARGIN 20 // Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5 // Number of horizontal and vertical blocks of a matrix piece


class Board {
    public:

    Board(Pieces *pieces, int screenHeight);

    int getXPosInPixels(int pos);
    int getYPosInPixels(int pos);
    bool isFreeBlock(int x, int y);
    bool isPossibleMovement(int x, int y, int piece, int rotation);
    void storePiece(int x, int y, int piece, int rotation);
    void deletePossibleLines();
    bool isGameOver();

    private:

    enum { POS_FREE, POS_FILLED }; // POS_FREE = free position of the board; POS_FILLED = filled position of the board

    int board[BOARD_WIDTH][BOARD_HEIGHT]; // Board that contains the pieces
    Pieces *gPieces;
    int GScreenHeigth;

    void initBoard();
    void deleteLine(int pY);

};

#endif // BOARD


