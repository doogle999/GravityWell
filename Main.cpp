#include <stdio.h>

#include <SFML/Graphics.hpp>

#include <chrono>
#include <ratio>
#include <vector>

#include "PVector.h"
#include "Entity.h"
#include "GravityField.h"

typedef std::chrono::duration<double, std::ratio<1, 1000>> milliseconds;
const milliseconds MS_PER_UPDATE(20);

const double METERS_PER_PIXEL = 500000000;

const double TIME_SCALE = 864000;

const int WINDOW_HEIGHT = 900;
const int WINDOW_WIDTH = 1600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gravity Well");

	std::chrono::steady_clock::time_point previous = std::chrono::steady_clock::now();
	milliseconds lag(0);

	GravityField planets;

	planets.setColor(sf::Color::Green);

	planets.addEntity(2.992e11, 84150000000, 0, 30000, 0, 0, 5.972e24);
	planets.addEntity(1.496e11, 84150000000, 0, 0, 0, 0, 1.989e30);

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
			planets.updateAll(MS_PER_UPDATE.count() * TIME_SCALE);
			lag -= MS_PER_UPDATE;
		}

		window.clear();
		
		std::vector<sf::CircleShape> shapes = planets.getShapes();

		for (unsigned int i = 0; i < shapes.size(); i++)
		{
			shapes[i].setPosition(shapes[i].getPosition() / (float) METERS_PER_PIXEL);

			shapes[i].setScale(1 / METERS_PER_PIXEL, 1 / METERS_PER_PIXEL);
			window.draw(shapes[i]);
		}

		window.display();
	}

	return 0;
}