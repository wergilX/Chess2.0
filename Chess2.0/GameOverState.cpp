#include "GameOverState.h"
#include "Game.h"
#include <memory>
#include <algorithm>
#include <iostream>
#include "SelectPieceState.h"

void GameOverState::HandleInput(Game& game, int x, int y)
{
}

void GameOverState::Update(Game& game)
{
	auto& board = game.GetBoard().GetAllBoard();
	if (std::find(board.begin(), board.end(), 5) == board.end())
	{
		std::cout << "Black winner !" << std::endl;
	}
	else if(std::find(board.begin(), board.end(), -5) == board.end())
	{
		std::cout << "White winner !" << std::endl;
	}
	else
	{
		std::cout << "SelectState \n";
		game.ChangeState(std::make_unique<SelectPieceState>());
	}
}

void GameOverState::Render(Game& game)
{

}
