#pragma once
#include "IMoveStrategy.h"

class KingMoveStrategy : public IMoveStrategy
{
public:
	KingMoveStrategy();
	std::vector<std::pair<int, int>> GetValidMoves(int x, int y, const std::vector<int>& board) override;

private:
	std::vector<std::pair<int, int>> m_move_pattern;
};
