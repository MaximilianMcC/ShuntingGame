#include <SFML/Graphics.hpp>
#include "utils.h"
#include "numericalVectors.h"
#include "track.h"
#include "locomotive.h"
#include "rollingStock.h"
#include "assetManager.h"

int main()
{	
	// SFML setup
	sf::RenderWindow window(sf::VideoMode({ 640, 480 }), "we should turn the skytower into a rocket ship");
	sf::Clock deltaTimeClock = sf::Clock();

	// Load the debug font
	AssetManager::LoadDefaultFont("debug", "consola");

	// Share the window so we can draw and whatnot
	Utils::Init(&window);

	Track* track1 = new Track(sf::Vector2f(100.0f, 100.0f), 100.0f);
	Track* track2 = new Track(sf::Vector2f(200.0f, 100.0f), 200.0f);
	Track* track3 = new Track(sf::Vector2f(400.0f, 100.0f), 200.0f);
	Track* track4 = new Track(sf::Vector2f(600.0f, 100.0f), 300.0f);

	track1->NextTrack = track2;
	track2->NextTrack = track3;
	track3->NextTrack = track4;
	track4->NextTrack = nullptr;

	track2->PreviousTrack = track1;
	track3->PreviousTrack = track2;
	track4->PreviousTrack = track3;
	track1->PreviousTrack = nullptr;

	Locomotive* loco = new Locomotive(track1);

	// Game window
	while (window.isOpen())
	{
		// Calculate and update delta time
		Utils::DeltaTime = deltaTimeClock.restart().asSeconds();

		// Check for any events
		while (const std::optional event = window.pollEvent())
		{
			// Check for if we wanna close the window
			if (event->is<sf::Event::Closed>()) window.close();
		}

		// Update
		loco->Update();

		// Draw
		window.clear(sf::Color::Magenta);
		track1->Draw();
		track2->Draw();
		track3->Draw();
		track4->Draw();
		loco->Draw();
		window.display();
	}

	delete loco;
	delete track1;
	delete track2;
	delete track3;
	delete track4;

	return 0;
}