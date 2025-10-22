#include "railVehicle.h"

#include "utils.h"

// TODO: Stop you from going off the edge of tracks
void RailVehicle::FollowTrack(float newPositionOnTrack)
{
	// Check for if we're moving forwards onto the next bit of track
	if ((newPositionOnTrack >= CurrentTrack->Length) && (CurrentTrack->NextTrack != nullptr))
	{
		// Move to the start of the next track
		CurrentTrack = CurrentTrack->NextTrack;
		newPositionOnTrack = 0.0f;

		// TODO: Play fishplate sound effect
	}

	// Check for if we're moving backwards onto the previous bit of track
	if ((newPositionOnTrack < 0.0f) && (CurrentTrack->PreviousTrack != nullptr))
	{;
		// Move to the end of the previous track
		CurrentTrack = CurrentTrack->PreviousTrack;
		newPositionOnTrack = CurrentTrack->Length;

		// TODO: Play fishplate sound effect
	}

	// Update our position
	PositionOnTrack = newPositionOnTrack;
}

void RailVehicle::Draw()
{
    shape->setPosition(CurrentTrack->Position + sf::Vector2f(PositionOnTrack, 0.0f));
    Utils::GetWindow()->draw(*shape);
}
