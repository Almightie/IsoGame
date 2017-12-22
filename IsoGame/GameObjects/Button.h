#pragma once
#include <vector>
#include <SFML/Graphics/Drawable.hpp>

namespace sf {
	class RenderWindow;
}

namespace Bronckers
{
	class Button
	{
	public:
		Button(sf::Vector2f position, sf::Vector2f size);
		~Button() {}

		virtual void Draw(sf::RenderWindow& window) = 0;
		virtual void Update(float dt) = 0;

	private:
		sf::Vector2f _position;
		sf::Vector2f _size;
	};
}
