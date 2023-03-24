#pragma once
#include<SFML/Graphics.hpp>

extern int g_player;

enum class TypeOfBlock
{
	EMPTY, O, X
};
class Block
{
private:
	sf::Sprite state;
	sf::Texture texture;
	TypeOfBlock typeOfBlock;
public:
	Block(float x, float y);
	Block() = delete;
	~Block() = default;
	void SetTypeOfBlock();
	TypeOfBlock GetTypeOfBlock();
	void SetSprite();
	sf::Sprite GetSprite();
	
};

