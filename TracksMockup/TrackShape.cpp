char TrackLinear::tellType()
{
    return 0;
}

char TrackCircular::tellType()
{
    return 1;
}

void TrackLinear::readParams(Coordinates &back, Coordinates &forward)
{
    back = this->back;
    forward = this->forward;
}

void TrackCircular::readParams(Coordinates &centre, double &radius, double &az_back, double &az_forward)
{
    centre = this->centre;
    radius = this->radius;
    az_back = this->az_back;
    az_forward = this->az_forward;
}