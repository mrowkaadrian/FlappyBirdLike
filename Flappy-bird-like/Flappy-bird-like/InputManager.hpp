#pragma once

#include <SFML/Graphics.hpp>

namespace Varnaxes {

	class InputManager {
	private:
		// ----- CLASS VARIABLES -----

	public:
		// ----- CONSTRUCTOR/DESTRUCTOR -----
		InputManager() {}
		~InputManager() {}

		// ----- MEMBER FUNCTIONS -----
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	
	};
}