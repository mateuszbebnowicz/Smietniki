#include <time.h>
#include "Map.h"

int main()
{
	srand(time(NULL));
	Map mapa(30, 200, 5);
	
	sf::RenderWindow window(sf::VideoMode(900, 900), "smieciorze");
	window.setFramerateLimit(20);

	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		mapa.admin(window);
	}

	return 0;
}

