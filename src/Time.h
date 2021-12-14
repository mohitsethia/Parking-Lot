#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Time{
    public:
    int hour;
    int minute;
    Time(int hour, int minute){
        this->hour = hour;
        this->minute = minute;
    }
};