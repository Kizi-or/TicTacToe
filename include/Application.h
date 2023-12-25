#include <iostream>

#include <memory>
#include "SFML/Graphics.hpp"


class Application
{
private:
	std::unique_ptr<sf::RenderWindow> window;
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


};