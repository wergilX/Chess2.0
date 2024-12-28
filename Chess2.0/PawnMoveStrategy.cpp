#include "PawnMoveStrategy.h"

namespace {
	bool IsStartPos(const int pos_y, const int figure)
	{
		if (figure < 0 && pos_y == 1) {
			return true;
		}
		if (figure > 0 && pos_y == 6) {
			return true;
		}
		return false;
	}
}

std::vector<std::pair<int, int>> PawnMoveStrategy::GetValidMoves(int x, int y, const std::vector<int>& board)
{
	std::vector<std::pair<int, int>> global_pos;
	int figure_id = board[x + (y * 8)];


	int direction = figure_id < 0 ? 1 : -1;

	int board_id;
	int target_posX = x;
	int target_posY = y + direction;

	//check diagonal enemy
	if (int pos = (target_posX + direction) + (target_posY * 8); pos < 64 || pos >= 0)
	{
		board_id = board[pos];
		if ((figure_id > 0 && board_id < 0) || (figure_id < 0 && board_id > 0)) //enemy check
			global_pos.push_back({ target_posX + direction, target_posY });
	}

	if (int pos = (target_posX - direction) + (target_posY * 8); pos < 64 || pos >= 0)
	{
		board_id = board[pos];
		if ((figure_id > 0 && board_id < 0) || (figure_id < 0 && board_id > 0)) //enemy check
			global_pos.push_back({ target_posX - direction, target_posY });
	}

	//move
	board_id = board[x + (target_posY * 8)];// todo exeption
	if (board_id == 0) {
		global_pos.push_back({ x, target_posY });
	}
	else {
		return global_pos;
	}

	//if this is first move for this pawn add one more cell
	if (IsStartPos(y, figure_id))
	{
		board_id = board[x + ((target_posY + direction) * 8)];
		if (board_id == 0) {
			global_pos.push_back({ x, (y + (direction + direction)) });
		}
		else {
			return global_pos;
		}
	}

	return global_pos;
}