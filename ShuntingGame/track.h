#pragma once

#include <SFML/Graphics.hpp>

class Track
{
private:
	// TODO: delete
	sf::Text* debugText;

protected:
	sf::RectangleShape shape;
public:
	sf::Vector2f Position;

	float Length;
	Track* NextTrack;
	Track* PreviousTrack;

	Track(sf::Vector2f position, float length);

	void Draw();
};