extern class TrackSeg;

class Node
{
private:
    Coordinates position;
    TrackSegs (*tracks)[4] = {0};
    unsigned char state;

public:
    Node() = delete;
    Node(TrackSeg*);

    void AddTrackSeg(TrackSeg*);                    //Проверка допустимости добавления тут будет, скорее всего
    void RemoveSeg(unsigned char);                  //Участок пути с переданным индексом будет отцеплен
};