#include <iostream>
#include <cstdlib>
#include <iomanip>
#ifndef CONTAINER_H
#define CONTAINER_H

class Container
{
    public:
    static const size_t CAPACITY = 200;
    Container(size_t)
     {used = 0;}
    void record();
    void remove(double target);
    void display(ostream& outs);
    void time_sort();
    void distance_sort();
    void distance_view(double dist);
    void total_time();
    void total_distance();
    void average_pace();
    void save(ofs);



    

    private:
    Runtime data [CAPACITY];
    size_t used;



};
std::ostream& operator <<(ostream& outs, const Runtime& r){
    r.output(outs);
    return outs;
}
#endif
