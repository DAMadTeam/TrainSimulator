#pragma once

#include "../GlobalIncludes.h"

#include "TrackExceptions.h"
#include "Node.hpp"
#include "TrackShape.h"

class TrackSeg
{
private:
    TrackShape *shape;
    Node *fwd, *bck;
    char fwd_id, bck_idl;

public:
    TrackSeg() = delete;
    TrackSeg(TrackShape*);
    ~TrackSeg() = default;                                      //изменить

    void ShiftCart(TrackSeg*&, bool&);
    char tellType();
    void readParamsAsLinear(Coordinates&, Coordinates&);
    void readParamsAsCircular(Coordinates&, double&, double&, double&);
};

void TrackSeg::ShiftCart(TrackSeg *&next_seg, bool &direction)
{
    
}