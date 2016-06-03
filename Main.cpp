#include <stdio.h>

#include <SFML/Graphics.hpp>

#include <chrono>
#include <ratio>

#include "PVector.h"
#include "Entity.h"
#include "GravityField.h"

typedef std::chrono::duration<double, std::ratio<1, 1000>> milliseconds;
const milliseconds MS_PER_UPDATE(50);

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gravity Well");

	std::chrono::steady_clock::time_point previous = std::chrono::steady_clock::now();
	milliseconds lag(0);

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
			lag -= MS_PER_UPDATE;
		}

		window.clear();
		window.display();
	}

	return 0;
}