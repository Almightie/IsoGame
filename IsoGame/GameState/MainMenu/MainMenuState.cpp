#include "../../Definitions.h"
#include "MainMenuState.h"
#include "../../GameObjects/MenuButton.h"


namespace Bronckers
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
		_buttons = std::vector<MenuButton>();
	}

	void MainMenuState::Init()
	{
		std::vector<std::string> menuItems;
		menuItems.push_back("Start Game");
		menuItems.push_back("Close Game");
		sf::Color textColor(205, 210, 220);
		sf::Color bgColor(25, 35, 50);
		sf::Color hoverColor(105, 140, 185);

		_data->assets.LoadTexture("MainMenuBackground", MAIN_MENU_BACKGROUND_FILEPATH);
		_background.setTexture(_data->assets.GetTexture("MainMenuBackground"));

		_data->assets.LoadTexture("MainMenuHeader", MAIN_MENU_HEADER_FILEPATH);
		_header.setTexture(_data->assets.GetTexture("MainMenuHeader"));
		_header.setPosition(sf::Vector2f(((_data->window.getSize().x / 2) - 73), ((_data->window.getSize().y / 2) - 135)));

		_headerText = sf::Text("Main Menu", _data->assets.GetFont("ManaSpace"));
		_headerText.setCharacterSize(15);
		_headerText.setPosition(_header.getPosition().x + ((_header.getLocalBounds().width - _headerText.getLocalBounds().width) / 2), _header.getPosition().y + ((_header.getLocalBounds().height - _headerText.getLocalBounds().height) / 3));
		_headerText.setFillColor(sf::Color::White);

		_menuBorder = sf::RectangleShape(sf::Vector2f(142, ((25 * menuItems.size()) + 2) + 34));
		_menuBorder.setFillColor(sf::Color(114, 151, 204));
		_menuBorder.setOutlineColor(sf::Color(21, 28, 38));
		_menuBorder.setOutlineThickness(1.0f);
		_menuBorder.setPosition(_header.getPosition().x + 2, _header.getPosition().y);

		for (int i = 0; i < menuItems.size(); i++)
		{
			MenuButtonTypeEnum buttonType;
			if(i == 0)
			{
				buttonType = MenuButtonTypeEnum::StartGame;
			}
			else
			{
				buttonType = MenuButtonTypeEnum::CloseGame;
			}

			MenuButton button = MenuButton(menuItems.at(i), _data->assets.GetFont("ManaSpace"), sf::Vector2f((_data->window.getSize().x / 2) - 70, ((_data->window.getSize().y / 2) - 100) + (25 * i)), sf::Vector2f(140, 25), buttonType);
			button.SetTextColor(textColor);
			button.SetBackgroundColor(bgColor);
			button.SetHoverColor(hoverColor);

			_buttons.push_back(button);
		}
	}

	void MainMenuState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Black);

		_data->window.draw(_menuBorder);
		_data->window.draw(_header);
		_data->window.draw(_headerText);

		for (int i = 0; i < _buttons.size(); i++)
		{
			_buttons.at(i).Draw(_data->window);
		}
		_data->window.display();
	}

	void MainMenuState::HandleEvent()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::EventType::MouseButtonPressed:
				EvaluateMouseClicked(event);
				break;
			case sf::Event::EventType::MouseMoved:
				EvaluateMouseMoved(event);
				break;
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		for (int i = 0; i < _buttons.size(); i++)
		{
			_buttons.at(i).Update(dt);
		}
	}

	void MainMenuState::EvaluateMouseClicked(sf::Event& event)
	{
		for (int i = 0; i < _buttons.size(); i++)
		{
			_buttons.at(i).HandleMouseClickedEvent(_data->window, event);
		}
	}

	void MainMenuState::EvaluateMouseMoved(sf::Event& event)
	{
		for (int i = 0; i < _buttons.size(); i++)
		{
			_buttons.at(i).HandleMouseMovedEvent(_data->window);
		}
	}
}
