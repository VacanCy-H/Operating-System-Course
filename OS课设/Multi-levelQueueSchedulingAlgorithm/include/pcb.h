#ifndef PCB_H
#define PCB_H
#include<string>

struct PCB {
    std::string name;
    int need_time;
    int remain_time;
    int wait_time;
    int run_count = 0;
    int turnaround = 0;

    PCB(std::string n, int nt, int rt, int wt) 
        : name(n), need_time(nt), remain_time(rt), wait_time(wt),
             run_count(0), turnaround(0) {}
};

#endif
