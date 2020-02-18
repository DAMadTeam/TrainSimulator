#ifndef TRAINMOVEMENTS_HPP
#define TRAINMOVEMENTS_HPP

#include "Train.hpp"
#include <math>

double getDistanceToEnd(Coordinates point, TrackSeg track, bool direction){
    if (track.tellType() == 'l'){
    	Coordinates* fwd = new Coordinates;
        Coordinates* bck = new Coordinates;
        track.readParamsAsLinear(fwd, bck);

        if (direction) return sqrt( (point.x - fwd.x)*(point.x - fwd.x) + (point.y - fwd.y)*(point.y - fwd.y) + (point.z - fwd.z)*(point.z - fwd.z) );
        return sqrt( (point.x - bck.x)*(point.x - bck.x) + (point.y - bck.y)*(point.y - bck.y) + (point.z - bck.z)*(point.z - bck.z) );
    }
    return -1;
}

void moveTruck(Truck* truck, double speed, bool direction){ //Здесь скорость - смещение за один тик. Один вызов функции - один тик
    double DTE = getDistanceToEnd(*(truck->getCoordinates()), *(truck->getTrack()), direction);

    if (DTE > speed){ //Если за один тик не выезжаем с сегмента пути, то едем спокойно
        
    	if (truck->getTrack->tellType() == 'l'){ //Работаем как с отрезком
			Coordinates* fwd = new Coordinates;
        	Coordinates* bck = new Coordinates;
        	truck->getTrack->readParamsAsLinear(fwd, bck);

    	}else{ //Пока только отрезки и дуги, поэтому работаем как с дугой

    	} 

    }else{ //Если за один тик переходим с одного сегмента на другой, то описываем логику
     	truck->getTrack->ShiftCart(truck->getTrack, direction); //Сомнительно выглядит. Сломается или нет зависит от реализации метода.
       	moveTruck(truck, speed - DTE, direction); // Здесь (speed-DTE) - это расстояние, которое нужно проехать по оставшемуся участку пути за тик.
       	//Есть вопросы по направлению движения. Не очень понятно как географически определяются точки входа-выхода путей.
    }
}

void moveTrainCar(TrainCar* trainCar, bool direction){ //Вагон стоит на двух тележках. Здесь двигаем две тележки вагона. Применимо для локомотивов. 
	Truck* firstTruck = new Truck;
	Truck* lastTruck = new Truck;
	trainCar->getTrucks(firstTruck, lastTruck);

	moveTruck(firstTruck, trainCar->getLen(), direction); 
	moveTruck(lastTruck, trainCar->getLen(), direction); // Не особо классный вариант перемещения второй тележки(могут быть погрешности). Хорошо бы относительно первой перемещать.
}

void moveTrain(Train* train); //Пока как вариант сдвигаться за один тик на длину вагона + погрешность на дугах.
//При таком раскладе можно отдавать координаты тележек вагонов назад по списку. Сильно уменьшает сложность вычислений.
//Скорость в итоге конвертируется в вагоны/секунду

#endif