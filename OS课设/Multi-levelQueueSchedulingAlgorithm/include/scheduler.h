#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <deque>
#include "pcb.h"

void process_RQ1(std::deque<PCB*>& RQ1, std::deque<PCB*>& RQ2, std::deque<PCB*>& Finish, int& global_clock);
void process_RQ2(std::deque<PCB*>& RQ2, std::deque<PCB*>& RQ3, std::deque<PCB*>& Finish, int& global_clock);
void process_RQ3(std::deque<PCB*>& RQ3, std::deque<PCB*>& Finish, int& global_clock);

#endif
