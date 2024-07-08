#include "job-sequencing/JobSequencing.h"
#include "job-sequencing/Job.h"

#include <vector>
#include <algorithm>
#include <map>
#include <memory>
#include <set>

std::vector<std::shared_ptr<Job>> JobSequencing::jobSequencing(int days, std::vector<std::shared_ptr<Job>> jobs) {
    //sort by profit
    std::sort(jobs.begin(), jobs.end(), [days](std::shared_ptr<Job> a, std::shared_ptr<Job> b) {
        if (a->deadline > days || a->deadline < 1)
            throw std::invalid_argument("Deadline must be between 1 and 4");
        if (b->deadline > days || b->deadline < 1)
            throw std::invalid_argument("Deadline must be between 1 and 4");
        return a->profit > b->profit;
    });

    //find all options for each day
    std::vector<std::vector<std::shared_ptr<Job>>> dayJobsVec;
    dayJobsVec.resize(days);
    for (auto job : jobs)
        for (int day = 1; day <= job->deadline; day++)
            dayJobsVec[day - 1].push_back(job);

    //greedy method
    //find the best option for each day from the last day to the first day
    std::set<std::shared_ptr<Job>> pickedJobs;
    std::vector<std::shared_ptr<Job>> result;
    result.resize(days);
    for (int day = days - 1; day >= 0; day--) {
        for (auto job : dayJobsVec[day]) {
            if (pickedJobs.find(job) != pickedJobs.end())
                continue;
            pickedJobs.insert(job);
            result[day] = job;
            break;
        }
    }
    
    return result;
}