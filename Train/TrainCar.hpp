#ifndef TRAINCAR_HPP
#define TRAINCAR_HPP

#include "../Positioning/Coordinates.hpp"
#include "../TracksMockup/TrackSeg.h"
#include "TrainMath.hpp"

class TrainCar{
private:
	bool locomotive;
	TrainCar* next = nullptr; //Типа сцепка
	TrainCar* previous = nullptr; 
	Coordinates firstTruckCoordinates; //Координаты центра передних катков
	Coordinates lastTruckCoordinates;
	TrackSeg* track;
	int len; //Длина вагона со сцепкой
	int truckOffset; //Отступ от сцепки до телеги

public:
	TrainCar(bool isLocomotive, TrackSeg* track, Coordinates firstTruckCoordinates, Coordinates lastTruckCoordinates){ //Вагон с координатами, остаётся только прицепить
		this->locomotive = isLocomotive;
		this->track = track;
		this->firstTruckCoordinates = firstTruckCoordinates;
		this->lastTruckCoordinates = lastTruckCoordinates;
	}

	TrainCar(bool isLocomotive, TrackSeg* track){ //Просто вагон без координат(вдруг понадобится)
		this->locomotive = isLocomotive;
		this->track = track;
	}

	bool isLocomotive(){
		return locomotive;
	}

	void setNext(TrainCar* pointer) return; //Цепляем вагоны
	void setPrevious(TrainCar* pointer) return; //



}

#endif