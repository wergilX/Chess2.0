#pragma once
#include <memory>
#include "IGameState.h"
#include "Board.h"
#include "WindowRenderer.h"

class Game
{
public:
	Game();
	void ChangeState(std::unique_ptr<IGameState> newState);
	void HandleInput(int x, int y);
	void Update();
	void Render();

	const WindowRenderer& GetRenderer();
	Board& GetBoard();

	void DrawBoard();

private:
	WindowRenderer m_windowRenderer;
	Board m_board;
	std::unique_ptr<IGameState> m_gameState;

	void LoadTextures();
};
