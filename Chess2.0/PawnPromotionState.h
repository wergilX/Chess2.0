#pragma once
#include "IGameState.h"
#include <vector>

class PawnPromotionState : public IGameState
{
public:

    void HandleInput(Game& game, int x, int y) override;
    void Update(Game& game) override;
    void Render(Game& game) override;
private:
    bool m_isPawnPromotion = false;
    int m_pieceColor = 0;
    int m_figureId = -1;

    int m_targetPosX = 0;
    int m_targetPosY = 0;
};

