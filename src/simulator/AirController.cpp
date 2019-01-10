/*
 * AirController.cpp
 *
 *  Created on: 21/07/2014
 *      Author: paco
 *
 *  Copyright 2014 Francisco Martín
 *
 *  This file is part of ATCSim.
 *
 *  ATCSim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ATCSim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with ATCSim.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AirController.h"
#include "Airport.h"
#include "Flight.h"
#include "Position.h"
#include "Sector.h"
#include <list>

namespace atcsim{

AirController::AirController()
{
	SectorEspera * aSector;
	SectorExterior * aSectorExt;

	_mySectors[0] = new SectorCentral(8000.0, 8000.0, 8000.0, 16000.0);

	aSector = new SectorEspera(8000.0, 16000.0, 8000.0, 8000.0, ROTATION_R);
	aSector->setExitAngle(320);
	aSector->setMinimumHeight(500);
	aSector->setTargetPoint(6400.0, 7900.0);
	_mySectors[1] = aSector;

	aSector = new SectorEspera(16000.0, 8000.0, 8000.0, 8000.0, ROTATION_R);
	aSector->setExitAngle(270);
	aSector->setMinimumHeight( 500);
	aSector->setTargetPoint(6000.0, 0.0);
	_mySectors[2] = aSector;

	aSector = new SectorEspera(16000.0, 0.0, 8000.0, 8000.0, ROTATION_L);
	aSector->setExitAngle(90);
	aSector->setMinimumHeight( 500);
	aSector->setTargetPoint(6000.0, 0.0);
	_mySectors[3] = aSector;

	aSector = new SectorEspera(8000.0, -8000.0, 8000.0, 8000.0, ROTATION_L);
	aSector->setExitAngle(40);
	aSector->setMinimumHeight( 500);
	aSector->setTargetPoint(6400, -7900.0);
	_mySectors[4] = aSector;

	aSectorExt = new SectorExterior(20000.0, 20000.0, 20000.0, 40000.0);
	aSectorExt->setTargetPoint(1, 15000.0, 1500.0 );
	aSectorExt->setTargetPoint(2, 14400.0, 8000.0);
	aSectorExt->setTargetPoint(3, 8000.0, 14400.0);
	aSectorExt->setTargetPoint(4, 1600.0, 16000.0);
	_mySectors[5] = aSectorExt;

}

AirController::~AirController() {}

void
AirController::doWork()
{
	int numSectors = 6;
	bool flightLanding = false;
	std::list<Flight*> flights = Airport::getInstance()->getFlights();
	std::list<Flight*>::iterator it;

	int numFlights = flights.size();
	int descendRate = ((numFlights < 10) ? 2500 : ((numFlights< 20) ? 2000: 1000));

	for(int sector = 1; sector <= 4; sector++)
	{
		((SectorEspera *) _mySectors[sector])->setDescendRate(descendRate);
	}

	if (_landing != NULL)
	{
		for(it = flights.begin(); it!= flights.end(); ++it)
		{
			if(_landing->compare((*it)->getId()) == 0)
			{
				flightLanding = true;
				break;
			}
		}
		if( flightLanding == false)
		{
			delete( _landing);
			_landing = NULL;
		}
	}

	for(it = flights.begin(); it!=flights.end(); ++it)
	{
		if(_mySectors[0]->isFlightInSector(*it))
		{
			flightLanding = true;
			if((*it)->getRoute()->empty())
				_mySectors[0]->assignRoute(*it);
			break;
		}
	}

	for(it = flights.begin(); it!=flights.end(); ++it)
	{
		if((*it)->getRoute()->empty())
		{
			for(int sector = 1; sector <= 4; sector++)
			{
				if(_mySectors[sector]->isFlightInSector(*it))
				{
					((SectorEspera*)_mySectors[sector])->canRelease(!flightLanding);
					_mySectors[sector]->assignRoute(*it);
					if(((SectorEspera*)_mySectors[sector])->flightReleased())
					{
						flightLanding = true;
						_landing = new std::string( (*it)->getId());
					}
					break;
				}
			}
		}
	}

	for(it = flights.begin(); it!=flights.end(); ++it)
	{
		if((*it)->getRoute()->empty())
		{
			if(_mySectors[5]->isFlightInSector(*it))
			{
				_mySectors[5] -> assignRoute(*it);
			}
		}
	}
}

};  // namespace atcsim
