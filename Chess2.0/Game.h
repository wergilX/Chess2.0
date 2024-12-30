#pragma once
#include <memory>
#include "IGameState.h"
#include "Board.h"
#include "WindowRenderer.h"
#include "Player.h"

class Game
{
public:
	Game();
	void ChangeState(std::unique_ptr<IGameState> newState);
	void HandleInput(int x, int y);
	void Update();
	void Render();
	void ChangePlayer();
	Player GetCurrentPlayer();


	const WindowRenderer& GetRenderer();
	Board& GetBoard();

	void DrawBoard();//todo

private:
	WindowRenderer m_windowRenderer;
	Board m_board;
	std::unique_ptr<IGameState> m_gameState;

	Player m_currentPlayer;

	Player m_player1;
	Player m_player2;


	void LoadTextures();
};
