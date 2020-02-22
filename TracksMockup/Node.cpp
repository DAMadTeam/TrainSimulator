Node::Node(TrackSeg* track)                             //изменить
{
    state = 0;
    tracks[0] = track;
    tracks[1] = 0;
    tracks[2] = 0;
    tracks[3] = 0;
}

void Node::shiftCart(TrackSeg *&new_seg, bool &direction, unsigned char source_seg_id)
{
    if((state >> 6) == 0)                                       //тупик 00D- ----
    {
        throw RRT_DeadEnd_OverRun();
    }
    else if((state >> 6) == 1)                                  //сквозной узел 01DD ----
    {
        unsigned char i = 0;
        unsigned char n = 0;
        while(i != 255)
        {
            if(i == 4)
            {
                new_seg = 0;
                throw RRT_Bad_TransferNode();
            }
            if(tracks[i])
            {
                if(i == source_seg_id)
                {
                    i++;
                    n++;
                }
                else
                {
                    new_seg = tracks[i];
                    direction = state & (32 >> n);              //32 = 0010 0000b
                    i = 255;                                    //     01DD ----
                }
            }
            else
            {
                i++;
            }
        }
    }
    else if((state >> 6) == 2)                                  //стрелка 10DD DRRS
    {
        unsigned char root_id = (state & 6) >> 2;               //6 = 0000 0110b
        if(source_seg_id == root_id)
        {
            unsigned char i = 0;
            unsigned char n = 0;
            bool pass_next_branch = state & 1;                  //1 = 0000 0001b
            while(i != 255)
            {
                if(i == 4)
                {
                    new_seg = 0;
                    throw RRT_Bad_Switch();
                }
                else if(tracks[i])
                {
                    if(i == root_id)
                    {
                        i++;
                        n++;
                    }
                    else if(pass_next_branch)
                    {
                        i++;
                        n++;
                        pass_next_branch = 0;
                    }
                    else
                    {
                        new_seg = tracks[i];
                        direction = state & (32 >> n);          //32 = 0010 0000b
                        i = 255;                                //     10DD DRRS
                    }
                }
                else
                {
                    i++;
                }
            }
        }
        else //if(source_seg_id != root_id)
        {
            bool source_is_second_branch = (source_seg_id == 3) + (source_seg_id == 2) * ((root_id == 3) + (tracks[3] == 0)) + 
                            (source_seg_id == 1) * (tracks[0] != 0) * (root_id != 0);
            unsigned char i = 0;
            unsigned char n = 0;
            while(i != 255)
            {
                if(i == 4)
                {
                    new_seg = 0;
                    throw RRT_Bad_Switch();
                }
                else if(tracks[i])
                {
                    if(i == root_id)
                    {
                        i == 255;
                    }
                    else
                    {
                        i++;
                        n++;
                    }
                }
                else
                {
                    i++;
                }
            }
            new_seg = tracks[root_id];
            direction = state & (32 >> n);
            if(source_is_second_branch != (state & 1))          //переделать - нехер исключением передавать чатсь допустимых* исходов
            {
                throw RRT_Bad_Switch_Branch();
            }
        }
    }
    else //if ((state >> 6) == 3)                               //перекрёсток 11DD DDCC
    {
        unsigned char n;
        if(source_seg_id == 0)
        {
            n = state & 3;
        }
        else if(source_seg_id == (state & 3))
        {
            n = 0;
        }
        else if(source_seg_id == 1)
        {
            if((state & 3) == 2)
            {
                n = 3;
            }
            else //if((state & 3) == 3)
            {
                n = 2;
            }
        }
        else if(source_seg_id == 2)
        {
            if((state & 3) == 1)
            {
                n = 3;
            }
            else //if((state & 3) == 3)
            {
                n = 1;
            }
        }
        else //if(source_seg_id == 3)
        {
            if((state & 3) == 1)
            {
                n = 2;
            }
            else //if((state & 3) == 2)
            {
                n = 1;
            }
        }
        new_seg = tracks[n];
        if(new_seg)
        {
            direction = state & (32 >> n);
        }
        else
        {
            throw RRT_Bad_Crossing();
        } 
    }
}
