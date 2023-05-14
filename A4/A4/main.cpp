#include "main.h"

struct Student{
    int id;
    string name;
    double gpa;
    string department;
    friend ostream & operator << (ostream &os,const Student &s){
        os << s.id << " " << s.name << " " << s.gpa << " " << s.department;
        return os;
    }
};
map<int, Student> m;
void Load(map<int,Student> &m){
    ifstream input_file("input.txt");
    int num_students;
    input_file >> num_students;
    for (int i = 0; i < num_students; i++)
    {
        Student st;
        input_file >> st.id;
        input_file >> std::ws;
        getline(input_file, st.name);
        input_file >> st.gpa;
        input_file >> std::ws;
        getline(input_file, st.department);
        m[st.id] = st;
    }


    input_file.close();



}
class Node{
public:
    Node *lchild, *rchild;
    Student data;
};

class BinarySearchTree{
private:
    Node *AddStudent(Node *p, Student key);
    void Print(Node *p);
    Node *Search(Node *p, int key);
    Node *root;
    Node *Remove(Node *p, int Key);
    Node *Predecessor(Node *p);
    Node* Successor(Node *p);
    int Height(Node *p);
public:
    BinarySearchTree(){root = NULL;}
    void AddStudent(Student key){ AddStudent(root, key);}
    void Search(int key){ Search(root, key)? cout << m[key] : cout << "Student Not Found";}
    void Remove(int key){ Remove(root, key); }
    void Print(){ Print(root); };

};
Node *BinarySearchTree::AddStudent(Node* p,Student key) {
    Node *t = NULL;
    if(p == NULL){
        m[key.id] = key;
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        if(root == NULL)
            root = t;
        return t;
    }
    if(key.id < p->data.id){
        p->lchild = AddStudent(p->lchild, key);
    }else if(key.id > p->data.id){
        p->rchild = AddStudent(p->rchild, key);
    }
    return p;
}
void BinarySearchTree::Print(Node *p) {
    if(p){
        Print(p->lchild);
        cout << p->data << endl;
        Print(p->rchild);
    }
}

Node * BinarySearchTree::Search(Node *p, int key) {
    if(p == NULL)
        return NULL;
    if(p->data.id == key){
        return p;
    }else if(key < p->data.id){
        return Search(p->lchild, key);
    }else{
        return Search(p->rchild, key);
    }
}

Node *BinarySearchTree::Predecessor(Node *p) {
    while (p && p->rchild){
        p = p->rchild;
    }
    return p;
}

Node *BinarySearchTree::Successor(Node *p) {
    while (p && p->lchild){
        p = p->lchild;
    }
    return p;
}

int BinarySearchTree::Height(Node *p) {
    if(p == NULL)
        return 0;
    int x, y;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x + y + 1;
}
Node *BinarySearchTree::Remove(Node *p, int key) {
    Node *q = NULL;
    if(p == NULL){
        return NULL;
    }
    if((p->lchild == NULL && p->rchild == NULL) && (p->data.id == key)){
        if(p == root)
            root = NULL;
        delete p;
        return NULL;
    }
    if(key < p->data.id){
        p->lchild = Remove(p->lchild, key);
    }else if(key > p->data.id){
        p->rchild = Remove(p->rchild, key);
    }else{
        if(Height(p->lchild) > Height(p->rchild)){
            q = Predecessor(p->lchild);
            p->data = q->data;
            p->lchild = Remove(p->lchild, q->data.id);
        }else{
            q = Successor(p->rchild);
            p->data = q->data;
            p->rchild = Remove(p->rchild, q->data.id);
        }
    }
    return p;
}
void start_BST(BinarySearchTree *tree)
{
    for(auto i: m)
        tree->AddStudent(i.second);
    int option;
    Student new_student;
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
           tree->AddStudent(new_student);
            break;
        case 2:
            cout << "id: ";
            cin >> id;
           tree->Remove(id);
            break;
        case 3:
            cout << "id: ";
            cin >> id;
            tree->Search(id);
            break;
        case 4:
           tree->Print();
           break;
        default:
            if (option != 5)
                cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (option != 5);
}

int main()
{
    Load(m);
    int n;
    AVLTree AVL_tree;
    MinHeap MinHeap_tree;
    MaxHeap MaxHeap_tree;
    BinarySearchTree BinarySearchTree_tree; 
    fill_trees(&AVL_tree, &MinHeap_tree, &MaxHeap_tree );
    while (true)
    {
        cout << "Choose Data Structure:" << endl
             << " 1. BST \n 2. AVL \n 3. Min Heap \n 4. Max Heap \n 5. Exit Program \n"
             << "Enter the number of your choice : ";
        cin >> n;
        if (n == 1)
        {
            start_BST(&BinarySearchTree_tree);
        }
        else if (n == 2)
            start_avl(&AVL_tree);
        else if (n == 3)
            MinHeap_Menu(&MinHeap_tree);
        else if (n == 4)
            MaxHeap_Menu(&MaxHeap_tree);
        else if (n == 5)
            break;
        else
            cout << "Invalid choice X_X, try again\n";
    }
    return (0);
}