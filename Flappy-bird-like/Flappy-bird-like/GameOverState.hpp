#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Varnaxes {
	class GameOverState : public State {
	private:
		GameDataRef _data;
		sf::Texture _backgroundTexture;
		sf::Sprite _background;

	public:
		GameOverState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	};
}