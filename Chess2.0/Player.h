#pragma once
#include <string>

enum PlayerSide { WHITE, BLACK };
enum class PlayerType { HUMAN, AI };

struct Player
{
	PlayerType type;
	PlayerSide side;

	bool operator==(const Player& other) const {
		return (type == other.type && side == other.side);
	}
};