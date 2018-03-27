#include "Ground.hpp"
#include "Definitions.hpp"

namespace Varnaxes {
	Ground::Ground(GameDataRef data) : _data(data) {
		sf::Sprite sprite(_data->assets.GetTexture("Ground"));
		sf::Sprite sprite2(_data->assets.GetTexture("Ground"));

		double sprite1posX = 0;
		double sprite1posY = _data->window.getSize().y - sprite.getGlobalBounds().height;
		double sprite2posX = sprite.getGlobalBounds().width;
		double sprite2posY = _data->window.getSize().y - sprite.getGlobalBounds().height;

		sprite.setPosition(sprite1posX, sprite1posY);
		sprite2.setPosition(sprite2posX, sprite2posY);

		_groundSprites.push_back(sprite);
		_groundSprites.push_back(sprite2);
	}

	void Ground::MoveGround(float dt) {
		float movement;
		for (unsigned short int i = 0; i < _groundSprites.size(); ++i) {
			movement = PIPE_MOVEMENT_SPEED * dt;
			_groundSprites.at(i).move(-movement, 0.0f);

			if (_groundSprites.at(i).getPosition().x < 0 - _groundSprites.at(i).getGlobalBounds().width) {
				sf::Vector2f position(_data->window.getSize().x, _groundSprites.at(i).getPosition().y);

				_groundSprites.at(i).setPosition(position);
			}
		}
	}
	
	void Ground::DrawGround() {
		for (unsigned short int i = 0; i < _groundSprites.size(); i++) {
			_data->window.draw(_groundSprites.at(i));
		}
	}
}