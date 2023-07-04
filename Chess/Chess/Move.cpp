#include "Move.h"


Move::Move(MoveType mType, int fRow, int fCol, int tRow, int tCol, std::shared_ptr<Piece> moved, std::shared_ptr<Piece> captured)
{
	type = mType;
	fromRow = fRow;
	fromCol = fCol;
	toRow = tRow;
	toCol = tCol;
	movePiece = moved;
	capturedPiece = captured;
}

Move::Move(const Move& move) = default;

std::pair<int, int> Move::getOriginPosition()
{
	return std::make_pair(fromRow, fromCol);
}

std::pair<int, int> Move::getDestinationPosition()
{
	return std::make_pair(toRow, toCol);
}

std::shared_ptr<Piece> Move::getMovedPiece()
{
	return movePiece;
}

std::shared_ptr<Piece> Move::getCapturedPiece()
{
	return capturedPiece;
}

MoveType Move::getType()
{
	return type;
}

bool Move::operator==(const Move& other)
{
	bool fromrow = (this->fromRow == other.fromRow);
	bool fromcol = (this->fromCol == other.fromCol);
	bool movepiecetype = (this->movePiece->getType() == other.movePiece->getType());
	bool movepiececolour = (this->movePiece->getColor() == other.movePiece->getColor());
	bool torow = (this->toRow == other.toRow);
	bool tocol = (this->toCol == other.toCol);
	bool type = (this->type == other.type);
	//if(this->capturedPiece == nullptr)
	//bool capturedtype = (this->capturedPiece->getType() == other.capturedPiece->getType());
	//bool capturedcolour = (this->capturedPiece->getColor() == other.capturedPiece->getColor());
	return fromrow && fromcol && movepiecetype && movepiececolour && torow && tocol && type && (this->capturedPiece == other.capturedPiece);// capturedtype&& capturedcolour;
}

bool Move::operator!=(const Move& other)
{
	return !(operator==(other));
}