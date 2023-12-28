#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include "SFML/Graphics.hpp"
#include "Block.h"
#include "TypeOfPlayer.h"
#include "TypeOfBlock.h"

class Board {
private:
	std::vector<Block> blocks;
	sf::Texture textureEmpty;
	sf::Texture textureCircle;
	sf::Texture textureX;
	TypeOfPlayer player;
	bool isGameOver = false;

	static constexpr int countOfBlocks = 9;
	static constexpr int maxRangeOfBlocks = 3;
	static constexpr int blockShift = 150;
	static constexpr int posX = 0;
	static constexpr int posY = 0;

public:
	Board();
	void DrawBlocksOnScreen(const std::unique_ptr<sf::RenderWindow>& window);
	void CheckClick(const sf::Vector2f& clickPosition);
	const bool IsGameOver() const;
};