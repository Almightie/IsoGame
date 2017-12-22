#include "GameWindow.h"
#include <iostream>

namespace Bronckers
{
	GameWindow::GameWindow(unsigned width, unsigned height)
	{
		_width = width;
		_height = height;
	}

	GameWindow::~GameWindow()
	{
	}

	void GameWindow::OpenWindow()
	{
		std::cout << "Creating window of " << _width << "x" << _height << "px" << std::endl;

		_window.create(sf::VideoMode(_width, _height), "IsoGameWindow");

		while (_window.isOpen())
		{
			CatchEvents();

			_window.clear(sf::Color::Black);
			_window.display();
		}
	}

	void GameWindow::CatchEvents()
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				_window.close();
				break;
			case sf::Event::KeyPressed:
				HandleKeyPressed(event.key);
				break;
			case sf::Event::MouseButtonPressed:
				HandleMouseButtonPressed(event.mouseButton);
				break;
			}
		}
	}

	void GameWindow::HandleKeyPressed(sf::Event::KeyEvent& key)
	{
		if (key.code == sf::Keyboard::Escape)
		{
			std::cout << "The escape key  was pressed" << std::endl;
			_window.close();
		}
	}

	void GameWindow::HandleMouseButtonPressed(sf::Event::MouseButtonEvent& mouse_button)
	{

	}
}