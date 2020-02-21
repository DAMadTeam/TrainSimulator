class RRT_DeadEnd_OverRun : public std::exception
{
    const char *what() const noexcept override
    {
        return "001";
    }
};

class RRT_Bad_TransferNode : public std::exception
{
    const char *what() const noexcept override
    {
        return "002";
    }
};

class RRT_Bad_Switch : public std::exception
{
    const char *what() const noexcept override
    {
        return "003";
    }
};

class RRT_Bad_Switch_Branch : public std::exception
{
    const char *what() const noexcept override
    {
        return "004";
    }
};

class RRT_Bad_Crossing : public std::exception
{
    const char *what() const noexcept override
    {
        return "005";
    }
};