#pragma once
#include "../../GameState/State.h"
#include "../../Game.h"
#include "../../GameObjects/MenuButton.h"

namespace Bronckers
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);
		~MainMenuState() {}

		void Init();
		void HandleEvent();
		void Update(float dt);
		void Draw(float dt);

	private: 
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _header;
		sf::Text _headerText;
		std::vector<MenuButton> _buttons;
		sf::RectangleShape _menuBorder;

		void EvaluateMouseMoved(sf::Event& event);
		void EvaluateMouseClicked(sf::Event& event);
	};


}
