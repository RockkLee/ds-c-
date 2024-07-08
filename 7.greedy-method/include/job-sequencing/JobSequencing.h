#ifndef JOB_SEQUENCING_H
#define JOB_SEQUENCING_H

#include <job-sequencing/Job.h>

#include <vector>
#include <algorithm>
#include <memory>


class JobSequencing {
private:
public:
    static std::vector<std::shared_ptr<Job>> jobSequencing(int days, std::vector<std::shared_ptr<Job>> jobs); 
};

#endif //JOB_SEQUENCING_H