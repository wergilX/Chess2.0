#include "Game.h"
#include "WindowRenderer.h"
#include "SelectPieceState.h"
#include "PawnPromotionState.h"
#include <string>

const int SCREEN_SIZE = 640;
const int TILE_SIZE = SCREEN_SIZE / 8;

Game::Game()
{
	//m_gameState = std::make_unique<PawnPromotionState>();
	m_gameState = std::make_unique<SelectPieceState>();
	LoadTextures();
}

void Game::ChangeState(std::unique_ptr<IGameState> newState)
{
	m_gameState = std::move(newState);
}

void Game::HandleInput(int x, int y)
{
	if (m_gameState)
	{
		m_gameState->HandleInput(*this, x, y);
	}
}

void Game::Update()
{
	m_gameState->Update(*this);
}

void Game::Render()
{
	m_windowRenderer.Clear();
	//DrawBoard();
	m_gameState->Render(*this);
	m_windowRenderer.Present();
}

const WindowRenderer& Game::GetRenderer()
{
	return m_windowRenderer;
}

Board& Game::GetBoard()
{
	return m_board;
}

void Game::DrawBoard()
{
	for (size_t i = 0; i < m_board.GetAllBoard().size(); i++)
	{
		int pos_x = i % 8;// todo
		int pos_y = i / 8;
		std::string tileColor = (pos_x+pos_y) % 2 == 0 ? "dark_tile" : "light_tile";
		// Determine tile color

		SDL_FRect pos;
		pos.w = TILE_SIZE;
		pos.h = TILE_SIZE;
		pos.x = TILE_SIZE * pos_x;
		pos.y = TILE_SIZE * pos_y;

		m_windowRenderer.Render(pos, tileColor);
	}

	for (size_t i = 0; i < m_board.GetAllBoard().size(); i++)
	{
		int pos_x = i % 8;// todo
		int pos_y = i / 8;

		int figure_type = m_board.GetFigureIdFromPos({pos_x, pos_y});
		if (figure_type == 0)
			continue;

		SDL_FRect pos;
		pos.w = TILE_SIZE;
		pos.h = TILE_SIZE;
		pos.x = TILE_SIZE * pos_x;
		pos.y = TILE_SIZE * pos_y;
		m_windowRenderer.Render(pos, std::to_string(figure_type));
	}
}

void Game::LoadTextures()
{
	//m_windowRenderer.GetTextureManager().Load("board", "..\\resources\\images\\board.png");
	m_windowRenderer.GetTextureManager().Load("green_frame", "..\\resources\\images\\green_frame.png");
	m_windowRenderer.GetTextureManager().Load("red_frame", "..\\resources\\images\\red_frame.png");
	m_windowRenderer.GetTextureManager().Load("light_tile", "..\\resources\\images\\128h\\square brown light_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("dark_tile", "..\\resources\\images\\128h\\square brown dark_png_128px.png");

	m_windowRenderer.GetTextureManager().Load("-1", "..\\resources\\images\\128h\\b_rook_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("-2", "..\\resources\\images\\128h\\b_knight_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("-3", "..\\resources\\images\\128h\\b_bishop_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("-4", "..\\resources\\images\\128h\\b_queen_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("-5", "..\\resources\\images\\128h\\b_king_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("-6", "..\\resources\\images\\128h\\b_pawn_png_128px.png");

	m_windowRenderer.GetTextureManager().Load("1", "..\\resources\\images\\128h\\w_rook_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("2", "..\\resources\\images\\128h\\w_knight_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("3", "..\\resources\\images\\128h\\w_bishop_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("4", "..\\resources\\images\\128h\\w_queen_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("5", "..\\resources\\images\\128h\\w_king_png_128px.png");
	m_windowRenderer.GetTextureManager().Load("6", "..\\resources\\images\\128h\\w_pawn_png_128px.png");
}


