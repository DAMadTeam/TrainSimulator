class RRT_DeadEnd_OverRun : public std::exception
{
    const char *what() const noexcept override
    {
        return "000";
    }
};