#include "Board.h"

#include "BishopMoveStrategy.h"
#include "RookMoveStrategy.h"
#include "KnightMoveStrategy.h"
#include "QueenMoveStrategy.h"
#include "KingMoveStrategy.h"
#include "PawnMoveStrategy.h"

#include <math.h>


const int BOARD_SIZE = 8;

Board::Board()
{
	m_moveStrategies.push_back(std::make_shared<RookMoveStrategy>()); // board id = 1
	m_moveStrategies.push_back(std::make_shared<KnightMoveStrategy>()); // board id = 2
	m_moveStrategies.push_back(std::make_shared<BishopMoveStrategy>()); // board id = 3
	m_moveStrategies.push_back(std::make_shared<QueenMoveStrategy>()); // board id = 4
	m_moveStrategies.push_back(std::make_shared<KingMoveStrategy>()); // board id = 5
	m_moveStrategies.push_back(std::make_shared<PawnMoveStrategy>()); // board id = 6
}

int Board::GetFigureIdFromPos(std::pair<int, int> pos) const {
	return m_board[pos.first + (pos.second * BOARD_SIZE)];
}

void Board::SetFigureIdToPos(int id, std::pair<int, int> pos) {
	m_board[pos.first + (pos.second * BOARD_SIZE)] = id;
}

void Board::ClearPos(std::pair<int, int> pos) {
	m_board[pos.first + (pos.second * BOARD_SIZE)] = 0;
}

const std::vector<int>& Board::GetAllBoard() {
	return m_board;
}

std::shared_ptr<IMoveStrategy> Board::GetPieceStrategy(int figureId)
{
	return m_moveStrategies[figureId - 1];
}
