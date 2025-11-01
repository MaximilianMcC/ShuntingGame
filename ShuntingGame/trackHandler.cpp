#include "trackHandler.h"

std::vector<Track*> TrackHandler::Railway;
std::vector<RailVehicle*> TrackHandler::ThingsOnTheTrack;

void TrackHandler::Add(Track* trackToAdd)
{
	if (Railway.empty() == false)
	{
		// Get the previous track an add the new track
		Track* previousTrack = Railway.back();
		Railway.push_back(trackToAdd);
		Track* newTrack = Railway.back();

		// Join the tracks together
		previousTrack->NextTrack = newTrack;
		newTrack->PreviousTrack = previousTrack;

		// Adjust the position so that it is 'next' to it
		newTrack->SetPosition(previousTrack->GetEndPosition());
	}
	else
	{
		// Add the new track without
		// doing anything special
		Railway.push_back(trackToAdd);
	}
}

void TrackHandler::RemoveAll()
{
	// Delete all track pointers
	for (size_t i = 0; i < Railway.size(); i++)
	{
		delete Railway[i];
		Railway[i] = nullptr;
	}
	Railway.clear();

	// Delete all rail vehicles
	for (size_t i = 0; i < ThingsOnTheTrack.size(); i++)
	{
		delete ThingsOnTheTrack[i];
		ThingsOnTheTrack[i] = nullptr;
	}
	ThingsOnTheTrack.clear();
}

void TrackHandler::Update()
{
	for (size_t i = 0; i < ThingsOnTheTrack.size(); i++)
	{
		ThingsOnTheTrack[i]->Update();
	}
}

void TrackHandler::DrawAllTrack()
{
	for (size_t i = 0; i < Railway.size(); i++)
	{
		Railway[i]->Draw();
	}
}

void TrackHandler::DrawAllVehicles()
{
	for (size_t i = 0; i < ThingsOnTheTrack.size(); i++)
	{
		ThingsOnTheTrack[i]->Draw();
	}
}
