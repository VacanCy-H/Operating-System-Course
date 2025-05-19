#ifndef UTILS_H
#define UTILS_H

#include <deque>
#include "pcb.h"

void init_queues(std::deque<PCB*>& RQ1, std::deque<PCB*>& RQ2);
void print_results(const std::deque<PCB*>& Finish);

#endif
