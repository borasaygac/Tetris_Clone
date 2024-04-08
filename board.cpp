#include "board.hpp"


// Init

Board::Board (Pieces *pieces, int screenHeight) {
    gPieces = pieces;
    GScreenHeigth = screenHeight;
    initBoard();
};


// Init the board 

void Board::initBoard(){
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            board[i][j] = POS_FREE;
        }
    }
}

void Board::storePiece(int x, int y, int piece, int rotation) {
    for (int i1 = x, i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = y, j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++) {
            if (gPieces->getBlockType(piece, rotation, j2, i2) != 0) {
                board[i1][j1] = POS_FILLED;
            }
        }
    }
}

bool Board::isGameOver() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (board[i][0] == POS_FILLED) {
            return true;
        }
        return false;
    }
}


// Deletes a line by moving all lines above one down 
void Board::deleteLine(int pY) {
    for (int j = pY; j > 0; j--) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            board[i][j] = board[i][j-1];
        }
    }
}

// Find the lines to delete and use the deleteLine function to delete them, if any
void Board::deletePossibleLines() {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
        int i = 0;
        while(i < BOARD_WIDTH){
            if (board[i][j] != POS_FILLED) break;
            i++;
        }

        if (i == BOARD_WIDTH) deleteLine(j);
    }
}

// Check if the coordinate is free
bool Board::isFreeBlock(int x, int y) {
    return board[x][y] == POS_FREE;
}

// Get positions in pixels for y and x coordinates.
int Board::getXPosInPixels(int pos) {
    return ((BOARD_POSITION - (BlOCK_SIZE * (BOARD_WIDTH / 2)) + (pos * BlOCK_SIZE)));
}

int Board::getYPosInPixels(int pos) {
    return ((GScreenHeigth - (BlOCK_SIZE * BOARD_HEIGHT)) + (pos * BlOCK_SIZE));
}

// Check whether a move is possible
bool Board::isPossibleMovement(int x, int y, int piece, int rotation) {
    // Checking for collision with already stored pieces and the limits

    for (int i1 = x, int i2 = 0; i1 < x + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = y, int j2 = 0; j1 < y + PIECE_BLOCKS; j1++, j2++) {
            if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1) {
                if (gPieces->getBlockType(piece, rotation,i2, j2)) return 0;  
            }

            if (j1 >= 1) {
                if ((gPieces->getBlockType(piece, rotation, x, y) != 0) && !isFreeBlock(i1,j1)) return false;
            }
        }
    }

    // No collision
    return true;
}
