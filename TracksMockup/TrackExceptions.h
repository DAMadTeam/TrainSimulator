class RRT_DeadEnd_OverRun : public std::exception
{
    const char *what() const noexcept override
    {
        return "001";
    }
};

class RRT_Bad_TransferNode : public std::exception
{
    const chat *what() const noexcept override
    {
        return "002";
    }
};