#ifndef JOB_H
#define JOB_H

#include <string>

struct Job {
    std::string id; // Job Id
    int deadline;   // Deadline of job
    int profit;     // Profit if job is over before or on deadline

    Job() {}
    Job(std::string id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {}
};

#endif // JOB_H