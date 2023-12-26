#include "Block.h"

Block::Block(int x, int y)
{
	this->sprite.setPosition(x, y);
}

void Block::SetSprite(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}