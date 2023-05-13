#pragma once
#include "Student.h"
class MinHeap
{
private:
   
    Student* array{ };
    int size{ };
    int capacity{ 1000 };

    int left(int node) {
        int p = 2 * node + 1;
        if (p >= size)
            return -1;
        return p;
    }
    int right(int node) {
        int p = 2 * node + 2;
        return p >= size ? -1 : p;
    }
    int parent(int node) {
        return node == 0 ? -1 : (node - 1) / 2;
    }

    void heapify_up(int child_pos) {
        // stop when parent is smaller (or no parent)
        int par_pos = parent(child_pos);
        if (child_pos == 0 || array[par_pos].gpa < array[child_pos].gpa)
            return;

        swap(array[child_pos], array[par_pos]);
        heapify_up(par_pos);
    }
    void heapify_down(int parent_pos) {	// O(logn)
        int child_pos = left(parent_pos);
        int right_child = right(parent_pos);

        if (child_pos == -1) // no children
            return;
        // is right smaller than left?
        if (right_child != -1 && array[right_child].gpa < array[child_pos].gpa)
            child_pos = right_child;

        if (array[parent_pos].gpa > array[child_pos].gpa) {
            swap(array[parent_pos], array[child_pos]);
            heapify_down(child_pos);
        }
    }

public:
    MinHeap();
    ~MinHeap();
    void push(Student s);
    bool isempty();
    Student top();
    void pop();
    int Size();
};

