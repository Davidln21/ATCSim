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

	//Puntos que definen un circuito hexagonal en sentido horario en el cuadrante central izquierdo.
	Position circuitoizq1_1(15000.0, 8000.0, 3500.0);
	Position circuitoizq1_2(13500.0, 5000.0, 3500.0);
	Position circuitoizq1_3(10500.0, 5000.0, 3500.0);
	Position circuitoizq1_4(9000.0, 8000.0, 3500.0);
	Position circuitoizq1_5(10500.0, 11000.0, 3500.0);
	Position circuitoizq1_6(13500.0, 11000.0, 2800.0);
	Position circuitoizq1_7(15000.0, 8000.0, 2100.0);
	Position circuitoizq1_8(13500.0, 5000.0, 2100.0);
	Position circuitoizq1_9(10500.0, 5000.0, 2100.0);
	Position circuitoizq1_10(9000.0, 8000.0, 2100.0);
	Position circuitoizq1_11(10500.0, 11000.0, 2100.0);
	Position circuitoizq1_12(13500.0, 11000.0, 1400.0);

	//Puntos que definen un circuito hexagonal en sentido horario en el cuadrante lateral izquierdo.
	Position circuitoizq2_1(5500.0, 16000.0, 3500.0);
	Position circuitoizq2_2(8500.0, 14500.0, 3500.0);
	Position circuitoizq2_3(8500.0, 11500.0, 3500.0);
	Position circuitoizq2_4(5500.0, 10000.0, 3500.0);
	Position circuitoizq2_5(2500.0, 11500.0, 3500.0);
	Position circuitoizq2_6(2500.0, 14500.0, 2800.0);
	Position circuitoizq2_7(5500.0, 16000.0, 2100.0);
	Position circuitoizq2_8(8500.0, 14500.0, 2100.0);
	Position circuitoizq2_9(8500.0, 11500.0, 2100.0);
	Position circuitoizq2_10(5500.0, 10000.0, 2100.0);
	Position circuitoizq2_11(2500.0, 11500.0, 2100.0);
	Position circuitoizq2_12(2500.0, 14500.0, 1400.0);

	//Puntos que definen un circuito hexagonal en sentido horario en el cuadrante central derecho.
	Position circuitoder1_1(15000.0, -8000.0, 3500.0);
	Position circuitoder1_2(13500.0, -5000.0, 3500.0);
	Position circuitoder1_3(10500.0, -5000.0, 3500.0);
	Position circuitoder1_4(9000.0, -8000.0, 3500.0);
	Position circuitoder1_5(10500.0, -11000.0, 3500.0);
	Position circuitoder1_6(13500.0, -11000.0, 2800.0);
	Position circuitoder1_7(15000.0, -8000.0, 2100.0);
	Position circuitoder1_8(13500.0, -5000.0, 2100.0);
	Position circuitoder1_9(10500.0, -5000.0, 2100.0);
	Position circuitoder1_10(9000.0, -8000.0, 2100.0);
	Position circuitoder1_11(10500.0, -11000.0, 2100.0);
	Position circuitoder1_12(13500.0, -11000.0, 1400.0);

	//Puntos que definen un circuito hexagonal en sentido horario en el cuadrante lateral derecho.
	Position circuitoder2_1(5500.0, -16000.0, 3500.0);
	Position circuitoder2_2(8500.0, -14500.0, 3500.0);
	Position circuitoder2_3(8500.0, -11500.0, 3500.0);
	Position circuitoder2_4(5500.0, -10000.0, 3500.0);
	Position circuitoder2_5(2500.0, -11500.0, 3500.0);
	Position circuitoder2_6(2500.0, -14500.0, 2800.0);
	Position circuitoder2_7(5500.0, -16000.0, 2100.0);
	Position circuitoder2_8(8500.0, -14500.0, 2100.0);
	Position circuitoder2_9(8500.0, -11500.0, 2100.0);
	Position circuitoder2_10(5500.0, -10000.0, 2100.0);
	Position circuitoder2_11(2500.0, -11500.0, 2100.0);
	Position circuitoder2_12(2500.0, -14500.0, 1400.0);

	//Puntos de control por los que pasar para aterrizar.
	/*Position pos_aterrizajeizq_1(6000.0, 5000.0, 100.0);
	Position pos_aterrizajeizq_2(3500.0, 10000.0, 100.0);
	Position pos_aterrizajeder_1(6000.0, -5000.0, 100.0);
	Position pos_aterrizajeder_2(3500.0, -10000.0, 100.0);
*/
	Position pos_aterrizaje_1(2500.0, 0.0, 100.0);
	Position pos_aterrizaje_2(1000.0, 0.0, 50.0);
	Position pos_aterrizaje_3(200.0, 0.0, 25.0);
	Position pos_aterrizaje_4(-750.0, 0.0, 25.0);

	Route r_aterr1, r_aterr2, r_aterr3, r_aterr4;

	Route r_aterr_izq1_1, r_aterr_izq1_2, r_aterr_izq1_3, r_aterr_izq1_4;
	Route r_aterr_izq2_1, r_aterr_izq2_2, r_aterr_izq2_3, r_aterr_izq2_4;

	Route r_aterr_der1_1, r_aterr_der1_2, r_aterr_der1_3, r_aterr_der1_4;
	Route r_aterr_der2_1, r_aterr_der2_2, r_aterr_der2_3, r_aterr_der2_4;

	Route r_circ_izq1_1, r_circ_izq1_2, r_circ_izq1_3, r_circ_izq1_4, r_circ_izq1_5, r_circ_izq1_6;
	Route r_circ_izq1_7, r_circ_izq1_8, r_circ_izq1_9, r_circ_izq1_10, r_circ_izq1_11, r_circ_izq1_12;

	Route r_circ_izq2_1, r_circ_izq2_2, r_circ_izq2_3, r_circ_izq2_4, r_circ_izq2_5, r_circ_izq2_6;
	Route r_circ_izq2_7, r_circ_izq2_8, r_circ_izq2_9, r_circ_izq2_10, r_circ_izq2_11, r_circ_izq2_12;

	Route r_circ_der1_1, r_circ_der1_2, r_circ_der1_3, r_circ_der1_4, r_circ_der1_5, r_circ_der1_6;
	Route r_circ_der1_7, r_circ_der1_8, r_circ_der1_9, r_circ_der1_10, r_circ_der1_11, r_circ_der1_12;

	Route r_circ_der2_1, r_circ_der2_2, r_circ_der2_3, r_circ_der2_4, r_circ_der2_5, r_circ_der2_6;
	Route r_circ_der2_7, r_circ_der2_8, r_circ_der2_9, r_circ_der2_10, r_circ_der2_11, r_circ_der2_12;

	r_aterr1.pos = pos_aterrizaje_1;
	r_aterr1.speed = 200.0;
	r_aterr2.pos = pos_aterrizaje_2;
	r_aterr2.speed = 100.0;
	r_aterr3.pos = pos_aterrizaje_3;
	r_aterr3.speed = 40.0;
	r_aterr4.pos = pos_aterrizaje_4;
	r_aterr4.speed = 19.0;
