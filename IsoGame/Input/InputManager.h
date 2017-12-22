#pragma once

#include <SFML/Graphics.hpp>

namespace Bronckers
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
		static bool IsTextHovered(sf::Text& object,sf::RenderWindow& window);
		
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};
}