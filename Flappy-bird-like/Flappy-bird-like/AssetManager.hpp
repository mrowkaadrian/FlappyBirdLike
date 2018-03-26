#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace Varnaxes {
	class AssetManager {

	private:
		// ----- CLASS VARIABLES -----
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	public:
		// ----- CONTRUCTOR/DESTRUCTOR -----
		AssetManager() {}
		~AssetManager() {}

		// ----- MEMBER FUNCTIONS -----
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);
		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);
	};
}