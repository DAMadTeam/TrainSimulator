#pragma once

#include "../GlobalIncludes.h"

#include "TrackExceptions.h"
#include "Node.h"
#include "TrackShape.h"

class TrackSeg
{
private:
    TrackShape *shape;
    Node *fwd, *bck;
    unsigned char fwd_id, bck_id;

public:
    TrackSeg() = delete;
    TrackSeg(TrackShape*);
    ~TrackSeg() = default;                                      //исправить

    void ShiftCart(TrackSeg*&, bool&);
    char tellType();
    void readParamsAsLinear(Coordinates&, Coordinates&);
    void readParamsAsCircular(Coordinates&, double&, double&, double&);     //центр окр-ти, радиус, азимут 1 (bck), азимут 2 (fwd), ход против частовой от направления на восток
};

void TrackSeg::ShiftCart(TrackSeg *&next_seg, bool &direction)
{
    if(direction)
    {
        bck->shiftCart(next_seg, direction, bck_id);
    }
    else
    {
        fwd->shiftCart(next_seg, direction, fwd_id);
    }
}