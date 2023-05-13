#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include<vector>
struct Student {
    int id;
    string name;
    double gpa;
    string department;
    friend ostream& operator << (ostream& os, const Student& s) {
        os << s.id << " , " << s.name << " , " << s.gpa << " , " << s.department;
        return os;
    }
};