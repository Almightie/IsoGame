#pragma once
#include <SFML/Graphics.hpp>

namespace Bronckers
{
	class State
	{
	public:
		virtual ~State() = default;
		virtual void Init() = 0;
		virtual void HandleEvent() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;

		 void Pause(){}
		void Resume(){}
	};
}