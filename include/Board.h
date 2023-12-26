#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include "Block.h"

class Board {
private:
	std::vector<Block> blocks;
public:
	Board();
};