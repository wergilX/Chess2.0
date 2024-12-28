#include "KingMoveStrategy.h"

KingMoveStrategy::KingMoveStrategy()
{
    m_move_pattern = { {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1} };
}

std::vector<std::pair<int, int>> KingMoveStrategy::GetValidMoves(int x, int y, const std::vector<int>& board)
{
	std::vector<std::pair<int, int>> global_pos;
	int figure_id = board[x + (y * 8)];

	for (const auto& move_coord : m_move_pattern)
	{
		int pos = x + move_coord.first + ((y + move_coord.second) * 8);
		if (pos > 64 || pos < 0)
			continue;

		int board_id = board[pos];

		if (board_id == 0)
		{
			global_pos.push_back({ (x + move_coord.first), (y + move_coord.second) });
		}
		else if ((figure_id > 0 && board_id < 0) || (figure_id < 0 && board_id > 0)) //enemy check
		{
			global_pos.push_back({ (x + move_coord.first), (y + move_coord.second) });
		}
	}

	return global_pos;
}
