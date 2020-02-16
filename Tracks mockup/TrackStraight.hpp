class TrackStraight : public TrackSeg
{
private:
    Coordinates fwd_coord, bck_coord;

public:
    TrackStraight() = delete;
    TrackStraight(Coordinates, Coordinates, Node* = 0, Node* = 0);

    void GetCartPos(double, Coordinates&, TrackSeg*&, double&) override;
};

TrackStraight::TrackStraight(Coordinates fwd_coord, Coordinates bck_coord, Node *fwd, Node *bck)
{
    this->bck_coord = bck_coord;
    this->fwd_coord = fwd_coord;
}
