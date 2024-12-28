#pragma once
#include "IMoveStrategy.h"

class KnightMoveStrategy : public IMoveStrategy
{
public:
	KnightMoveStrategy();
	std::vector<std::pair<int, int>> GetValidMoves(int x, int y, const std::vector<int>& board) override;

private:
	std::vector<std::pair<int, int>> m_move_pattern;
};
