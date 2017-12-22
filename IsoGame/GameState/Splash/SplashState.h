#pragma once

#include <SFML/Graphics.hpp>
#include "../State.h"
#include "../../Game.h"

namespace Bronckers
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);
		~SplashState(){}

		void Init();
		void HandleEvent();
		void Update(float dt);
		void Draw(float dt);

	private: 
		GameDataRef _data;

		sf::Clock _clock;
		sf::Sprite _backGround;
	};


}