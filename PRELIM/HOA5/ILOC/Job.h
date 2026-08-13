#ifndef JOB_H
#define JOB_H

#include <string>
#include <cstdlib>

class Job {
private:
    int jobID;
    std::string username;
    int pages;

public:
    // Default constructor (needed so Job can be stored inside a Node)
    Job() : jobID(0), username(""), pages(0) {}

    // Main constructor: ID and pages are both generated automatically —
    // only the username needs to be supplied.
    Job(const std::string& user) {
        jobID = (std::rand() % 90000) + 10000; // auto: random 5-digit ID (10000-99999)
        username = user;
        pages = (std::rand() % 20) + 1;        // auto: random between 1 and 20 pages
    }

    int getID() const { return jobID; }
    std::string getUsername() const { return username; }
    int getPages() const { return pages; }
};

#endif

