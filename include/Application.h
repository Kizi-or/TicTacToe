#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
#include "Board.h"


class Application
{
private:
	std::unique_ptr<sf::RenderWindow> window;
	std::unique_ptr<Board> board;
	sf::VideoMode videoMode;
	sf::Event event;

	static constexpr int width = 450;
	static constexpr int height = 480;

	void Initalize();
	void CreateWindow();
public:
	Application();
	bool AppIsOpen() const;
	void AppUpdate();
	void AppRender();
	void AppPollEvents();
	void DrawBoard();

};