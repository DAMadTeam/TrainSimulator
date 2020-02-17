class RR_DeadEnd_Overrun : public std::exception
{
    const char *what() const noexcept override
    {
        return "A train has tried to pass over a track end";
    }
};