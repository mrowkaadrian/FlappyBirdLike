#include "Pipe.hpp"
#include "Definitions.hpp"

namespace Varnaxes {
	Pipe::Pipe(GameDataRef data) : _data(data) { 
	
	}

	void Pipe::SpawnTopPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		double spritePosX = _data->window.getSize().x;
		double spritePosY = 0;

		sprite.setPosition(spritePosX, spritePosY);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnBottomPipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));

		double spritePosX = _data->window.getSize().x;
		double spritePosY = _data->window.getSize().y - sprite.getGlobalBounds().height;

		sprite.setPosition(spritePosX, spritePosY);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnInvisiblePipe() {
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		double spritePosX = _data->window.getSize().x;
		double spritePosY = _data->window.getSize().y - sprite.getGlobalBounds().height;

		sprite.setPosition(spritePosX, spritePosY);

		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeSprites.push_back(sprite);
	}

	void Pipe::MovePipes(float dt) {
		for (unsigned short int i = 0; i < pipeSprites.size(); ++i) {
			sf::Vector2f position = pipeSprites.at(i).getPosition();
			float movement = PIPE_MOVEMENT_SPEED * dt;

			pipeSprites.at(i).move(-movement, 0);
		}
	}

	void Pipe::DrawPipes() {
		for (unsigned short int i = 0; i < pipeSprites.size(); ++i) {
			_data->window.draw(pipeSprites.at(i));
		}
	}
}