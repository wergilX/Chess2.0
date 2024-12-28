#include "SelectPieceState.h"
#include "MovePieceState.h"
#include "Game.h"
#include <iostream>
#include <math.h>

const int SCREEN_SIZE = 640;
const int TILE_SIZE = SCREEN_SIZE / 8;

void SelectPieceState::HandleInput(Game& game, int x, int y)
{
	// todo
	if (x > 0 && x < SCREEN_SIZE && y > 0 && y < SCREEN_SIZE)
	{
		int pos_x = x / TILE_SIZE;
		int pos_y = y / TILE_SIZE;

		std::cout << pos_x << "  " << pos_y << std::endl;
		m_figurePosX = pos_x;
		m_figurePosY = pos_y;
	}
}

void SelectPieceState::Update(Game& game)
{
	if (m_figurePosX < 0)
		return;

	int figureId = game.GetBoard().GetFigureIdFromPos({ m_figurePosX, m_figurePosY });
	if (figureId == 0)
	{
		return;
	}
	std::cout << "MoveState \n";
	game.ChangeState(std::make_unique<MovePieceState>(m_figurePosX, m_figurePosY));
}

void SelectPieceState::Render(Game& game)
{
}
