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
    void shiftCart(TrackSeg*&, char);
};

Node::Node(TrackSeg* track)                             //доделать
{
    state = 0;
    tracks[0] = track;
    tracks[1] = 0;
    tracks[2] = 0;
    tracks[3] = 0;
}

void Node::shiftCart(TrackSeg *&new_seg, char source_seg_id)
{
    if((state >> 6) == 0)                                       //тупик
    {
        
    }
}
