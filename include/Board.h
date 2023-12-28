#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include "SFML/Graphics.hpp"
#include "Block.h"

enum class Player
{
	PlayerX,
	PlayerO
};

class Board {

private:
	std::vector<Block> blocks;
	sf::Texture textureEmpty;
	sf::Texture textureCircle;
	sf::Texture textureX;
	Player player;

	static constexpr int countOfBlocks = 9;
	static constexpr int maxRangeOfBlocks = 3;
	static constexpr int blockShift = 150;
	static constexpr int posX = 0;
	static constexpr int posY = 0;

public:
	Board();
	void DrawBlocksOnScreen(const std::unique_ptr<sf::RenderWindow>& window);
	void CheckClick(const sf::Vector2f& clickPosition);

};