#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Varnaxes {
	class MainMenuState : public State {
	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;

	public:
		MainMenuState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	};
}