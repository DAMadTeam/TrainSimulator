class TrainCar{
private:
	bool locomotive;
	TrainCar* next;
	TrainCar* previous;	


public:
	TrainCar(bool isLocomotive){
		this->locomotive = isLocomotive;
		this->next = nullptr;
		this->previous = nullptr;
	}

	bool isLocomotive(){
		return locomotive;
	}

	void setNext(TrainCar* pointer) return;
	void setPrevious(TrainCar* pointer) return;

}