#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <string>
#include "SFML/Graphics.hpp"
#include "Block.h"
#include "Shared.h"

class Board {
private:
	std::vector<Block> blocks;
	sf::Texture textureEmpty;
	sf::Texture textureCircle;
	sf::Texture textureX;
	TypeOfPlayer player;
	bool isGameOver = false;
	sf::Font font;
	sf::Text text;

	static constexpr char* noBodyWon = "Nobody won, press M to refresh";
	static constexpr int countOfBlocks = 9;
	static constexpr int maxRangeOfBlocks = 3;
	static constexpr int blockShift = 150;
	static constexpr int posX = 0;
	static constexpr int posY = 0;

public:
	static constexpr char* winXInscription = "Win player X, press M to refresh";
	static constexpr char* winOInscription = "Win player O, press M to refresh";

	Board();
	void DrawBlocksOnScreen(const std::unique_ptr<sf::RenderWindow>& window);
	void CheckClick(const sf::Vector2f& clickPosition);
	const bool IsGameOver() const;
	void CheckWin(const TypeOfBlock& typeOfBlock,const std::string& finalInscription);
	void DrawText(const std::unique_ptr<sf::RenderWindow>& window);
	void CheckFinish();
};