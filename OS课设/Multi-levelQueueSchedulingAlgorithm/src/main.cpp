#include "scheduler.h"
#include "utils.h"
#include <deque>

int main() {
    std::deque<PCB*> RQ1, RQ2, RQ3, Finish;
    int global_clock = 0;

    init_queues(RQ1, RQ2);
    process_RQ1(RQ1, RQ2, Finish, global_clock);
    process_RQ2(RQ2, RQ3, Finish, global_clock);
    process_RQ3(RQ3, Finish, global_clock);
    print_results(Finish);

    return 0;
}
