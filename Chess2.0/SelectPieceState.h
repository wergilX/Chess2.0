#pragma once
#include "IGameState.h"

class SelectPieceState : public IGameState
{
public:
	void HandleInput(Game& game, int x, int y) override;
	void Update(Game& game) override;
	void Render(Game& game) override;
private:

	int m_figurePosX = -1;
	int m_figurePosY = -1;
};

