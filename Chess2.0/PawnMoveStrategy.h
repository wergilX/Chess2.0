#pragma once
#include "IMoveStrategy.h"

class PawnMoveStrategy : public IMoveStrategy
{
public:
	std::vector<std::pair<int, int>> GetValidMoves(int x, int y, const std::vector<int>& board) override;
};