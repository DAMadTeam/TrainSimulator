class TrackSeg;

class Node
{

private:
    Coordinates position;
    TrackSeg *tracks[4];
    unsigned char state;

public:
    Node() = delete;
    Node(TrackSeg*);
    ~Node() = default;                                  //изменить


    int AddTrackSeg(TrackSeg*, bool);
    void RemoveSeg(unsigned char);
    void shiftCart(TrackSeg*&, bool&, unsigned char);
};

#include "Node.cpp"