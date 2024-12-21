#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <chrono>
using namespace std;

class goods {
private:
    int id, quantity, storage_time, time_to_exp;
    string name, entry_date, expired_date;
public:
    goods* next;
    int getid();
    int getquantity();
    int getstorage_time();
    int gettime_to_exp();
    string getname();
    string getentry_date();
    string getexpired_date();

    void setid(int x);
    void setquantity(int y);
    void setstorage_time(int z);
    void settime_to_exp(int t);
    void setname(string a);
    void setentry_date(string b);
    void setexpired_date(string c);
};

int daysSinceToday(const string& dateStr);