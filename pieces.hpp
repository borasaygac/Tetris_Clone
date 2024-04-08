#ifndef PIECES_HPP
#define PIECES_HPP

//----------------------------------------------------------------------//
// Pieces 
//----------------------------------------------------------------------//

class Pieces
{
public:
    int getBlockType(int piece, int rotation, int x, int y) { return pieceDB[piece][rotation][x][y]; } ;
    int getXInitialPosition(int piece, int rotation) { return pieceInitPos[piece][rotation][0]; };
    int getYInitialPosition(int piece, int rotation) { return pieceInitPos[piece][rotation][1]; };
};

#endif // PIECES_HPP