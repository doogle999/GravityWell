#include <stdio.h>

#include <chrono>
#include <ratio>

#include "PVector.h"
#include "Entity.h"

typedef std::chrono::duration<double, std::ratio<1, 1000>> milliseconds;
const milliseconds MS_PER_UPDATE(50);

int main()
{
	Entity thing;

	thing.setPose(0, 0, 1, 0, 0, 0);

	bool quit = false;

	std::chrono::steady_clock::time_point previous = std::chrono::steady_clock::now();
	milliseconds lag(0);

	while (!quit)
	{
		std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
		milliseconds elapsed = std::chrono::duration_cast<milliseconds>(current - previous);
		previous = current;
		lag += elapsed;

		// Input

		while (lag >= MS_PER_UPDATE)
		{
			thing.update(MS_PER_UPDATE.count());
			lag -= MS_PER_UPDATE;
		}

		// Render
	}

	return 0;
}