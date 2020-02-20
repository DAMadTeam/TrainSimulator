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
    void shiftCart(TrackSeg*&, unsigned char);
};

Node::Node(TrackSeg* track)                             //изменить
{
    state = 0;
    tracks[0] = track;
    tracks[1] = 0;
    tracks[2] = 0;
    tracks[3] = 0;
}

void Node::shiftCart(TrackSeg *&new_seg, bool &direction, unsigned char source_seg_id)
{
    if((state >> 6) == 0)                                       //тупик 00X-----
    {
        throw RRT_DeadEnd_OverRun();
    }
    else if((state >> 6) == 1)                                  //сквозной узел
    {
        char i = 0;
        while(i != -1)
        {
            if(i == 4)
            {
                i = -1;
                new_seg = 0;
                throw RRT_Bad_TransferNode();
            }
            else if((i != source_seg_id) * (tracks[i]))
            {
                new_seg = tracks[i];
                direction = state & 32;                         //32 = 00100000b
                i = -1;
            }
            else
            {
                i++;
            }
        }
    }
    else if((state >> 6) == 2)                                  //стрелка
    {

    }
}
