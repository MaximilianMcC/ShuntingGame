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
	Track* NextTrack = nullptr;
	Track* PreviousTrack = nullptr;

	Track(float length, sf::Vector2f position = { 0, 0 });

	sf::Vector2f GetEndPosition();
	void SetPosition(sf::Vector2f newPosition);

	void Draw();
};