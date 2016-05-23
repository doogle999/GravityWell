#include <iostream>
#include <chrono>
#include <ratio>

#include "PVector.h"
#include "Entity.h"

typedef std::chrono::duration<double, std::ratio<1, 1000>> milliseconds;

const milliseconds MS_PER_UPDATE(1000);

int main()
{
	std::chrono::steady_clock::time_point previous = std::chrono::steady_clock::now();
	milliseconds lag(0);

	while (true)
	{
		std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
		milliseconds elapsed = std::chrono::duration_cast<milliseconds>(current - previous);
		previous = current;
		lag += elapsed;

		// Input

		while (lag >= MS_PER_UPDATE)
		{
			// Update
			lag -= MS_PER_UPDATE;
		}

		// Render
	}
}