#include "Sector.h"

namespace atcsim{

Sector::Sector()
{
  _topX = _topY = _totalX = _totalY = 0;
}

Sector::Sector(float topX, float topY, float totalX, float totalY)
{
  _topX = topX;
  _topY = topY;
  _totalX = totalX;
  _totalY = totalY;
}

Sector::~Sector()
{

}

bool
Sector::isFlightInSector(Flight *aFlight)
{
  bool is_in = false;
  float posFlightX = aFlight->getPosition().get_x();
  float posFlightY = aFlight->getPosition().get_y();

  if (((posFlightX <= _topX) && (posFlightX >= (_topX - _totalX))) && ((posFlightY <= _topY) && (posFlightY >= (_topY - _totalY))))
  {
    is_in = true;
  }
  return is_in;
}

void
Sector::assignRoute(Flight *aFlight)
{

}

float
Sector::maxDistanceForAngle(float angle)
{

}

//------------------------------------------------------------------------------------------------------

SectorEspera::SectorEspera(float topX, float topY, float totalX, float totalY, int rotation)
{
  _topX = topX;
  _topY = topY;
  _totalX = totalX;
  _totalY = totalY;
  _rotation = rotation;

  _centerX = topX - totalX/2;
  _centerY = topY - totalY/2;
  _radius = 0.8 * std::min(totalX/2, totalY/2);
  _diagAngle = std::atan(_totalX / _totalY);

  _exitAngle = 270;
  _descRate = 1000;
  _hMin = 500;

  _targetPoint = NULL;

  _flightReleased = false;
  _canRelease = true;
}

SectorEspera::~SectorEspera()
{

}

void
SectorEspera::setExitAngle(float angle)
{
  _exitAngle = angle;
}

void
SectorEspera::setDescendRate(float descRate)
{
	_descRate = descRate;
}

void
SectorEspera::setMinimumHeight(float hMin)
{
	_hMin = hMin;
}

void
SectorEspera::setTargetPoint(float posX, float posY)
{
	_targetPoint = new Position(posX,posY);
}

void
SectorEspera::canRelease(bool canRelease)
{
  _canRelease = canRelease;
}

bool
SectorEspera::flightReleased()
{
  return _flightReleased;
}

float
SectorEspera::maxDistanceForAngle(float angle)
{
	float angleRad;
	float result;

  if(angle < 90)
  {
    angleRad = angle;
  }
  else if (angle < 180)
  {
    angleRad = (180 - angle);
  }
  else if (angle < 270)
  {
    angleRad = (angle - 180);
  }
  else
  {
    angleRad = (360 - angle);
  }

	angleRad = angleRad * pi/180.0;

	if (angleRad <= _diagAngle)
	{
		result =  _totalY/(2*std::cos(angleRad));
	}
	else
	{
		result = _totalX/(2*std::sin(angleRad));
	}

	return result;
}

void
SectorEspera::assignRoute(Flight *aFlight)
{
  float posFlightX = aFlight->getPosition().get_x() - _centerX;
  float posFlightY = aFlight->getPosition().get_y() - _centerY;
  float posFlightZ = aFlight->getPosition().get_z();
  float velocity = aFlight->getSpeed();
  float distance2D = sqrt((posFlightX * posFlightX) + (posFlightY * posFlightY));
  float angle;
  int status;

  Route toFollow;
  _flightReleased = false;

  angle = std::acos(posFlightX/distance2D)*180.0/pi;
  if(posFlightY < 0)
  {
    angle = 360-angle;
  }

  if((posFlightZ <= _hMin) && ((angle > _exitAngle - 15) && (angle < _exitAngle + 15)) && _canRelease)
  {
    status = 2; //Saliendo del circuito.
  }
  else
  {
	  if(distance2D > _radius + 10.0)
    {
      status = 0; //Entrando en el circuito.
    }
    else
    {
      status = 1; //Girando en el circuito.
    }
  }

  angle = angle + 15*_rotation;
  if(angle > 360)
  {
    angle = angle-360;
  }
  else if(angle < 0)
  {
    angle = angle+360;
  }

  if(status == 2)
  {
    _flightReleased = true;

	  if(_targetPoint == NULL)
	  {
		  distance2D = maxDistanceForAngle(angle) + 10.0;

		  angle = angle*pi/180.0;
		  posFlightX = distance2D * std::cos(angle) + _centerX;
		  posFlightY = distance2D * std::sin(angle) + _centerY;
	  }
	  else
	  {
		  posFlightX = _targetPoint->get_x();
		  posFlightY = _targetPoint->get_y();
	  }
  }
  else //Girando o entrando en el circuito.
  {
    velocity = std::max(175.0, velocity-20.0);

    if(status == 0)
    {
      distance2D = std::min(distance2D - std::max(50.0, (distance2D-_radius)/1.75), maxDistanceForAngle(angle)-10.0);
    }
    else //status = 1
    {
      distance2D = _radius;

      if(posFlightZ > _hMin)
      {
        posFlightZ = posFlightZ - _descRate/24.0;
      }
    }

    angle = angle*pi/180.0;
    posFlightX = distance2D * std::cos(angle) + _centerX;
    posFlightY = distance2D * std::sin(angle) + _centerY;
  }

  toFollow.pos = Position(posFlightX, posFlightY, posFlightZ);
  toFollow.speed = velocity;
  aFlight->getRoute()->push_front(toFollow);
}

//------------------------------------------------------------------------------------------------------

SectorCentral::SectorCentral(float topX, float topY, float totalX, float totalY)
{
  _topX = topX;
  _topY = topY;
  _totalX = totalX;
  _totalY = totalY;

  _diagAngle = std::atan(2 * _totalX / _totalY);
}

SectorCentral::~SectorCentral()
{

}

float
SectorCentral::maxDistanceForAngle(float angle)
{
	float angleRad;
	float result;

	if(angle < 90)
  {
		angleRad = angle;
  }
	else if (angle < 180)
  {
		angleRad = (180 - angle);
  }
	else if (angle < 270)
  {
		angleRad = (angle - 180);
  }
	else
  {
		angleRad = (360 - angle);
  }

	angleRad = angleRad * pi / 180.0;

	if (angleRad <= _diagAngle)
	{
		result =  _totalY / (2*std::cos(angleRad));
	}
	else
	{
		result = _totalX / std::sin(angleRad);
	}

	return result;
}

void
SectorCentral::assignRoute(Flight *aFlight)
{
  float posFlightX = aFlight->getPosition().get_x();
  float posFlightY = aFlight->getPosition().get_y();
  float posFlightZ = aFlight->getPosition().get_z();
  float velocity = aFlight->getSpeed();
  float distance2D;
  float angle;

  Route toFollow;

  distance2D = sqrt((posFlightX * posFlightX) + (posFlightY * posFlightY));
  angle = std::acos(posFlightX/distance2D)*180.0/pi;

  if (angle != 0)
  {
	  angle = std::max((float)0, angle - 6);
  }
  posFlightZ = distance2D*std::tan(std::min((float)(5*pi/180), std::atan(posFlightZ/distance2D)));

  if (distance2D > 4000)
  {
    distance2D = std::min(distance2D - 1000, maxDistanceForAngle(angle) - 1000);
	  velocity = std::max(140.0, velocity-20.0);
  }
  else
  {
    distance2D = distance2D - 500;
	  velocity = std::max(19.5, (140.0 / 4000.0 * distance2D) + 22.5);
  }

  angle = angle*pi/180.0;
  posFlightX = distance2D * std::cos(angle);
  posFlightY = distance2D * std::sin(angle) * ((posFlightY < 0) ? -1 : 1);

  toFollow.pos = Position(posFlightX, posFlightY, posFlightZ);
  toFollow.speed = velocity;
  aFlight->getRoute()->push_front(toFollow);
}

//------------------------------------------------------------------------------------------------------

SectorExterior::SectorExterior(float topX, float topY, float totalX, float totalY)
{
  _topX = topX;
  _topY = topY;
  _totalX = totalX;
  _totalY = totalY;

  Position *_targetPoint[4];
}

SectorExterior::~SectorExterior()
{

}

void
SectorExterior::setTargetPoint(int order, float posX, float posY)
{
	if ((order > 0) && (order <=4))
	{
		_targetPoint[order-1] = new Position(posX, posY);
	}
}

bool
SectorExterior::isFlightInSector(Flight *aFlight)
{
  float posFlightX = aFlight->getPosition().get_x();
  float posFlightY = aFlight->getPosition().get_y();
  float distance2D;

  distance2D = sqrt((posFlightX * posFlightX) + (posFlightY * posFlightY));

  return (distance2D > (0.95 * _totalX));
}

void
SectorExterior::assignRoute(Flight *aFlight)
{
  float posFlightX = aFlight->getPosition().get_x();
  float posFlightY = aFlight->getPosition().get_y();
  float posFlightZ = aFlight->getPosition().get_z();
  float velocity = aFlight->getSpeed();
  float distance2D;
  float angle;
  int target;

  Route toFollow;

  distance2D = sqrt((posFlightX * posFlightX) + (posFlightY * posFlightY));
  angle = std::acos(posFlightX/distance2D)*180.0/pi;

  target = (angle < 30.0) ? 1 : (angle < 45.0) ? 2 : (angle < 70) ? 3 : 4;

  posFlightX = _targetPoint[target-1]->get_x();
  posFlightY = _targetPoint[target-1]->get_y() * ((posFlightY >= 0) ? 1 : -1);

  posFlightZ = 500 + (int)((posFlightZ - 500) / 1000) * 1000;

	velocity = std::max(200.0, velocity-30.0);

  toFollow.pos = Position(posFlightX, posFlightY, posFlightZ);
  toFollow.speed = velocity;
  aFlight->getRoute()->push_front(toFollow);
}

};
