#pragma once

struct Controller
{
    // (todo cooper): make bit-flag to save on memory
    bool up, down, left, right;

    Controller() = default;


    void Poll()
    {
	up = down = left = right = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	    up = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	    down = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	    left = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	    right = true;
	}

    }
};
