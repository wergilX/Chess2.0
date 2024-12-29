#include "PawnPromotionState.h"
#include "Game.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include "SelectPieceState.h"

const int SCREEN_SIZE = 640;
const int TILE_SIZE = SCREEN_SIZE / 8;

int up = (SCREEN_SIZE / 2) - (TILE_SIZE / 2);// todo
int down = (SCREEN_SIZE / 2) - (TILE_SIZE / 2) + TILE_SIZE;
int left = TILE_SIZE * 2;
int right = TILE_SIZE * 2;


void PawnPromotionState::HandleInput(Game& game, int x, int y)
{
	if (y > up && y < down)
	{
		// calculate figure id
		int id = (x / TILE_SIZE) - 1;
		if (id > 0 && id < 5)
		{
			m_figureId = id;
			std::cout << "Selected figure: " << m_figureId << std::endl;
		}
	}
}

void PawnPromotionState::Update(Game& game)
{
	// + check pawns on positions 
	// + open window with correct pieces
	// + choose piece
	// setup in board

	// figure not selected
	if (!m_isPawnPromotion)
	{
		auto board = game.GetBoard().GetAllBoard();
		for (int i = 0; i < board.size(); ++i)
		{
			int figure_id = board[i];
			if (std::abs(figure_id) == 6)
			{
				int x = i % 8;
				int y = i / 8;

				if (y == 0 && figure_id > 0)
				{
					std::cout << "White pawn promotion" << std::endl;
					m_pieceColor = 1;
					m_isPawnPromotion = true;

					m_targetPosX = x;
					m_targetPosY = y;
				}
				else if (y == 7 && figure_id < 0)
				{
					std::cout << "Black pawn promotion" << std::endl;
					m_pieceColor = -1;
					m_isPawnPromotion = true;

					m_targetPosX = x;
					m_targetPosY = y;
				}
			}
		}
		if (!m_isPawnPromotion)
		{
			std::cout << "SelectPieceState \n";
			game.ChangeState(std::make_unique<SelectPieceState>());
		}
	}
	// figure selected
	else if (m_isPawnPromotion)
	{
		if (m_figureId != -1) // todo
		{
			game.GetBoard().SetFigureIdToPos(m_figureId * m_pieceColor, { m_targetPosX,m_targetPosY });

			std::cout << "SelectPieceState \n";
			game.ChangeState(std::make_unique<SelectPieceState>());
		}
	}
}

void PawnPromotionState::Render(Game& game)
{
	if (!m_isPawnPromotion)
		return;

	SDL_FRect pos;
	pos.w = SCREEN_SIZE;
	pos.h = SCREEN_SIZE;
	pos.x = 0;
	pos.y = 0;
	game.GetRenderer().Render(pos, "dark_tile");
	for (int i = 1; i < 5; ++i)
	{
		SDL_FRect pos;
		pos.w = TILE_SIZE;
		pos.h = TILE_SIZE;
		pos.x = (TILE_SIZE * i) + TILE_SIZE;
		pos.y = SCREEN_SIZE / 2 - TILE_SIZE / 2;

		game.GetRenderer().Render(pos, std::to_string(i * m_pieceColor));
	}
}
