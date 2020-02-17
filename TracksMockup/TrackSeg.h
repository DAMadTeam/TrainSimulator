#pragma once

#include "../GlobalIncludes.h"

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
    
};