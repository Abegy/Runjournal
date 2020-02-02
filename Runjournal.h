#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "runtime.h"
#include "MyTime.h"
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H

class RunJournal
{
    
    public:
    RunJournal(){
        used = 0;
    }
    static const size_t CAPACITY = 200;
    RunJournal(size_t)
     {used = 0;}
    void record(Runtime tmp);
    void find_remove(Runtime tmp);
    void display();
    void time_sort();
    void distance_sort();
    void distance_view(double dist);
    MyTime total_time();
    double total_distance();
    double average_pace();
    void save(std::ostream& ofs);



    

    private:
    Runtime data [CAPACITY];
    size_t used;



};

#endif
