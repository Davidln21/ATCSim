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
#include <list>

AirController::AirController() {
	// TODO Auto-generated constructor stub
}

AirController::~AirController() {
	// TODO Auto-generated destructor stub
}

void
AirController::doWork()
{
	std::list<Flight*> flights = Airport::getInstance()->getFlights();
	std::list<Flight*>::iterator it;

	Position circuitoi0(8000.0, -10000.0, 1000.0);
	Position circuitoi1(8000.0, -7000.0, 1000.0);
	Position circuitoi2(5000.0, -10000.0, 1000.0);
	Position circuitoi3(5000.0, -7000.0, 1000.0);

	Position circuitod0(8000.0, 10000.0, 1000.0);
	Position circuitod1(8000.0, 7000.0, 1000.0);
	Position circuitod2(5000.0, 10000.0, 1000.0);
	Position circuitod3(5000.0, 7000.0, 1000.0);

	Position pos_aterrizaje_0(3500.0, 0.0, 100.0);
	Position pos_aterrizaje_1(1500.0, 0.0, 50.0);
	Position pos_aterrizaje_2(200.0, 0.0, 25.0);
	Position pos_aterrizaje_3(-750.0, 0.0, 25.0);

	Route ra0, ra1, ra2, ra3;
	Route rci0, rci1, rci2, rci3; //rutas de circuito
	Route rcd0, rcd1, rcd2, rcd3;

	ra0.pos = pos_aterrizaje_0;
	ra0.speed = 200.0;
	ra1.pos = pos_aterrizaje_1;
	ra1.speed = 100.0;
	ra2.pos = pos_aterrizaje_2;
	ra2.speed = 19.0;
	ra3.pos = pos_aterrizaje_3;
	ra3.speed = 15.0;

	rcd0.pos = circuitod0;
	rcd0.speed = 250.0;
	rcd1.pos = circuitod1;
	rcd1.speed = 250.0;
	rcd2.pos = circuitod2;
	rcd2.speed = 250.0;
	rcd3.pos = circuitod3;
	rcd3.speed = 250.0;

	rci0.pos = circuitoi0;
	rci0.speed = 250.0;
	rci1.pos = circuitoi1;
	rci1.speed = 250.0;
	rci2.pos = circuitoi2;
	rci2.speed = 250.0;
	rci3.pos = circuitoi3;
	rci3.speed = 250.0;

	if(!Airport::getInstance()-> is_booked_landing())
	{
		Flight* primero = *(flights.begin());

		primero -> getRoute() -> clear();
	}

	for(it = flights.begin(); it!=flights.end(); ++it)
	{
		if((*it)->getRoute()->empty())
		{
			/*(*it)->getRoute()->push_back(r3);
			(*it)->getRoute()->push_front(r2);
			(*it)->getRoute()->push_front(r1);
			(*it)->getRoute()->push_front(r0);*/
			if((Airport::getInstance() -> is_booked_landing()) && ((*it) -> getPosition().get_y() < 0))
			{
				(*it)->getRoute()->push_back(rci3);
				(*it)->getRoute()->push_front(rci2);
				(*it)->getRoute()->push_front(rci1);
				(*it)->getRoute()->push_front(rci0);
			}
			else
			{
				Airport::getInstance() -> book_landing();
				(*it)->getRoute()->push_back(ra3);
				(*it)->getRoute()->push_front(ra2);
				(*it)->getRoute()->push_front(ra1);
				(*it)->getRoute()->push_front(ra0);
			}
			if(Airport::getInstance() -> is_booked_landing() && ((*it) -> getPosition().get_y() > 0))
			{
				(*it)->getRoute()->push_back(rcd3);
				(*it)->getRoute()->push_front(rcd2);
				(*it)->getRoute()->push_front(rcd1);
				(*it)->getRoute()->push_front(rcd0);
			}
			else
			{
				Airport::getInstance()-> book_landing();
				(*it)->getRoute()->push_back(ra3);
				(*it)->getRoute()->push_front(ra2);
				(*it)->getRoute()->push_front(ra1);
				(*it)->getRoute()->push_front(ra0);
			}
		}
	}
}
