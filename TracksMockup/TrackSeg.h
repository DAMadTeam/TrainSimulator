class Coordinates               //placeholder
{
public:
    double x, y, z;
};

#include "Node.hpp"

class TrackSeg
{
private:
    double length;
    Node *fwd, *bck;
    char fwd_id, bck_id;

public:
    virtual void GetCartPos(double&, Coordinates&, TrackSeg*&, bool&) = 0;              //gives coordinates of cart based on offset and tells it
                                                                                //the segment it is now on, if it has passed the current one
};

#include "TrackStraight.hpp"