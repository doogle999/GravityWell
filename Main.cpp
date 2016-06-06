#include <stdio.h>

#include <SFML/Graphics.hpp>

#include <chrono>
#include <ratio>
#include <vector>

#include "PVector.h"
#include "Entity.h"
#include "GravityField.h"

typedef std::chrono::duration<double, std::ratio<1, 1000>> milliseconds;
const milliseconds MS_PER_UPDATE(5);

const int WINDOW_HEIGHT = 900;
const int WINDOW_WIDTH = 1600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gravity Well");

	std::chrono::steady_clock::time_point previous = std::chrono::steady_clock::now();
	milliseconds lag(0);

	GravityField planets;

	planets.setColor(sf::Color::Green);

	planets.addEntity(400, 200, 0, 0, 0, 0, 10000000000000000);
	planets.addEntity(470, 300, 0, 0, 0, 0, 10000000000000000);
	planets.addEntity(80, 238, 0, 0, 0, 0, 10000000000000000);
	planets.addEntity(800, 650, 0, 0, 0, 0, 10000000000000000);

	while (window.isOpen())
	{
		std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
		milliseconds elapsed = std::chrono::duration_cast<milliseconds>(current - previous);
		previous = current;
		lag += elapsed;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		while (lag >= MS_PER_UPDATE)
		{
			planets.updateAll(MS_PER_UPDATE.count());
			lag -= MS_PER_UPDATE;
		}

		window.clear();
		
		std::vector<sf::CircleShape> shapes = planets.getShapes();

		for (unsigned int i = 0; i < shapes.size(); i++)
		{
			window.draw(shapes[i]);
		}

		window.display();
	}

	return 0;
}