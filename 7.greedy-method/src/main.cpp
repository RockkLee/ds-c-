#include <stdio.h>

#include "job-sequencing/JobSequencing.h"
#include "job-sequencing/Job.h"
#include <vector>
#include <memory>

void jobSequencing(){
    std::vector<std::shared_ptr<Job>> jobs = {
        std::make_shared<Job>("J1", 2, 20), 
        std::make_shared<Job>("J2", 2, 30), 
        std::make_shared<Job>("J3", 1, 5), 
        std::make_shared<Job>("J4", 4, 25), 
        std::make_shared<Job>("J5", 3, 10), 
        std::make_shared<Job>("J6", 1, 15) 
    };

    auto result = JobSequencing::jobSequencing(4, jobs);
    for (auto job : result)
        printf("job:%s, deadline:%d, profit:%d\n", job->id.c_str(), job->deadline, job->profit);

    return;
}

int main(int, char**){
    printf("Hello, from greedy-method!\n");

    jobSequencing();
}
