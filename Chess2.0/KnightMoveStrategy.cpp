#include "KnightMoveStrategy.h"

KnightMoveStrategy::KnightMoveStrategy()
{
	m_move_pattern = { {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };
}

std::vector<std::pair<int, int>> KnightMoveStrategy::GetValidMoves(int x, int y, const std::vector<int>& board)
{
	std::vector<std::pair<int, int>> global_pos;

	int figure_id = board[x + (y * 8)];

	for (const auto& move_coord : m_move_pattern)
	{
		int target_posX = x + move_coord.first;
		int target_posY = y + move_coord.second;

		// if target pos out of board
		if (target_posX > 7 || target_posY > 7 || target_posX < 0 || target_posY < 0)
			continue;

		int board_id = board[target_posX + (target_posY * 8)];
		// empty teil
		if (board_id == 0)
		{
			global_pos.push_back({ target_posX, target_posY });
		}
		//enemy check
		else if ((figure_id > 0 && board_id < 0) || (figure_id < 0 && board_id > 0))
		{
			global_pos.push_back({ target_posX, target_posY });
		}
	}

	return global_pos;
}
