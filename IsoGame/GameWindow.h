#pragma once
#include <SFML/Graphics.hpp>

namespace Bronckers
{
	class GameWindow
	{
	public:
		GameWindow(unsigned width, unsigned height);
		~GameWindow();

		void OpenWindow();
	private:
		void HandleKeyPressed(sf::Event::KeyEvent& key);
		void HandleMouseButtonPressed(sf::Event::MouseButtonEvent& mouse_button);
		void CatchEvents();

		sf::RenderWindow _window;
		int32_t _height;
		int32_t _width;
	};

}
