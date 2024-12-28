#include "QueenMoveStrategy.h"

std::vector<std::pair<int, int>> QueenMoveStrategy::GetValidMoves(int x, int y, const std::vector<int>& board)
{
	std::vector<std::pair<int, int>> valid_moves;
	
	valid_moves = m_rookStrategy.GetValidMoves(x, y, board);
	
	auto part_moves = m_bishopStrategy.GetValidMoves(x, y, board);
	valid_moves.insert(valid_moves.end(), part_moves.begin(), part_moves.end());

	return valid_moves;
}
