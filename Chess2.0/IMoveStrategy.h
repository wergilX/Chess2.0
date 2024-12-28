#pragma once
#include <vector>
#include <utility>

class IMoveStrategy
{
public:
	virtual ~IMoveStrategy() = default;
	virtual std::vector<std::pair<int, int>> GetValidMoves(int x, int y, const std::vector<int>& board) = 0;
};
