#pragma once

#include "GameOverState.hpp"
#include "Definitions.hpp"

#include <iostream>
#include <sstream>

namespace Varnaxes {
	GameOverState::GameOverState(GameDataRef data) : _data(data) {

	}

	void GameOverState::Init() {
		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
	}

	void GameOverState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}
		}
	}

	void GameOverState::Update(float dt) {

	}

	void GameOverState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(_background);
		this->_data->window.display();
	}
}