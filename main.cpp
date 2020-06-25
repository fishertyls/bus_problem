//
//  main.cpp
//  bus_problem
//
//  Created by Mike on 25/06/20.
//  Copyright © 2020 mike. All rights reserved.
//

#include<iostream>
#include <vector>
using namespace std;

struct BusStop
{
    uint32_t exit;   // exit number
    uint32_t enter;  // enter number
};

int calcMinCapacity(const vector<BusStop> & busStops){
    uint32_t sum = 0;
    uint32_t max = 0;
    
    for (auto & e : busStops) {
        if (e.exit > sum) {
            cout << "exit number exceed current number." << endl;
            return -1;
        }
        
        sum = (sum - e.exit + e.enter);
        if (sum > max){
            max = sum;
        }
    }
    
    return max;
}

int main(){
    uint32_t N = 0;

    /* input data */
    cin >> N;
    BusStop busStop = {0};
    vector<BusStop> myVector;
    for (uint32_t i = 0; i < N; i++){
        cin >> busStop.exit >> busStop.enter;
        myVector.push_back(busStop);
    }
    
    /* calculate minimum capacity of the bus */
    int ret = calcMinCapacity(myVector);
    
    cout << ret << endl;
    
    return 0;
}
