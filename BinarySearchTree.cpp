#include <iostream>
using namespace std;
#include <map>
#include <fstream>

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
    ifstream file("Student.txt");
    string s;
    getline(file,s);
    while (!file.eof()) {
        Student st;
        getline(file,s);
        st.id = stoi(s);
        getline(file,s);
        st.name = s;
        getline(file,s);
        st.gpa = stof(s);
        getline(file,s);
        st.department = s;
        m[st.id] = st;
    }

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
int main() {

    Load(m);
    BinarySearchTree BST;
    for(auto i: m)
        BST.AddStudent(i.second);
    Student st;
    st.name = "Ahmed";
    st.id = 100;
    st.gpa = 4;
    st.department = "cs";
    BST.AddStudent(st);
    BST.Remove(10);
    BST.Print();
    BST.Search(100);
    


    return 0;
}
