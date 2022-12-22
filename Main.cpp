#define _USE_MATH_DEFINES
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Math.hpp"
#include "Track.hpp"
#include "Controller.hpp"
#include "Car.hpp"



int main()
{
    int screenWidth = 1280;
    int screenHeight = 720;
    int tracksAcross = 30;
    int tracksDown = 30;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Kart Basics");

    Track track(tracksAcross, tracksDown, screenWidth / tracksAcross , screenHeight / tracksDown);
    Controller controller;
    sf::Clock clock;
    Car car(Vec2(30.0f, 30.0f), Vec2(1.0f, 0.0f));

    while (window.isOpen()) {
	sf::Event event;
	while (window.pollEvent(event)) {
	    if (event.type == sf::Event::Closed) {
		window.close();
	    }
	}

	float dt = clock.getElapsedTime().asSeconds();
	clock.restart();
	controller.Poll();
	
	car.Update(dt, controller);
	
	window.clear(sf::Color(20,20,20,255));

	track.Render(window);
	car.Render(window);

	window.display();
    }
    
    return 0;
}
