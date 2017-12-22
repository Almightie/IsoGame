#include "sstream"
#include <iostream>

#include "SplashState.h"
#include "../../Definitions.h"
#include "../MainMenu/MainMenuState.h"

namespace Bronckers
{
	SplashState::SplashState(GameDataRef data) : _data( data )
	{
				
	}

	void SplashState::Init()
	{
		_data->assets.LoadTexture("SplashStateBackground", SPLASH_SCENE_BACKGROUND_FILEPATH);
		_backGround.setTexture(_data->assets.GetTexture("SplashStateBackground"));

		_data->assets.LoadFont("Astron", "Resources/Fonts/astron boy.ttf");
		_data->assets.LoadFont("OpenSansRegular", "Resources/Fonts/OpenSans-Regular.ttf");
		_data->assets.LoadFont("ManaSpace", "Resources/Fonts/manaspc.ttf");
	}

	void SplashState::HandleEvent()
	{
		sf::Event event;

		while(_data->window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if(_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Red);
		_data->window.draw(_backGround);
		_data->window.display();
	}

}
