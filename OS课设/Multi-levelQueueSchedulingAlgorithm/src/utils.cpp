#include "utils.h"
#include <vector>
#include <iostream>

void init_queues(std::deque<PCB*>& RQ1, std::deque<PCB*>& RQ2) {
    // RQ1 初始化
    std::vector<int> rq1_times = {16, 21, 14, 30, 7, 21, 18};
    std::vector<int> rq1_waits = {6, 5, 4, 3, 2, 1, 2};
    for (int i = 0; i < (int)rq1_times.size(); i++) {
        PCB* p = new PCB(
            "P" + std::to_string(i + 1),
            rq1_times[i],
            rq1_times[i],
            rq1_times[i]
        );
        RQ1.push_back(p);
    }

    // RQ2 初始化
    std::vector<int> rq2_times = {10, 27, 14};
    std::vector<int> rq2_waits = {3, 4, 5};
    for (int i = 0; i < (int)rq2_times.size(); i++) {
        PCB* p = new PCB(
            "P" + std::to_string(i + 8),
            rq2_times[i],
            rq2_times[i],
            rq2_waits[i]
        );
        RQ2.push_back(p);
    }
}

void print_results(const std::deque<PCB*>& Finish) {
    std::cout << "进程\t周转时间" << std::endl;
    for (const auto& p : Finish) {
        std::cout << p->name << "\t" << p->turnaround << std::endl;
        delete p;
    }
}
