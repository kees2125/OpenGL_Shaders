#define _USE_MATH_DEFINES

#include "Movement.h"
#include <math.h>


Movement::Movement()
{
}


void Movement::goForward()
{
	movingForward = true;
}

void Movement::goBackward()
{
	movingBackward = true;
}

void Movement::turnLeft(bool turnLeft)
{
	turningLeft = turnLeft;
}

void Movement::turnRight(bool turnRight)
{
	turningRight = turnRight;
}

void Movement::stop()
{
	movingBackward = false;
	movingForward = false;
}

void Movement::move(int elapsedTime)
{
	if (movingForward)
	{
		position[0] += (float)0.05 * elapsedTime * sin(rotation[1] / 180 * M_PI);
		position[1] -= (float)0.05 * elapsedTime * sin(rotation[0] / 180 * M_PI);
		position[2] -= (float)0.05 * elapsedTime * cos((rotation[1] + rotation[0]) / 180 * M_PI);
	}
	else if (movingBackward)
	{
		position[0] -= (float)0.05 * elapsedTime * sin(rotation[1] / 180 * M_PI);
		position[1] += (float)0.05 * elapsedTime * sin(rotation[0] / 180 * M_PI);
		position[2] += (float)0.05 * elapsedTime * cos((rotation[1] + rotation[0]) / 180 * M_PI);
	}
	if (turningLeft)
	{
		rotation[1]--;
	}
	if (turningRight)
	{
		rotation[1]++;
	}
}

Movement::~Movement()
{
}
