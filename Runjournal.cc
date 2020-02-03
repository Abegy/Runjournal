// The implementation file for the RunJournal class
#include "runtime.h"
#include "MyTime.h"
#include "Runjournal.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructor

void RunJournal::record(Runtime tmp){
    if(used < CAPACITY){
        data[used] = tmp;
        used++;
    }
    else{ 
        cout << "No room left " << endl;
    }
}
void RunJournal::display(){
     for(int i = 0; i < used; ++i){
      cout << "Run " << i + 1 << " | Time: " << data[i].get_time() << " " << data[i].get_distance() << endl;
     }

}

void RunJournal::find_remove(Runtime tmp){
    double totaltime = 0;
    double pace = (totaltime / tmp.get_distance());
    char choice;

   for(int i = 0; i < used; i++){
       if(data[i] == tmp){
           totaltime = tmp.get_time().get_hours() + tmp.get_time().get_minutes()/60 + tmp.get_time().get_seconds()/3600;
           cout << "Total Distance: " << tmp.get_distance() << " Pace: " << pace << endl;
            cout << "Would you like to remove this run? (y/n)" << endl;
            cin >> choice;
            if (choice == 'y' || choice == 'Y'){
                for(size_t i = 0; i < used; i++){
                if(data[i] == tmp){
                data[i] = data [used - 1];
                used--;
                return;
                }
             }
        }
    }
    
  } 

}

void RunJournal::distance_view(double dist){
    
    for(int i = 0; i < used; i++){
        if(data[i].get_distance() == dist){
            cout << data[i] << endl;
        }
        else{
            cout << "no runs at that distance" << endl;
        }
    }
}


void RunJournal::time_sort(){
    int tmp; size_t loc_small;
    for(size_t i = 0; i < used - 1; i++){
        for(size_t j = i; j < used; j++){
            loc_small = i;
            if (data[j].get_time() < data[loc_small].get_time()){
                loc_small = j;
                data[loc_small].get_time() = tmp; 
                data[loc_small] = data[i];
                data[i].get_time() = tmp;
            }
        }
    }
}


void RunJournal::distance_sort(){
    int tmp; size_t loc_small;
    for(size_t i = 0; i < used - 1; i++){
        for(size_t j = i; j < used; j++){
            loc_small = i;
            if (data[j].get_distance() < data[loc_small].get_distance()){
                loc_small = j;
                tmp = data[loc_small].get_distance();
                data[loc_small] = data[i];
                tmp = data[i].get_distance();
            }
        }
    }
    }


MyTime RunJournal::total_time(){
    int totalSeconds = 0;
    int totalMinutes = 0;
    int totalHours = 0;


    for (int i = 0; i < used; i++){
        totalSeconds += (data[i].get_time()).get_seconds();
        totalMinutes += (data[i].get_time()).get_minutes();
        totalHours += (data[i].get_time()).get_hours();
    }
    totalMinutes += totalSeconds/60;
    totalSeconds = totalSeconds%60;
    totalHours += totalMinutes/60;
    totalMinutes = totalMinutes%60;
    
    MyTime tmp(totalHours, totalMinutes, totalSeconds);
    return tmp; 
}

double RunJournal::total_distance(){
    int totalDistance = 0;
    for(int i = 0; i < used; i++){
       totalDistance += data[i].get_distance(); 
    }
     return totalDistance;
}

double RunJournal::average_pace(){
    double totalhr = 0;
    totalhr += total_time().get_hours();
    totalhr += (total_time().get_minutes()/60);
    totalhr += (total_time().get_seconds()/3600);
    return totalhr / total_distance();
}





void RunJournal::save(std::ostream& ofs){
    for(int i = 0; i < used; i++){
        ofs << data[i].get_time() << " " << data[i].get_distance();
    }

}



