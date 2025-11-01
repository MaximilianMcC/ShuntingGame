#include <SFML/Graphics.hpp>
#include "utils.h"
#include "numericalVectors.h"
#include "track.h"
#include "locomotive.h"
#include "rollingStock.h"
#include "assetManager.h"
#include "trackHandler.h"

int main()
{
	// SFML setup
	sf::RenderWindow window(sf::VideoMode({ 640, 480 }), "Corporate Business Music Playlist (1 hour) Light and Upbeat Background Music For Business");
	sf::Clock deltaTimeClock = sf::Clock();

	// Load the debug font
	AssetManager::LoadDefaultFont("debug", "consola");

	// Share the window so we can draw and whatnot
	Utils::Init(&window);

	Track* root = new Track(200.0f);
	root->SetPosition(sf::Vector2f(50, 50));
	TrackHandler::Add(root);
	TrackHandler::Add(new Track(100.0f));
	TrackHandler::Add(new Track(100.0f));

	TrackHandler::ThingsOnTheTrack.push_back(new Locomotive(root));

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

		TrackHandler::Update();

		// Draw
		window.clear(sf::Color::Magenta);
		TrackHandler::DrawAllTrack();
		TrackHandler::DrawAllVehicles();
		window.display();
	}

	TrackHandler::RemoveAll();

	return 0;
}