/*
	r_aterr_izq1_1.pos = pos_aterrizajeizq_1;
	r_aterr_izq1_2.speed = 200.0;
	r_aterr_izq1_2.pos = pos_aterrizaje_2;
	r_aterr_izq1_3.speed = 100.0;
	r_aterr_izq1_3.pos = pos_aterrizaje_3;
	r_aterr_izq1_3.speed = 40.0;
	r_aterr_izq1_4.pos = pos_aterrizaje_4;
	r_aterr_izq1_4.speed = 19.0;

	r_aterr_izq2_1.pos = pos_aterrizajeizq_2;
	r_aterr_izq2_2.speed = 200.0;
	r_aterr_izq2_2.pos = pos_aterrizaje_2;
	r_aterr_izq2_3.speed = 100.0;
	r_aterr_izq2_3.pos = pos_aterrizaje_3;
	r_aterr_izq2_3.speed = 40.0;
	r_aterr_izq2_4.pos = pos_aterrizaje_4;
	r_aterr_izq2_4.speed = 19.0;

	r_aterr_der1_1.pos = pos_aterrizajeder_1;
	r_aterr_der1_2.speed = 200.0;
	r_aterr_der1_2.pos = pos_aterrizaje_2;
	r_aterr_der1_3.speed = 100.0;
	r_aterr_der1_3.pos = pos_aterrizaje_3;
	r_aterr_der1_3.speed = 40.0;
	r_aterr_der1_4.pos = pos_aterrizaje_4;
	r_aterr_der1_4.speed = 19.0;

	r_aterr_der2_1.pos = pos_aterrizajeder_2;
	r_aterr_der2_2.speed = 200.0;
	r_aterr_der2_2.pos = pos_aterrizaje_2;
	r_aterr_der2_3.speed = 100.0;
	r_aterr_der2_3.pos = pos_aterrizaje_3;
	r_aterr_der2_3.speed = 40.0;
	r_aterr_der2_4.pos = pos_aterrizaje_4;
	r_aterr_der2_4.speed = 19.0;
*/
	//Circuito de espera central izquierdo.
	r_circ_izq1_1.pos = circuitoizq1_1;
	r_circ_izq1_1.speed = 250.0;
	r_circ_izq1_2.pos = circuitoizq1_2;
	r_circ_izq1_2.speed = 250.0;
	r_circ_izq1_3.pos = circuitoizq1_3;
	r_circ_izq1_3.speed = 250.0;
	r_circ_izq1_4.pos = circuitoizq1_4;
	r_circ_izq1_4.speed = 250.0;
	r_circ_izq1_5.pos = circuitoizq1_5;
	r_circ_izq1_5.speed = 250.0;
	r_circ_izq1_6.pos = circuitoizq1_6;
	r_circ_izq1_6.speed = 250.0;
	r_circ_izq1_7.pos = circuitoizq1_7;
	r_circ_izq1_7.speed = 250.0;
	r_circ_izq1_8.pos = circuitoizq1_8;
	r_circ_izq1_8.speed = 250.0;
	r_circ_izq1_9.pos = circuitoizq1_9;
	r_circ_izq1_9.speed = 250.0;
	r_circ_izq1_10.pos = circuitoizq1_10;
	r_circ_izq1_10.speed = 250.0;
	r_circ_izq1_11.pos = circuitoizq1_11;
	r_circ_izq1_11.speed = 250.0;
	r_circ_izq1_12.pos = circuitoizq1_12;
	r_circ_izq1_12.speed = 250.0;

	//Circuito de espera lateral izquierdo.
	r_circ_izq2_1.pos = circuitoizq2_1;
	r_circ_izq2_1.speed = 250.0;
	r_circ_izq2_2.pos = circuitoizq2_2;
	r_circ_izq2_2.speed = 250.0;
	r_circ_izq2_3.pos = circuitoizq2_3;
	r_circ_izq2_3.speed = 250.0;
	r_circ_izq2_4.pos = circuitoizq2_4;
	r_circ_izq2_4.speed = 250.0;
	r_circ_izq2_5.pos = circuitoizq2_5;
	r_circ_izq2_5.speed = 250.0;
	r_circ_izq2_6.pos = circuitoizq2_6;
	r_circ_izq2_6.speed = 250.0;
	r_circ_izq2_7.pos = circuitoizq2_7;
	r_circ_izq2_7.speed = 250.0;
	r_circ_izq2_8.pos = circuitoizq2_8;
	r_circ_izq2_8.speed = 250.0;
	r_circ_izq2_9.pos = circuitoizq2_9;
	r_circ_izq2_9.speed = 250.0;
	r_circ_izq2_10.pos = circuitoizq2_10;
	r_circ_izq2_10.speed = 250.0;
	r_circ_izq2_11.pos = circuitoizq2_11;
	r_circ_izq2_11.speed = 250.0;
	r_circ_izq2_12.pos = circuitoizq2_12;
	r_circ_izq2_12.speed = 250.0;

	//Circuito de espera central derecho.
	r_circ_der1_1.pos = circuitoder1_1;
	r_circ_der1_1.speed = 250.0;
	r_circ_der1_2.pos = circuitoder1_2;
	r_circ_der1_2.speed = 250.0;
	r_circ_der1_3.pos = circuitoder1_3;
	r_circ_der1_3.speed = 250.0;
	r_circ_der1_4.pos = circuitoder1_4;
	r_circ_der1_4.speed = 250.0;
	r_circ_der1_5.pos = circuitoder1_5;
	r_circ_der1_5.speed = 250.0;
	r_circ_der1_6.pos = circuitoder1_6;
	r_circ_der1_6.speed = 250.0;
	r_circ_der1_7.pos = circuitoder1_7;
	r_circ_der1_7.speed = 250.0;
	r_circ_der1_8.pos = circuitoder1_8;
	r_circ_der1_8.speed = 250.0;
	r_circ_der1_9.pos = circuitoder1_9;
	r_circ_der1_9.speed = 250.0;
	r_circ_der1_10.pos = circuitoder1_10;
	r_circ_der1_10.speed = 250.0;
	r_circ_der1_11.pos = circuitoder1_11;
	r_circ_der1_11.speed = 250.0;
	r_circ_der1_12.pos = circuitoder1_12;
	r_circ_der1_12.speed = 250.0;

	//Circuito de espera lateral derecho.
	r_circ_der1_1.pos = circuitoder2_1;
	r_circ_der1_1.speed = 250.0;
	r_circ_der1_2.pos = circuitoder2_2;
	r_circ_der1_2.speed = 250.0;
	r_circ_der1_3.pos = circuitoder2_3;
	r_circ_der1_3.speed = 250.0;
	r_circ_der1_4.pos = circuitoder2_4;
	r_circ_der1_4.speed = 250.0;
	r_circ_der1_5.pos = circuitoder2_5;
	r_circ_der1_5.speed = 250.0;
	r_circ_der1_6.pos = circuitoder2_6;
	r_circ_der1_6.speed = 250.0;
	r_circ_der1_7.pos = circuitoder2_7;
	r_circ_der1_7.speed = 250.0;
	r_circ_der1_8.pos = circuitoder2_8;
	r_circ_der1_8.speed = 250.0;
	r_circ_der1_9.pos = circuitoder2_9;
	r_circ_der1_9.speed = 250.0;
	r_circ_der1_10.pos = circuitoder2_10;
	r_circ_der1_10.speed = 250.0;
	r_circ_der1_11.pos = circuitoder2_11;
	r_circ_der1_11.speed = 250.0;
	r_circ_der1_12.pos = circuitoder2_12;
	r_circ_der1_12.speed = 250.0;

	if(!Airport::getInstance() -> is_booked_landing())
	{
		Flight* primero = *(flights.begin());

		primero -> getRoute() -> clear();
	}

	for(it = flights.begin(); it!=flights.end(); ++it)
	{
		if((*it)->getRoute()->empty())
		{
			if ((((*it) -> getPosition().get_y()) > 0) && (((*it) -> getPosition().get_y()) < ((*it) -> getPosition().get_x())))
			{
				if (Airport::getInstance() -> is_booked_landing())
				{
					if(((*it) -> getPosition().get_y()) > 16000)
					{
						(*it)->getRoute()->push_back(r_circ_izq1_2);
						(*it)->getRoute()->push_back(r_circ_izq1_3);
						(*it)->getRoute()->push_back(r_circ_izq1_4);
						(*it)->getRoute()->push_back(r_circ_izq1_5);
						(*it)->getRoute()->push_back(r_circ_izq1_6);
						(*it)->getRoute()->push_back(r_circ_izq1_7);
						(*it)->getRoute()->push_back(r_circ_izq1_8);
						(*it)->getRoute()->push_back(r_circ_izq1_9);
						(*it)->getRoute()->push_back(r_circ_izq1_10);
						(*it)->getRoute()->push_back(r_circ_izq1_11);
						(*it)->getRoute()->push_back(r_circ_izq1_12);
					}
					else
					{
						(*it)->getRoute()->push_back(r_circ_izq1_1);
						(*it)->getRoute()->push_back(r_circ_izq1_2);
						(*it)->getRoute()->push_back(r_circ_izq1_3);
						(*it)->getRoute()->push_back(r_circ_izq1_4);
						(*it)->getRoute()->push_back(r_circ_izq1_5);
						(*it)->getRoute()->push_back(r_circ_izq1_6);
						(*it)->getRoute()->push_back(r_circ_izq1_7);
						(*it)->getRoute()->push_back(r_circ_izq1_8);
						(*it)->getRoute()->push_back(r_circ_izq1_9);
						(*it)->getRoute()->push_back(r_circ_izq1_10);
						(*it)->getRoute()->push_back(r_circ_izq1_11);
						(*it)->getRoute()->push_back(r_circ_izq1_12);
					}
				}
				else
				{
					Airport::getInstance() -> book_landing();
					(*it)->getRoute()->push_back(r_aterr1);
					(*it)->getRoute()->push_back(r_aterr2);
					(*it)->getRoute()->push_back(r_aterr3);
					(*it)->getRoute()->push_back(r_aterr4);
				}
			}
			else if ((((*it) -> getPosition().get_y()) > 0) && (((*it) -> getPosition().get_y()) > ((*it) -> getPosition().get_x())))
			{
				if (Airport::getInstance() -> is_booked_landing())
				{
					if(((*it) -> getPosition().get_x()) < 5500)
					{
						(*it)->getRoute()->push_back(r_circ_izq2_1);
						(*it)->getRoute()->push_back(r_circ_izq2_2);
						(*it)->getRoute()->push_back(r_circ_izq2_3);
						(*it)->getRoute()->push_back(r_circ_izq2_4);
						(*it)->getRoute()->push_back(r_circ_izq2_5);
						(*it)->getRoute()->push_back(r_circ_izq2_6);
						(*it)->getRoute()->push_back(r_circ_izq2_7);
						(*it)->getRoute()->push_back(r_circ_izq2_8);
						(*it)->getRoute()->push_back(r_circ_izq2_9);
						(*it)->getRoute()->push_back(r_circ_izq2_10);
						(*it)->getRoute()->push_back(r_circ_izq2_11);
						(*it)->getRoute()->push_back(r_circ_izq2_12);
					}
					else
					{
						(*it)->getRoute()->push_back(r_circ_izq2_2);
						(*it)->getRoute()->push_back(r_circ_izq2_3);
						(*it)->getRoute()->push_back(r_circ_izq2_4);
						(*it)->getRoute()->push_back(r_circ_izq2_5);
						(*it)->getRoute()->push_back(r_circ_izq2_6);
						(*it)->getRoute()->push_back(r_circ_izq2_7);
						(*it)->getRoute()->push_back(r_circ_izq2_8);
						(*it)->getRoute()->push_back(r_circ_izq2_9);
						(*it)->getRoute()->push_back(r_circ_izq2_10);
						(*it)->getRoute()->push_back(r_circ_izq2_11);
						(*it)->getRoute()->push_back(r_circ_izq2_12);
					}
				}
				else
				{
					Airport::getInstance() -> book_landing();
					(*it)->getRoute()->push_back(r_aterr1);
					(*it)->getRoute()->push_back(r_aterr2);
					(*it)->getRoute()->push_back(r_aterr3);
					(*it)->getRoute()->push_back(r_aterr4);
				}
			}
			else if ((((*it) -> getPosition().get_y()) < 0) && (abs(((*it) -> getPosition().get_y())) > ((*it) -> getPosition().get_x())))
			{
				if (Airport::getInstance() -> is_booked_landing())
				{
					if (abs(((*it) -> getPosition().get_y())) > 16000)
					{
						(*it)->getRoute()->push_back(r_circ_der1_2);
						(*it)->getRoute()->push_back(r_circ_der1_3);
						(*it)->getRoute()->push_back(r_circ_der1_4);
						(*it)->getRoute()->push_back(r_circ_der1_5);
						(*it)->getRoute()->push_back(r_circ_der1_6);
						(*it)->getRoute()->push_back(r_circ_der1_7);
						(*it)->getRoute()->push_back(r_circ_der1_8);
						(*it)->getRoute()->push_back(r_circ_der1_9);
						(*it)->getRoute()->push_back(r_circ_der1_10);
						(*it)->getRoute()->push_back(r_circ_der1_11);
						(*it)->getRoute()->push_back(r_circ_der1_12);
					}
					else
					{
						(*it)->getRoute()->push_back(r_circ_der1_1);
						(*it)->getRoute()->push_back(r_circ_der1_3);
						(*it)->getRoute()->push_back(r_circ_der1_4);
						(*it)->getRoute()->push_back(r_circ_der1_5);
						(*it)->getRoute()->push_back(r_circ_der1_6);
						(*it)->getRoute()->push_back(r_circ_der1_7);
						(*it)->getRoute()->push_back(r_circ_der1_8);
						(*it)->getRoute()->push_back(r_circ_der1_9);
						(*it)->getRoute()->push_back(r_circ_der1_10);
						(*it)->getRoute()->push_back(r_circ_der1_11);
						(*it)->getRoute()->push_back(r_circ_der1_12);
					}
				}
				else
				{
					Airport::getInstance()-> book_landing();
					(*it)->getRoute()->push_back(r_aterr1);
					(*it)->getRoute()->push_back(r_aterr2);
					(*it)->getRoute()->push_back(r_aterr3);
					(*it)->getRoute()->push_back(r_aterr4);
				}
			}
			else if ((((*it) -> getPosition().get_y()) < 0) && (abs((*it) -> getPosition().get_y()) < ((*it) -> getPosition().get_x())))
			{
				if (Airport::getInstance() -> is_booked_landing())
				{
					if(((*it) -> getPosition().get_x()) > 5500)
					{
						(*it)->getRoute()->push_back(r_circ_der2_2);
						(*it)->getRoute()->push_back(r_circ_der2_3);
						(*it)->getRoute()->push_back(r_circ_der2_4);
						(*it)->getRoute()->push_back(r_circ_der2_5);
						(*it)->getRoute()->push_back(r_circ_der2_6);
						(*it)->getRoute()->push_back(r_circ_der2_7);
						(*it)->getRoute()->push_back(r_circ_der2_8);
						(*it)->getRoute()->push_back(r_circ_der2_9);
						(*it)->getRoute()->push_back(r_circ_der2_10);
						(*it)->getRoute()->push_back(r_circ_der2_11);
						(*it)->getRoute()->push_back(r_circ_der2_12);
					}
					else
					{
						(*it)->getRoute()->push_back(r_circ_der2_1);
						(*it)->getRoute()->push_back(r_circ_der2_3);
						(*it)->getRoute()->push_back(r_circ_der2_4);
						(*it)->getRoute()->push_back(r_circ_der2_5);
						(*it)->getRoute()->push_back(r_circ_der2_6);
						(*it)->getRoute()->push_back(r_circ_der2_7);
						(*it)->getRoute()->push_back(r_circ_der2_8);
						(*it)->getRoute()->push_back(r_circ_der2_9);
						(*it)->getRoute()->push_back(r_circ_der2_10);
						(*it)->getRoute()->push_back(r_circ_der2_11);
						(*it)->getRoute()->push_back(r_circ_der2_12);
					}
				}
				else
				{
					Airport::getInstance()-> book_landing();
					(*it)->getRoute()->push_back(r_aterr1);
					(*it)->getRoute()->push_back(r_aterr2);
					(*it)->getRoute()->push_back(r_aterr3);
					(*it)->getRoute()->push_back(r_aterr4);
				}
			}
		}
	}
}
