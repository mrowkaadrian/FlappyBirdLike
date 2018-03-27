#pragma once

#include "GameState.hpp"
#include "Definitions.hpp"

#include <iostream>
#include <sstream>

namespace Varnaxes {
	GameState::GameState(GameDataRef data) : _data(data) {

	}

	void GameState::Init() {
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Up", ITEM_PIPE_UP_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Down", ITEM_PIPE_DOWN_FILEPATH);
		this->_data->assets.LoadTexture("Ground", GROUND_FILEPATH);

		pipe = new Pipe(_data);
		ground = new Ground(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	}

	void GameState::HandleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
				/*
				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				*/
			}
		}
	}

	void GameState::Update(float dt) {

		pipe->MovePipes(dt);
		ground->MoveGround(dt);

		if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_RATE) {

			pipe->SpawnBottomPipe();
			pipe->SpawnTopPipe();
			pipe->SpawnInvisiblePipe();
			clock.restart();
		}
	}

	void GameState::Draw(float dt) {
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(_background);
		pipe->DrawPipes();
		ground->DrawGround();
		this->_data->window.display();
	}
}