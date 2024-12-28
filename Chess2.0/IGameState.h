#pragma once

class Game;

class IGameState
{
public:

	virtual ~IGameState() = default;
	virtual void HandleInput(Game& game, int x, int y) = 0;
	virtual void Update(Game& game) = 0;
	virtual void Render(Game& game) = 0;
};