#include "Block.h"

Block::Block(int x, int y)
{
	this->positionX = x;
	this->positionY = y;
	this->sprite.setPosition(x, y);
}

void Block::SetSprite(sf::Texture& texture) { this->sprite.setTexture(texture); }

const sf::Sprite Block::GetSprite() const { return this->sprite; }

void Block::SetTypeOfBlock(sf::Texture& texture,const TypeOfBlock& typeOfBlock)
{
	SetSprite(texture);
	this->blockNotClosed = false;
	this->typeOfBlock = typeOfBlock;
}

const bool Block::GetStateOfBlock() const { return this->blockNotClosed; }
const TypeOfBlock Block::GetTypeOfBlock() const { return this->typeOfBlock; }