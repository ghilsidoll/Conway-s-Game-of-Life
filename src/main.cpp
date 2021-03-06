#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/game_controller.hpp"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1291, 712), "Conway's Game of Life", sf::Style::Close | sf::Style::Titlebar, settings);
	window.setFramerateLimit(60);
	cr::game_controller game(window, 76, 50, 12);
	game.start();

	return EXIT_SUCCESS;
}