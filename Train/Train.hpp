#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "../Positioning/Coordinates.hpp"
#include "TrainCar.hpp"

class Train{
private:
    TrainCar* first;
    TrainCar* last;    

public:
	Train(int len){
		TrainCar* locomotive = new TrainCar(true);
		this->first = locomotive;
		this->last = locomotive;

		for (int i = 0; i < len; i++){
			TrainCar* car = new TrainCar(false);
			this->last->setNext(car);
			this->last = car;
		}
	}

	void addCar(TrainCar* ) return;
	void removeCar(int id) return;

	void replaceTrain() return; //Вычисляется новая координата локомотива поезда. Все координаты вагонов передаются дальше по списку (+ поправки для полуокружностей)

}

#endif