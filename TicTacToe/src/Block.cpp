#include "Block.h"


Block::Block(float x, float y)
{
	state.setPosition(x, y);
	texture.loadFromFile("res/empty.png");
	state.setTexture(texture);
	typeOfBlock = TypeOfBlock::EMPTY;
}
void Block::SetTypeOfBlock()
{
	if (g_player == 1 && this->typeOfBlock == TypeOfBlock::EMPTY) {
		this->typeOfBlock = TypeOfBlock::O;
	}
	else if (g_player == 2 && this->typeOfBlock == TypeOfBlock::EMPTY)
	{
		this->typeOfBlock = TypeOfBlock::X;
	}
	Block::SetSprite();
}
TypeOfBlock Block::GetTypeOfBlock()
{
	TypeOfBlock copy = this -> typeOfBlock;
	return copy;
}
void Block::SetSprite()
{
	if (this->typeOfBlock == TypeOfBlock::O)
	{
		this -> texture.loadFromFile("res/circle.png");
	}
	else if (this->typeOfBlock == TypeOfBlock::X)
	{
		this->texture.loadFromFile("res/x.png");
	}
	this->state.setTexture(texture);
}
sf::Sprite Block::GetSprite()
{
	sf::Sprite copy = this->state;
	return copy;
}

