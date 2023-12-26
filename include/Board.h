#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include "SFML/Graphics.hpp"
#include "Block.h"

class Board {
private:
	std::vector<Block> blocks;
	std::vector<sf::Texture> textures;


	static constexpr int countOfBlocks = 9;
	static constexpr int maxRangeOfBlocks = 3;
	static constexpr int posX = 0;
	static constexpr int posY = 0;

public:
	Board();
};