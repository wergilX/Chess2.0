#pragma once
#include <SDL3/SDL.h>
#include <map>
#include <list>
#include <memory>
#include <vector>
#include <optional>

#include "IMoveStrategy.h"

class Board
{
public:

	Board();
	int GetFigureIdFromPos(std::pair<int, int> pos) const;
	void SetFigureIdToPos(int id, std::pair<int, int> pos);
	void ClearPos(std::pair<int, int> pos);
	const std::vector<int>& GetAllBoard();
	std::shared_ptr<IMoveStrategy> GetPieceStrategy(int figureId);

private:
	std::vector<std::shared_ptr<IMoveStrategy>> m_moveStrategies;

	std::vector<int> m_board =
	{ -1,-2,-3,-4,-5,-3,-2,-1,
	 -6,-6,-6,-6,-6,-6,-6,-6,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  1, 2, 3, 4, 5, 3, 2, 1 };
};