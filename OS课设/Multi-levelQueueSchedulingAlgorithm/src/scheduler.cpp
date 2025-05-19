#include "scheduler.h"
#include <algorithm>

// 对RQ1的处理
void process_RQ1(std::deque<PCB*>& RQ1, std::deque<PCB*>& RQ2, std::deque<PCB*>& Finish, int& global_clock) {
    while (!RQ1.empty()) {
        PCB* curr = RQ1.front();
        RQ1.pop_front();
            
        // 计算第一级队列每个进程的时间 
        int runtime = std::min(curr->remain_time, 4);
        global_clock += runtime;
        curr->remain_time -= runtime;
        curr->run_count++;

        if (curr->remain_time == 0) {
            curr->turnaround = global_clock - curr->wait_time;
            Finish.push_back(curr);
        } else {
            if (curr->run_count < 2) {
                RQ1.push_back(curr);
            } else {
                curr->run_count = 0;
                RQ2.push_back(curr);
            }
        }
    }
}

// 对RQ2的处理
void process_RQ2(std::deque<PCB*>& RQ2, std::deque<PCB*>& RQ3, std::deque<PCB*>& Finish, int& global_clock) {
    while (!RQ2.empty()) {
        PCB* curr = RQ2.front();
        RQ2.pop_front();
        
        // 分配给队列第一个程序该队列等级对应的时间片
        int runtime = std::min(curr->remain_time, 8);
        global_clock += runtime;
        curr->remain_time -= runtime;

        if (curr->remain_time == 0) {
            curr->turnaround = global_clock - curr->wait_time;
            Finish.push_back(curr);
        } else {
            RQ3.push_back(curr);
        }
    }
}

void process_RQ3(std::deque<PCB*>& RQ3, std::deque<PCB*>& Finish, int& global_clock) {
    while (!RQ3.empty()) {
        // 找出RQ3中剩余时间最少的进程，优先处理
        auto it = std::min_element(RQ3.begin(), RQ3.end(), [](PCB* a, PCB* b) {return a->remain_time < b->remain_time;});
        PCB* curr = *it;
        RQ3.erase(it); // 从deque中移除元素

        global_clock += curr->remain_time;
        curr->remain_time = 0;
        curr->turnaround = global_clock - curr->wait_time;
        Finish.push_back(curr);
    }
}
