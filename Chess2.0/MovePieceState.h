#pragma once
#include "IGameState.h"
#include <vector>

class MovePieceState : public IGameState
{
public:
    MovePieceState(int selectedX, int selectedY);

    void HandleInput(Game& game, int x, int y) override;
    void Update(Game& game) override;
    void Render(Game& game) override;

private:
    int m_selectedX;
    int m_selectedY;
    std::vector<std::pair<int, int>> m_validMoves;
};
