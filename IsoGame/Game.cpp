#include "Game.h"
#include "GameState/Splash/SplashState.h"

namespace Bronckers
{
	Game::Game(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(_data)));
		Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;
		float currentTime = _clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while(_data->window.isOpen())
		{
			_data->machine.ProcessStateChanges();

			newTime = _clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if(frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			_data->machine.GetActiveState()->HandleEvent();

			while(accumulator >= dt)
			{
				_data->machine.GetActiveState()->Update(dt);
				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}