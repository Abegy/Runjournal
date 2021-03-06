// The implementation file for the runtime class
#include "runtime.h"
#include "MyTime.h"
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
    tmp.rtime = rtime + rhs.rtime;
    tmp.distance = distance + rhs.distance;
    return tmp;
}

Runtime Runtime::operator -(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime - rhs.rtime;
    tmp.distance = distance - rhs.distance;
    return tmp;
}

Runtime Runtime::operator *(const double& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime * rhs;
    tmp.distance = distance * rhs;
    return tmp;
}
Runtime Runtime::operator /(const double& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime / rhs;
    tmp.distance = distance / rhs;
    return tmp;
}

bool Runtime::operator == (const Runtime& rhs)const{
    if(rtime == rhs.rtime && distance == rhs.distance){
        return true;
    }
    else{
        return false;
    }
}

bool Runtime::operator != (const Runtime& rhs)const{
    if(rtime == rhs.rtime && distance == rhs.distance){
        return false;
    }
    else{
        return true;
    }
}
bool Runtime::distance_equal(double d) const{
    if(distance == d){
        return true;
    }
    else {
        return false;
    }
    
}
void Runtime::input(std::istream& ins){
    ins >> rtime;
    ins >> distance;
}

void Runtime::output(std::ostream& outs)const{
   outs << rtime;
   outs << distance;
}

std::ostream& operator <<(std::ostream& outs, const Runtime& t1){
t1.output(outs);
return outs;
} 
			

std::istream& operator >>(std::istream& ins, Runtime& t1){
t1.input(ins);
return ins;
}
				