#include <cstdlib>
#include <iostream>
#include <math.h>
#include "Flight.h"
#include <algorithm>

#ifndef SECTOR_H_
#define SECTOR_H_

#define ROTATION_R -1
#define ROTATION_L 1

namespace atcsim{

class Sector
{
public:
    Sector();
    Sector(float topX, float topY, float totalX, float totalY); 
    ~Sector();
    virtual bool isFlightInSector(Flight *aFlight);
    virtual void assignRoute(Flight *aFlight);
    virtual float maxDistanceForAngle(float angle);

protected:
    float _topX;
    float _topY;
    float _totalX;
    float _totalY;
};

class SectorEspera:public Sector
{
public:
  SectorEspera(float topX, float topY, float totalX, float totalY, int rotation);
  ~SectorEspera();
  void setExitAngle(float angle);
  void setDescendRate(float descRate);
  void setMinimumHeight(float hMin);
  void setTargetPoint(float posX, float posY);
  void assignRoute(Flight *aFlight);
  float maxDistanceForAngle(float angle);
  bool flightReleased();
  void canRelease(bool canRelease);

private:
  float _centerX;
  float _centerY;
  float _radius;
  float _diagAngle;
  int _rotation;
  float _hMin;
  float _exitAngle;
  float _descRate;
  Position *_targetPoint = NULL;
  bool _flightReleased = false;
  bool _canRelease = true;
};

class SectorCentral:public Sector
{
public:
  SectorCentral(float topX, float topY, float totalX, float totalY);
  ~SectorCentral();
  void assignRoute(Flight *aFlight);
  float maxDistanceForAngle(float angle);

private:
  float _diagAngle;
};

class SectorExterior:public Sector
{
public:
  SectorExterior(float topX, float topY, float totalX, float totalY);
  ~SectorExterior();
  void assignRoute(Flight * aFlight);
  void setTargetPoint(int order, float posX, float posY);
  bool isFlightInSector(Flight *aFlight);

private:

  Position *_targetPoint[4];

};

};
#endif
