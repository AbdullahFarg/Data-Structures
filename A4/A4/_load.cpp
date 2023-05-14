#include "main.h"
#include <fstream>

vector<std_t> load()
{
    ifstream input_file("input.txt");
    int num_students;
    input_file >> num_students;
    vector<std_t> students(num_students);

    for (int i = 0; i < num_students; i++)
    {
        input_file >> students[i].id;
        input_file >> std::ws;
        getline(input_file, students[i].name);
        input_file >> students[i].gpa;
        input_file >> std::ws;
        getline(input_file, students[i].dept);
    }

    input_file.close();

    // print the student data
    // for (int i = 0; i < num_students; i++)
    // {
    //     cout << "ID: " << students[i].id << endl;
    //     cout << "Name: " << students[i].name << endl;
    //     cout << "GPA: " << students[i].gpa << endl;
    //     cout << "Department: " << students[i].dept << endl;
    //     cout << endl;
    // }
    return (students);
}

void fill_trees(AVLTree *t, MinHeap *t2, MaxHeap *t3)
{
    vector<std_t> stds = load();
    for (auto s : stds)
    {
        t->root = t->insert(t->root, s);
        t2->push(s);
        t3->push(s);
    }
}