#include <SFML/Graphics.hpp>
#include "utils.h"
#include "numericalVectors.h"

void Start()
{

}

void Update()
{

}

void Draw()
{

}

void CleanUp()
{
	
}

int main()
{	
	// Make the SFML window
	sf::RenderWindow window(sf::VideoMode({ 640, 480 }), "35 bus routes run 'till midnight or later. Does yours?");

	// Delta time setup
	float deltaTime = 0.0f;
	sf::Clock deltaTimeClock = sf::Clock();

	// Share common stuff
	Utils::Init(&window, &deltaTime);

	Start();

	// Game window
	while (window.isOpen())
	{
		// Calculate delta time
		deltaTime = deltaTimeClock.restart().asSeconds();

		// Check for any events on the main window
		while (const std::optional event = window.pollEvent())
		{
			// Check for if we wanna close the window
			if (event->is<sf::Event::Closed>()) window.close();
		}

		// Update
		Update();

		// Draw
		window.clear(sf::Color::Magenta);
		Draw();
		window.display();
	}

	CleanUp();
	return 0;
}