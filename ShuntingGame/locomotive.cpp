#include "locomotive.h"

#include "utils.h"

locomotive::locomotive(Track *track)
{
	// Put us on the track
	currentTrack = track;
	PositionOnTrack = 0.0f;

	// Make the actual loco
	shape = sf::RectangleShape(sf::Vector2f(25.0f, 8.0f));
	shape.setFillColor(sf::Color::Black);
}

void locomotive::Move()
{
	// Check what direction we wanna move
	float direction = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) direction += -1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) direction += 1.0f;
	if (direction == 0) return;

	// Get our new movement then move
	float newPositionOnTrack = PositionOnTrack + (speed * direction) * Utils::GetDeltaTime();
	FollowTrack(newPositionOnTrack);
}

void locomotive::Update()
{
	Move();
}
