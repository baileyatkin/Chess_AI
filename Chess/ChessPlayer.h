#pragma once
#include "Chess\PieceColor.h"
#include "Chess\PieceType.h"
#include <vector>
#include <memory>
#include "Chess/Move.h"

using namespace std;

class Piece;
class Board;
class GameStatus;
class Gameplay;
class Move;

struct PieceInPosition
{
	std::shared_ptr<Piece> piece;
	int col;
	int row;
};

typedef vector<PieceInPosition> vecPieces;

class ChessPlayer
{
public:
	static void		setupPlayers(ChessPlayer** playerWhite, ChessPlayer** playerBlack, Board* pBoard, GameStatus* pGameStatus, Gameplay* pGamePlay);
	ChessPlayer(Board* pBoard, GameStatus* pGameStatus, Gameplay* pGamePlay, PieceColor colour);

	void			setAI() { m_bAI = true; }
	bool			isAI() { return m_bAI; }
	unsigned int	getAllLivePieces(vecPieces& vpieces);
	vector<std::shared_ptr<Move>>	getValidMovesForPiece(PieceInPosition pip);
	Move			chooseAIMove();

protected:
	PieceColor		getColour() { return m_colour; }

private:
	PieceColor	m_colour;
	Board*		m_pBoard;
	GameStatus* m_pGameStatus;
	Gameplay*	m_pGamePlay;
	bool		m_bAI;
	const int m_depthLimit = 4;

	// holds previous moves. stops ai from repeating moves up to "m_maxPrevMoves" moves ago
	vector<Move> m_previousMoves;
	const int m_maxPrevMoves = 10;

	int MiniMax(Move m, Move* moves, int depth, int depthLimit, int alpha, int beta, bool maximisingPlayer);

	vector<shared_ptr<Piece>> getOpponentPieces();
};

