// The implementation file for the runtime class
#include "runtime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructor

Runtime::Runtime(){
    distance = 0;
    rtime = 0;
}

Runtime Runtime::operator +(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime + rhs;
    tmp.distance = distance + rhs;
    return tmp;
}

Runtime Runtime::operator -(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime - rhs;
    tmp.distance = distance - rhs;
    return tmp;
}

Runtime Runtime::operator *(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime * rhs;
    tmp.distance = distance * rhs;
    return tmp;
}
Runtime Runtime::operator /(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime / rhs;
    tmp.distance = distance / rhs;
    return tmp;
}

bool Runtime::operator ==(const Runtime& rhs)const{
    return rtime == rhs.time && distance == rhs.distance;
}

bool operator != (const Runtime& rhs)const{
    return rtime != rhs.time && distance != rhs.distance;
}
bool distance_equal(double d) const{
    if(distance == rhs.distance){
        return true;
    }
}
void input(std::istream& ins){
    int num;
while (ins.peek() == '\n'){
    ins.ignore();
    }
ins >> num;
while (!ins.eof()){
    insert(num);
    ins >> num;
} 
}

void output(std::ostream& outs)const{
    for(size_t i = 0; i < used; i++){
    outs << data[i] << endl;
    }
}

Runtime operator *(const double& lhs, const Runtime& rhs){
    Runtime tmp;
    tmp.rtime = rhs * rtime;
    tmp.distance = rhs * distance;
    return tmp;
}