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
    ~TrackLinear() = default;                               //изменить

    char tellType() override;
    void readParams(Coordinates&, Coordinates&);            //заполняет переданные по ссылке координаты своими концами, это не виртуальный метод, нужно разыменовать до TrackLinear!
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
    ~TrackCircular() = default;                             //изменить

    char tellType() override;
    void readParams(Coordinates&, double, double, double);  //заполняет переданные по ссылке координаты своими концами, это не виртуальный метод, нужно разыменовать до TrackCircular!
};

#include "TrackShape.cpp"