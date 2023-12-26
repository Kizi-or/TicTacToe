#include "Application.h"

void Application::Initalize()
{
	this->window = nullptr;
	this->board = std::make_unique<Board>();
}

void Application::CreateWindow()
{
	this->videoMode.height = this->height;
	this->videoMode.width = this->width;
	this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "TicTacToe");
	this->window->setFramerateLimit(60);
}

Application::Application()
{
	this->Initalize();
	this->CreateWindow();
}

bool Application::AppIsOpen() const
{
	return this->window->isOpen();
}

void Application::AppUpdate()
{
	this->AppPollEvents();
}

void Application::AppRender()
{
	this->window->clear();
	this->window->display();
}

void Application::AppPollEvents()
{
	while (this->window->pollEvent(this->event)) {

		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
		if (this->event.type == sf::Event::KeyPressed && this->event.key.code == sf::Keyboard::M) {
			this->board = std::make_unique<Board>();
		}
	}
}