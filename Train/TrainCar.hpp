#ifndef TRAINCAR_HPP
#define TRAINCAR_HPP

#include "../Positioning/Coordinates.hpp"
#include "../TracksMockup/TrackSeg.h"

class Truck{
private:
	Coordinates* coordinates;
	TrackSeg* track;

public:
	Coordinates* getCoordinates() return this->coordinates;
	TrackSeg* getTrack() return this->track; 
}

class TrainCar{
private:
	bool locomotive;
	TrainCar* next = nullptr; //Типа сцепка
	TrainCar* previous = nullptr; 
	Truck* firstTruck; //Передняя телега
	Truck* lastTruck; //Задняя телега
	double len; //Длина вагона со сцепкой
	double truckOffset; //Отступ от сцепки до телеги
	double mass;

public:
	TrainCar(bool isLocomotive, Truck firstTruck, Truck lastTruck, double mass){ //Вагон с координатами, остаётся только прицепить (Нужно ещё думать по поводу спавна вагонов)
		this->locomotive = isLocomotive;
		this->firstTruck->setCoordinates(firstTruckCoordinates);
		this->lastTruck->setCoordinates(lastTruckCoordinates);
		this->mass = mass;
	}

	bool isLocomotive(){
		return locomotive;
	}

	void getTrucks(Truck* firstTruck, Truck* lastTruck){
		firstTruck = this->firstTruck;
		lastTruck = this->lastTruck;
	}

	void setNext(TrainCar* pointer) return; //Цепляем вагоны
	void setPrevious(TrainCar* pointer) return; //
	void setMass(int mass) this->mass = mass;
	double getMass() return this->mass;
	double getLen() return this->len;


}

#endif