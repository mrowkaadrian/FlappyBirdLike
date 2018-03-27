#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Varnaxes {
	class Ground {
	private:
		GameDataRef _data;

		std::vector<sf::Sprite> _groundSprites;
	public:
		Ground(GameDataRef data);

		void MoveGround(float dt);
		void DrawGround();
	};
}