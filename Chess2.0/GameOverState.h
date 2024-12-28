#pragma once
#include "IGameState.h"
class GameOverState :
	public IGameState
{
public:

	void HandleInput(Game& game, int x, int y) override;
	void Update(Game& game) override;
	void Render(Game& game) override;

private:

};

