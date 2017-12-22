#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>
namespace Bronckers
{
	enum MenuButtonTypeEnum
	{
		StartGame,
		CloseGame,
	};

	class MenuButton : public Button
	{
	public:
		MenuButton(std::string menuText, sf::Font& font, sf::Vector2f position, sf::Vector2f size, MenuButtonTypeEnum buttonType);
		~MenuButton() {}

		void SetTextColor(sf::Color& color);
		void SetBackgroundColor(sf::Color& color);
		void SetHoverColor(sf::Color& color);

		void Draw(sf::RenderWindow& window);
		void Update(float dt);

		void HandleMouseMovedEvent(sf::RenderWindow& window);
		void HandleMouseClickedEvent(sf::RenderWindow& window, sf::Event& event);

	private:
		sf::Text _buttonText;
		sf::RectangleShape _buttonBackground;
		MenuButtonTypeEnum _buttonType;

		sf::Color _buttonColor;
		sf::Color _hoverColor;
		bool _isHovering;
	};
}
