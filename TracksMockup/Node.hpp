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
};

Node::Node(TrackSeg* track)
{
    state = 0;
    tracks[0] = track;
    tracks[1] = 0;
    tracks[2] = 0;
    tracks[3] = 0;
}