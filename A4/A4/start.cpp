#include "main.h"

student get_student()
{
    student new_student;
    cout << "id: ";
    cin >> new_student.id;
    cout << "Name: ";
    cin.ignore();
    getline(cin, new_student.name);
    cout << "GPA: ";
    cin >> new_student.gpa;
    cout << "Department: ";
    cin.ignore();
    getline(cin, new_student.dept);
    return new_student;
}

void start_avl(AVLTree *tree)
{
    int option;
    student new_student;
    int id;

    do
    {
        cout << "Choose one of the following options:" << endl
             << "1. Add student" << endl
             << "2. Remove student" << endl
             << "3. Search student" << endl
             << "4. Print All (sorted by id)" << endl
             << "5. Return to main menu" << endl
             << "Enter number of option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            tree->root = tree->insert(tree->root, get_student());
            break;
        case 2:
            cout << "id: ";
            cin >> id;
            if (!tree->remove(tree->root, id))
                cout << "Student is not found.\n";
            break;
        case 3:
            cout << "id: ";
            cin >> id;
            if (!tree->search(tree->root, id))
                cout << "Student is not found.\n";
            break;
        case 4:
            tree->inorderTraversal(tree->root);
            break;
        default:
            if (option != 5)
                cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (option != 5);
}

void MinHeap_Menu(MinHeap *tree)
{
    int choice;
    cout << "Choose one of the following options:" << endl
         << "1. Add student\n"
            "2. Print All (sorted by gpa)\n"
            "3. Return to main menu \n "
            "Enter the number of your choice : ";
    cin >> choice;
    if (choice == 1)
        tree->push(get_student());
    else if (choice == 2)
        tree->print();
    else
        return;
}

void MaxHeap_Menu(MaxHeap *tree)
{
    int choice;
    cout << "Choose one of the following options:" << endl
         << "1. Add student\n"
            "2. Print All (sorted by gpa)\n"
            "3. Return to main menu \n "
            "Enter the number of your choice : ";
    cin >> choice;
    if (choice == 1)
        tree->push(get_student());
    else if (choice == 2)
        tree->print();
    else
        return;
}
