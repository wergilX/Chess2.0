#pragma once
#include "IMoveStrategy.h"
#include "BishopMoveStrategy.h"
#include "RookMoveStrategy.h"

class QueenMoveStrategy : public IMoveStrategy
{
public:
	std::vector<std::pair<int, int>> GetValidMoves(int x, int y, const std::vector<int>& board) override;
private:
	BishopMoveStrategy m_bishopStrategy;
	RookMoveStrategy m_rookStrategy;
};

