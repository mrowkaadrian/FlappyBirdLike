#pragma once

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include <vector>

namespace Varnaxes {
	class Pipe {
	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
	public:
		Pipe(GameDataRef data);
		
		void SpawnTopPipe();
		void SpawnBottomPipe();
		void SpawnInvisiblePipe();
		void MovePipes(float dt);
		void DrawPipes();

	};
}
