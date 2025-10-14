#pragma once

#include "railVehicle.h"

class locomotive : public RailVehicle
{
private:
	float speed = 100.0f;
	void Move();

public:
	locomotive(Track* track);
	void Update() override;
};