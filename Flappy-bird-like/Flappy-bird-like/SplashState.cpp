#pragma once

#include "SplashState.hpp"
#include "Definitions.hpp"

#include <iostream>
#include <sstream>

namespace Varnaxes {
	SplashState::SplashState(GameDataRef data) : _data(data) {

	}

	void SplashState::Init() {
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}

	void SplashState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt) {
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			std::cout << "Go to main menu\n";
		}
	}

	void SplashState::Draw(float dt) {
		this->_data->window.clear();
		this->_data->window.draw(_background);
		this->_data->window.display();
	}
}