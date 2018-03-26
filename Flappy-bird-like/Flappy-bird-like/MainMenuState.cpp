#include "MainMenuState.hpp"
#include "Definitions.hpp"

#include <iostream>
#include <sstream>

namespace Varnaxes {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data) {

	}

	void MainMenuState::Init() {
		float titlePosX, titlePosY, buttonPosX, buttonPosY;

		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		titlePosX = (SCREEN_WIDTH / 2) - ((_title.getGlobalBounds().width) / 2);
		titlePosY = ((_title.getGlobalBounds().height) / 2);

		buttonPosX = (SCREEN_WIDTH / 2) - ((_playButton.getGlobalBounds().width) / 2);
		buttonPosY = (SCREEN_HEIGHT / 2) - ((_playButton.getGlobalBounds().height) / 2);

		_title.setPosition(titlePosX, titlePosY);
		_playButton.setPosition(buttonPosX, buttonPosY);
	}

	void MainMenuState::HandleInput() {
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window)) {
				std::cout << "Go to game screen \n";
			}
		}
	}

	void MainMenuState::Update(float dt) {
		
	}

	void MainMenuState::Draw(float dt) {
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}