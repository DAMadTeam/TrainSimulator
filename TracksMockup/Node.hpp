class TrackSeg;

class Node
{

private:
    Coordinates position;
    TrackSeg *tracks[4];
    unsigned char state;

public:
    Node() = delete;
    Node(TrackSeg*);                                //Каждый узел рождается тупиком, становяс на bck участка пути

    int AddTrackSeg(TrackSeg*, bool);               //Проверка допустимости добавления тут будет, скорее всего, цепляется fwd/bck (bool) переданного участка и возвращает его лкоальный индекс
    void RemoveSeg(unsigned char);                  //Участок пути с переданным индексом будет отцеплен
};

Node::Node(TrackSeg* track)
{
    state = 0;
    tracks[0] = track;
    tracks[1] = 0;
    tracks[2] = 0;
    tracks[3] = 0;
}