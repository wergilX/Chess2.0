#include "BishopMoveStrategy.h"

std::vector<std::pair<int, int>> BishopMoveStrategy::GetValidMoves(int x, int y, const std::vector<int>& board)
{
	std::vector<std::pair<int, int>> valid_moves;

	auto part_of_valid_moves = ChekDirection(x, y, 1, 1, board);
	valid_moves = part_of_valid_moves;

	part_of_valid_moves = ChekDirection(x, y, -1, -1, board);
	valid_moves.insert(valid_moves.end(), part_of_valid_moves.begin(), part_of_valid_moves.end());

	part_of_valid_moves = ChekDirection(x, y, 1, -1, board);
	valid_moves.insert(valid_moves.end(), part_of_valid_moves.begin(), part_of_valid_moves.end());

	part_of_valid_moves = ChekDirection(x, y, -1, 1, board);
	valid_moves.insert(valid_moves.end(), part_of_valid_moves.begin(), part_of_valid_moves.end());

	return valid_moves;
}

std::vector<std::pair<int, int>> BishopMoveStrategy::ChekDirection(int x, int y, int dirX, int dirY, const std::vector<int>& board)
{
	std::vector<std::pair<int, int>> valid_moves;

	int figure_id = board[x + (y * 8)];

	int target_posX = x;
	int target_posY = y;

	for (int i = 0; i < 8; ++i)
	{
		target_posX += dirX;
		target_posY += dirY;

		// if target pos out of board
		if (target_posX > 7 || target_posY > 7 || target_posX < 0 || target_posY < 0)
			break;

		int board_id = board[target_posX + (target_posY * 8)];
		// empty teil
		if (board_id == 0)
		{
			valid_moves.push_back({ target_posX, target_posY });
			continue;
		}
		//enemy check
		else if ((figure_id > 0 && board_id < 0) || (figure_id < 0 && board_id > 0))
		{
			valid_moves.push_back({ target_posX, target_posY });
			break;
		}
		break;// frendly figure

	}
	return valid_moves;
}