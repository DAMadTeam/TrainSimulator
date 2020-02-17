class TrackShape
{
public:
    TrackShape() = delete;
    virtual ~TrackShape() = default;

    virtual char tellType() = 0;
};

class TrackLinear : public TrackShape
{
private:
    Coordinates forward, back;

public:
    TrackLinear() = delete;
    TrackLinear(Coordinates&, Coordinates&);
    ~TrackLinear() = default;                               //��������

    char tellType() override;
    void readParams(Coordinates&, Coordinates&);            //��������� ���������� �� ������ ���������� ������ �������, ��� �� ����������� �����, ����� ������������ �� TrackLinear!
};

class TrackCircular : public TrackShape
{
private:
    Coordinates centre;
    double radius;
    double az1, az2;

public:
    TrackCircular() = delete;
    TrackCircular(Coordinates&, double, double, double);
    ~TrackCircular() = default;                             //��������

    char tellType() override;
    void readParams(Coordinates&, double, double, double);  //��������� ���������� �� ������ ���������� ������ �������, ��� �� ����������� �����, ����� ������������ �� TrackCircular!
};

#include "TrackShape.cpp"