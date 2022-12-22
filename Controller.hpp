#pragma once
#include <SFML/Graphics.hpp>

struct Controller
{
    // (todo cooper): make bit-flag to save on memory
    bool up, down, left, right;

    Controller() = default;


    void Poll()
    {
	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up); 
	
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);

	right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    }
};
