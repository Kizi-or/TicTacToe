#pragma once
#include "SFML/Graphics.hpp"
#include "TypeOfBlock.h"
class Block
{
private:
	sf::Sprite sprite;
	TypeOfBlock typeOfBlock = TypeOfBlock::Empty;
	int positionX = 0;
	int positionY = 0;
	bool blockNotClosed = true;

public:
	Block(int x, int y);
	void SetSprite(sf::Texture& texture);
	const sf::Sprite GetSprite() const;
	void SetTypeOfBlock(sf::Texture& texture,const TypeOfBlock& typeOfBlock);
	const bool GetStateOfBlock() const;
};