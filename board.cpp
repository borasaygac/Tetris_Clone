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

