#include "MenuButton.h"
#include "../Assets/AssetManager.h"

namespace Bronckers
{
	MenuButton::MenuButton(std::string menuText, sf::Font& font, sf::Vector2f position, sf::Vector2f size, MenuButtonTypeEnum buttonType) : Button(position, size)
	{	
		_buttonType = buttonType;
		_buttonBackground = sf::RectangleShape(size);
		_buttonBackground.setPosition(position);

		_isHovering = false;
		_buttonText = sf::Text(menuText, font);
		_buttonText.setCharacterSize(11);
		_buttonText.setPosition(_buttonBackground.getPosition().x + ((_buttonBackground.getSize().x - _buttonText.getLocalBounds().width) / 2), _buttonBackground.getPosition().y + ((_buttonBackground.getSize().y - _buttonText.getLocalBounds().height) / 3));
	}

	void MenuButton::SetTextColor(sf::Color& color)
	{
		_buttonText.setFillColor(color);
	}

	void MenuButton::SetBackgroundColor(sf::Color& color)
	{
		_buttonBackground.setFillColor(color);
		_buttonColor = color;
	}

	void MenuButton::SetHoverColor(sf::Color& color)
	{
		_hoverColor = color;
	}

	void MenuButton::Draw(sf::RenderWindow& window)
	{
		window.draw(_buttonBackground);
		window.draw(_buttonText);
	}

	void MenuButton::HandleMouseMovedEvent(sf::RenderWindow& window)
	{
		sf::FloatRect tempRect = _buttonBackground.getGlobalBounds();
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		if(tempRect.contains(mousePosition.x, mousePosition.y))
		{
			_isHovering = true;
		}
		else
		{
			_isHovering = false;
		}
	}

	void MenuButton::HandleMouseClickedEvent(sf::RenderWindow& window, sf::Event& event)
	{
		if(event.mouseButton.button == sf::Mouse::Button::Left)
		{
			sf::FloatRect tempRect = _buttonBackground.getGlobalBounds();
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			if (tempRect.contains(mousePosition.x, mousePosition.y))
			{
				switch (_buttonType)
				{
					case MenuButtonTypeEnum::StartGame:
						break;
					case MenuButtonTypeEnum::CloseGame:
						window.close();
						break;
				}
			}
		}
	}


	void MenuButton::Update(float dt)
	{
		if(_isHovering)
		{
			_buttonBackground.setFillColor(_hoverColor);
		}
		else
		{
			_buttonBackground.setFillColor(_buttonColor);
		}
	}
}
