
#include <iostream>
#include <map>
#include <fstream>
#include<vector>
#include"MinHeap.h"
#include "BinarySearchTree.h"
#include<string>
#include"MaxHeap.h"
using namespace std;

vector<Student> vec;
void Load(vector<Student>& vec) {
    ifstream file("input.txt");
    string s;
    while (!file.eof()) {
        Student st;
        getline(file, s);
        st.id = stoi(s);
        getline(file, s);
        st.name = s;
        getline(file, s);
        st.gpa = stof(s);
        getline(file, s);
        st.department = s;
        vec.push_back(st);
    }

}

void Load() {
    ifstream file("Student.txt");
    string s;
    getline(file, s);
    while (!file.eof()) {
        Student st;
        getline(file, s);
        st.id = stoi(s);
        getline(file, s);
        st.name = s;
        getline(file, s);
        st.gpa = stof(s);
        getline(file, s);
        st.department = s;
        m[st.id] = st;
    }

}

void print_MaxHeap()
{
    MaxHeap heap;
    for (auto i : vec)
        heap.push(i);
    while (!heap.isempty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }
}
void print_MinHeap()
{
    MinHeap heap;
    for (auto i : vec)
        heap.push(i);
    while (!heap.isempty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }
}
void Add_student()
{
    Student s;
    cout << "Enter the id : ";
    cin >> s.id;
    cout << "\nEnter the name : ";
    cin >> s.name;
    cout << "\nEnter the GPA : ";
    cin >> s.gpa;
    cout << "\nEnter the Department : ";
    cin >> s.department;
    vec.push_back(s);
}
bool Menu()
{
    int n;
    cout << "Choose Data Structure:" << endl
        << "1. BST \n 2. AVL \n 3. Min Heap \n 4. Max Heap \n 5. Exit Program \n" <<
        "Enter the number of your choice : ";
    cin >> n;
    if (n == 1)
    {
        int choice;
        cout << "Choose one of the following options:" << endl
            << "1. Add student\n"
            "2. Remove student\n"
            "3. Search student\n"
            "4. Print All (sorted by id)\n"
            "5. Return to main menu \n " <<
            "Enter the number of your choice : ";
        cin >> choice;
    }
    else if (n == 2)
    {
        int choice;
        cout << "Choose one of the following options:" << endl
            << "1. Add student\n"
            "2. Remove student\n"
            "3. Search student\n"
            "4. Print All (sorted by id)\n"
            "5. Return to main menu \n "
            "Enter the number of your choice : ";
        cin >> choice;
    }
    else if (n == 3)
    {
        int choice;
        cout << "Choose one of the following options:" << endl
            << "1. Add student\n"
            "2. Print All (sorted by gpa)\n"
            "3. Return to main menu \n "
            "Enter the number of your choice : ";
        cin >> choice;
        if (choice == 1)
            Add_student();
        else if (choice == 2)
            print_MinHeap();
        else
            Menu();
    }
    else if (n == 4)
    {
        int choice;
        cout << "Choose one of the following options:" << endl
            << "1. Add student\n"
            "2. Print All (sorted by gpa)\n"
            "3. Return to main menu \n "
            "Enter the number of your choice : ";
        cin >> choice;
        if (choice == 1)
            Add_student();
        else if (choice == 2)
            print_MaxHeap();
        else
            Menu();
    }
    else
    {
        return 0;
    }

}

signed main()
{
    Load(vec);
    while (Menu());
   
}

