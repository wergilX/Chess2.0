#pragma once
#include "IMoveStrategy.h"

class BishopMoveStrategy : public IMoveStrategy 
{
public:
	std::vector<std::pair<int, int>> GetValidMoves(int x, int y, const std::vector<int>& board) override;

private:
	std::vector<std::pair<int, int>> ChekDirection(int x, int y, int dirX, int dirY, const std::vector<int>& board);
	std::vector<std::pair<int, int>> m_move_pattern;
};