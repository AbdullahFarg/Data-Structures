#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef struct student
{
    int id;
    string name;
    string dept;
    float gpa;
    void view()
    {
        cout << "[" << id << ", " << name << ", " << gpa << ", " << dept << "]" << endl;
    }
    friend ostream &operator<<(ostream &os, const student &s)
    {
        os << s.id << " , " << s.name << " , " << s.gpa << " , " << s.dept;
        return os;
    }
} std_t;
#include "AVL.h"
#include "MaxHeap.h"
#include "MinHeap.h"
void _load();
void fill_trees(AVLTree *t, MinHeap *t2, MaxHeap *t3);
void start_avl(AVLTree *tree);
void MaxHeap_Menu(MaxHeap *tree);
void MinHeap_Menu(MinHeap *tree);
student get_student();
#endif /* MAIN_H */