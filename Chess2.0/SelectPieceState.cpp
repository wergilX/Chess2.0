#include "SelectPieceState.h"
#include "MovePieceState.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <math.h>

const int SCREEN_SIZE = 640;
const int TILE_SIZE = SCREEN_SIZE / 8;

void SelectPieceState::HandleInput(Game& game, int x, int y)
{
	// todo
	if (x > 0 && x < SCREEN_SIZE && y > 0 && y < SCREEN_SIZE)// maybe dont need
	{
		int pos_x = x / TILE_SIZE;
		int pos_y = y / TILE_SIZE;

		//std::cout << pos_x << "  " << pos_y << std::endl;
		m_figurePosX = pos_x;
		m_figurePosY = pos_y;
	}
}

void SelectPieceState::Update(Game& game)
{
	if (m_figurePosX < 0)//todo
		return;

	int figureId = game.GetBoard().GetFigureIdFromPos({ m_figurePosX, m_figurePosY });
	if (figureId == 0)
	{
		return;
	}
	else if(game.GetCurrentPlayer().side == PlayerSide::WHITE && figureId > 0 ||
		game.GetCurrentPlayer().side == PlayerSide::BLACK && figureId < 0)
	{
		std::cout << "MovePieceState pos{x: " << m_figurePosX << " y: " << m_figurePosY << "}\n";
		game.ChangePlayer();
		game.ChangeState(std::make_unique<MovePieceState>(m_figurePosX, m_figurePosY));
	}
}

void SelectPieceState::Render(Game& game)
{
	for (size_t i = 0; i < game.GetBoard().GetAllBoard().size(); i++)
	{
		int pos_x = i % 8;// todo
		int pos_y = i / 8;
		std::string tileColor = (pos_x + pos_y) % 2 == 0 ? "dark_tile" : "light_tile";
		// Determine tile color

		SDL_FRect pos;
		pos.w = TILE_SIZE;
		pos.h = TILE_SIZE;
		pos.x = TILE_SIZE * pos_x;
		pos.y = TILE_SIZE * pos_y;

		game.GetRenderer().Render(pos, tileColor);
	}

	for (size_t i = 0; i < game.GetBoard().GetAllBoard().size(); i++)
	{
		int pos_x = i % 8;// todo
		int pos_y = i / 8;

		int figure_type = game.GetBoard().GetFigureIdFromPos({ pos_x, pos_y });
		if (figure_type == 0)
			continue;

		SDL_FRect pos;
		pos.w = TILE_SIZE;
		pos.h = TILE_SIZE;
		pos.x = TILE_SIZE * pos_x;
		pos.y = TILE_SIZE * pos_y;
		game.GetRenderer().Render(pos, std::to_string(figure_type));
	}
}
