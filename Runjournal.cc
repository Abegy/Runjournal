// The implementation file for the container class
#include "Runjournal.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructor

void Container::record(){
    if(used < CAPACITY){
        data[used] = 0;
        used++;
    }
    else{ 
        cout << "No room left " << endl;
    }
}
void Container::display(ostream& outs){
    for(size_t j = 0; j < used; ++j){
        cout << data[j] << endl;
    }

}

void Container::remove(double target){
    for(size_t i = 0; i < used; i++){
        if(data[i] == target){
            data[i] = data [used - 1];
            used--;
            return;
        }
    }
}
void Container::time_sort(){
    int tmp; size_t loc_small;
    for(size_t i = 0; i < used - 1; i++){
        for(size_t j = i; j < used; j++){
            loc_small = i;
            if (data[j] < data[loc_small]){
                loc_small = j;
                tmp = data[loc_small];
                data[loc_small] = data[i];
                data[i] = tmp;
            }
        }
    }
}
void Container::distance_sort(){
    int tmp; size_t loc_small;
    for(size_t i = 0; i < used - 1; i++){
        for(size_t j = i; j < used; j++){
            loc_small = i;
            if (data[j] < data[loc_small]){
                loc_small = j;
                tmp = data[loc_small];
                data[loc_small] = data[i];
                data[i] = tmp;
            }
        }
    }
}

void Container::distance_view(double dist){

}



