#include "MovePieceState.h"
#include "GameOverState.h"
#include "Game.h"
#include <memory>
#include <algorithm>
#include <iostream>


const int SCREEN_SIZE = 640;
const int TILE_SIZE = SCREEN_SIZE / 8;

MovePieceState::MovePieceState(int selectedX, int selectedY)
	: m_selectedX(selectedX), m_selectedY(selectedY)
{
}

void MovePieceState::HandleInput(Game& game, int x, int y)
{
	if (m_validMoves.empty())//todo return to selectPieceState
		return;

	// todo
	if (x > 0 && x < SCREEN_SIZE && y > 0 && y < SCREEN_SIZE)
	{
		int targetX = x / TILE_SIZE;
		int targetY = y / TILE_SIZE;

		bool isValidMove = std::any_of(m_validMoves.begin(), m_validMoves.end(), [&](const auto& move) {
			return move.first == targetX && move.second == targetY;
			});

		if (isValidMove)
		{
			int currentFigure = game.GetBoard().GetFigureIdFromPos({ m_selectedX, m_selectedY });
			game.GetBoard().SetFigureIdToPos(currentFigure, { targetX, targetY });
			game.GetBoard().ClearPos({ m_selectedX, m_selectedY });
		}

		std::cout << "GameOverState \n";
		game.ChangeState(std::make_unique<GameOverState>());
	}
}

void MovePieceState::Update(Game& game)
{
	if (m_validMoves.empty())
	{
		int currentFigure = game.GetBoard().GetFigureIdFromPos({ m_selectedX, m_selectedY });
		auto strategy = game.GetBoard().GetPieceStrategy(std::abs(currentFigure));
		m_validMoves = strategy->GetValidMoves(m_selectedX, m_selectedY, game.GetBoard().GetAllBoard());
	}
}

void MovePieceState::Render(Game& game)
{
	// todo
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

	//==========================

	for (const auto& move : m_validMoves)
	{
		SDL_FRect spritePos{ TILE_SIZE * move.first, TILE_SIZE * move.second, TILE_SIZE, TILE_SIZE };
		game.GetRenderer().Render(spritePos, "red_frame");
	}
}
