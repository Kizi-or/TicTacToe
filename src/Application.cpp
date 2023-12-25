#include "Application.h"

void Application::Initalize()
{
	this->window = nullptr;
}

void Application::CreateWindow()
{
	this->videoMode.height = this->height;
	this->videoMode.width = this->width;
	this->window = std::make_unique<sf::RenderWindow>(this->videoMode, "TicTacToe");
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
	this->window->clear(sf::Color::Blue);
	this->window->display();
}

void Application::AppPollEvents()
{
	while (this->window->pollEvent(this->event)) {

		if (this->event.type == sf::Event::Closed) {
			window->close();
		}
	}
}