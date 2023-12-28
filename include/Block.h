#pragma once
#include "SFML/Graphics.hpp"

class Block
{
private:
	sf::Sprite sprite;
	int positionX = 0;
	int positionY = 0;
	bool blockClosed = false;

public:
	Block(int x, int y);
	void SetSprite(sf::Texture& texture);
	const sf::Sprite GetSprite() const;
	void SetTypeOfBlock(sf::Texture& texture);
	const bool GetStateOfBlock() const;
};