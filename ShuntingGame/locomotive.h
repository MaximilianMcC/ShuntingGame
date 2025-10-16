#pragma once

#include "railVehicle.h"

class Locomotive : public RailVehicle
{
private:
	float speed = 100.0f;
	void Move();

public:
	Locomotive(Track* track);
	void Update() override;
};