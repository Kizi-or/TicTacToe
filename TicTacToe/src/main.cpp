#include <iostream>
#include <SFML/Graphics.hpp>
#include "block.h"
#include <vector>

//Global variable that manage of win state
// 0 - Game is not over
// 1 - Player "O" win
// 2 - Player "X" win
// 3 - Dead-heat
int g_win = 0;
//
// Global variable that manage of what player actually play
// 1 - Player "O" play
// 2 - Player "X" play
int g_player = 1;
//

// Function to make container for our blocks
std::vector<std::vector<Block*>> Filling()
{
	std::vector<std::vector<Block*>> vector;

	float xPosition = 0.0f;
	float yPosition = 0.0f;
	for (int i = 0; i < 3; i++)
	{

		vector.push_back(std::vector<Block*>());
		for (int j = 0; j < 3; j++)
		{
			vector[i].push_back(new Block(xPosition, yPosition));
			yPosition += 150.0f;
		}
		xPosition += 150.0f;
		yPosition = 0;
	}

	return vector;
}
// Function to checking, what block was clicked
void CheckClick(std::vector<std::vector<Block*>>& listOfBlocks,sf::Vector2f translated_pos) 
{
	for (int i = 0; i < listOfBlocks.size(); i++)
	{
		for (int j = 0; j < listOfBlocks[i].size(); j++)
		{
			if (listOfBlocks[i][j]->GetSprite().getGlobalBounds().contains(translated_pos)
				&& listOfBlocks[i][j]->GetTypeOfBlock() == TypeOfBlock::EMPTY
				&& g_win == 0 )
			{
				listOfBlocks[i][j]->SetTypeOfBlock();
				g_player == 1 ? g_player++ : g_player--;
			}
		}
	}
}
// Function to draw all blocks on the window
void DrawBlocks(std::vector<std::vector<Block*>>& listOfBlocks, sf::RenderWindow& window)
{
	for (int i = 0; i < listOfBlocks.size(); i++)
	{
		for (int j = 0; j < listOfBlocks[i].size(); j++)
		{
			window.draw(listOfBlocks[i][j]->GetSprite());
		}
	}
}
//Function to display what player actually play
void DrawInfo(sf::Sprite& sprite, sf::Texture& texture)
{
	if (g_win == 0)
	{
		if (g_player == 1)
		{
			texture.loadFromFile("res/moveO.png");
		}
		else if (g_player == 2)
		{
			texture.loadFromFile("res/moveX.png");
		}
	}
	if (g_win == 1)
	{
		texture.loadFromFile("res/winO.png");
	}
	else if (g_win == 2)
	{
		texture.loadFromFile("res/winX.png");
	}
	else if (g_win == 3)
	{
		texture.loadFromFile("res/dead-heat.png");
	}
	sprite.setTexture(texture);
	sprite.setPosition(0, 450);
}
// Checking of Dead-heat
void IsDeadHeat(int& g_win, std::vector<std::vector<Block*>>& listOfBlocks)
{
	int toDeadHeat = 0;
	for (int i = 0; i < listOfBlocks.size(); i++)
	{
		for (int j = 0; j < listOfBlocks[i].size(); j++)
		{
			if (listOfBlocks[i][j]->GetTypeOfBlock() != TypeOfBlock::EMPTY)
			{
				toDeadHeat++;
				if (toDeadHeat == 9 && g_win == 0)
				{
					g_win = 3;
				}
			}
		}
	}
}
// Checking of win
void IsWinner(int& g_win, std::vector<std::vector<Block*>>& listOfBlocks)
{
	// Check for "O" player
	if (listOfBlocks[0][0]->GetTypeOfBlock() == TypeOfBlock::O &&
		listOfBlocks[1][1]->GetTypeOfBlock() == TypeOfBlock::O &&
		listOfBlocks[2][2]->GetTypeOfBlock() == TypeOfBlock::O)
	{
		g_win = 1;
	}
	else if (listOfBlocks[0][2]->GetTypeOfBlock() == TypeOfBlock::O &&
		listOfBlocks[1][1]->GetTypeOfBlock() == TypeOfBlock::O &&
		listOfBlocks[2][0]->GetTypeOfBlock() == TypeOfBlock::O)
	{
		g_win = 1;
	}
	for (int i = 0; i < 3; i++)
	{
		if (listOfBlocks[i][0]->GetTypeOfBlock() == TypeOfBlock::O &&
			listOfBlocks[i][1]->GetTypeOfBlock() == TypeOfBlock::O &&
			listOfBlocks[i][2]->GetTypeOfBlock() == TypeOfBlock::O)
		{
			g_win = 1;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (listOfBlocks[0][i]->GetTypeOfBlock() == TypeOfBlock::O &&
			listOfBlocks[1][i]->GetTypeOfBlock() == TypeOfBlock::O &&
			listOfBlocks[2][i]->GetTypeOfBlock() == TypeOfBlock::O)
		{
			g_win = 1;
		}
	}
	// Check for "X" player
	if (listOfBlocks[0][0]->GetTypeOfBlock() == TypeOfBlock::X &&
		listOfBlocks[1][1]->GetTypeOfBlock() == TypeOfBlock::X &&
		listOfBlocks[2][2]->GetTypeOfBlock() == TypeOfBlock::X)
	{
		g_win = 2;
	}
	else if (listOfBlocks[0][2]->GetTypeOfBlock() == TypeOfBlock::X &&
		listOfBlocks[1][1]->GetTypeOfBlock() == TypeOfBlock::X &&
		listOfBlocks[2][0]->GetTypeOfBlock() == TypeOfBlock::X)
	{
		g_win = 2;
	}
	for (int i = 0; i < 3; i++)
	{
		if (listOfBlocks[i][0]->GetTypeOfBlock() == TypeOfBlock::X &&
			listOfBlocks[i][1]->GetTypeOfBlock() == TypeOfBlock::X &&
			listOfBlocks[i][2]->GetTypeOfBlock() == TypeOfBlock::X)
		{
			g_win = 2;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (listOfBlocks[0][i]->GetTypeOfBlock() == TypeOfBlock::X &&
			listOfBlocks[1][i]->GetTypeOfBlock() == TypeOfBlock::X &&
			listOfBlocks[2][i]->GetTypeOfBlock() == TypeOfBlock::X)
		{
			g_win = 2;
		}
	}
}
// Dealloc memory of blocks
void Reset(std::vector<std::vector<Block*>>& listOfBlocks) 
{
	for (int i = 0; i < listOfBlocks.size(); i++)
	{
		for (int j = 0; j < listOfBlocks[i].size(); j++)
		{
			delete listOfBlocks[i][j];
		}
		listOfBlocks[i].clear();
	}
}
int main()
{
	bool isActive = true;
	while (isActive) {
		sf::RenderWindow window(sf::VideoMode(450, 480), "TicTacToe");
		// Create container for our blocks
		std::vector<std::vector<Block*>> listOfBlocks = Filling();

		sf::Sprite info;
		sf::Texture texture;

		while (window.isOpen())
		{
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					isActive = false;
				}
				if (event.key.code == sf::Keyboard::M)
				{
					Reset(listOfBlocks);
					g_win = 0;
					g_player = 1;
					window.close();
				}
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						// Getting position of clicking
						auto mouse_pos = sf::Mouse::getPosition(window);
						auto translated_pos = window.mapPixelToCoords(mouse_pos);
						CheckClick(listOfBlocks, translated_pos);
						IsWinner(g_win, listOfBlocks);
						IsDeadHeat(g_win, listOfBlocks);

					}
				}
			}
			window.clear();
			DrawBlocks(listOfBlocks, window);
			DrawInfo(info, texture);
			window.draw(info);
			window.display();
		}
	}
	return 0;
}