#ifndef AVL_H
#define AVL_H

#include "main.h"
typedef struct AVLNode
{
    std_t student;
    struct AVLNode *right;
    struct AVLNode *left;
    int Height;
    AVLNode(std_t std)
    {
        this->student.id = std.id;
        this->student.dept = std.dept;
        this->student.name = std.name;
        this->student.gpa = std.gpa;
        this->Height = 1;
        this->right = nullptr;
        this->left = nullptr;
    }
} AVLNode;

class AVLTree
{
public:
    AVLNode *root;
    AVLTree() { root = nullptr; }
    AVLNode *insert(AVLNode *node, std_t std)
    {
        if (node == NULL)
        {
            return new AVLNode(std);
        }

        if (std.id < node->student.id)
        {
            node->left = insert(node->left, std);
        }
        else
        {
            node->right = insert(node->right, std);
        }

        node->Height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && std.id < node->left->student.id)
        {
            return rotateRight(node);
        }

        if (balance < -1 && std.id > node->right->student.id)
        {
            return rotateLeft(node);
        }

        if (balance > 1 && std.id > node->left->student.id)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && std.id < node->right->student.id)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }
    int getHeight(AVLNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        return (node->Height);
    }
    int getBalance(AVLNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        return (getHeight(node->left) - getHeight(node->right));
    }
    AVLNode *rotateRight(AVLNode *node)
    {
        AVLNode *temp1 = node->left;
        AVLNode *temp2 = temp1->right;

        temp1->right = node;
        node->left = temp2;

        node->Height = max(getHeight(node->left), getHeight(node->right)) + 1;
        temp1->Height = max(getHeight(temp1->left), getHeight(temp1->right)) + 1;

        return temp1;
    }
    AVLNode *rotateLeft(AVLNode *node)
    {
        AVLNode *temp1 = node->right;
        AVLNode *temp2 = temp1->left;

        temp1->left = node;
        node->right = temp2;

        node->Height = max(getHeight(node->left), getHeight(node->right)) + 1;
        temp1->Height = max(getHeight(temp1->left), getHeight(temp1->right)) + 1;

        return temp1;
    }
    void inorderTraversal(AVLNode *node)
    {
        if (node == NULL)
        {
            return;
        }

        inorderTraversal(node->left);
        node->student.view();
        inorderTraversal(node->right);
    }
    bool search(AVLNode *node, int id)
    {
        if (node == NULL)
            return false;
        if (node->student.id == id)
        {
            cout << "Student is found.\n";
            node->student.view();
            return true;
        }

        if (search(node->left, id))
            return true;
        else if (search(node->right, id))
            return true;
        else
            return false;
    }
    AVLNode *remove(AVLNode *node, int id)
    {
        if (node == NULL)
            return node;

        if (id < node->student.id)
            node->left = remove(node->left, id);
        else if (id > node->student.id)
            node->right = remove(node->right, id);
        else
        {
            if (node->left == NULL || node->right == NULL)
            {
                AVLNode *temp = node->left ? node->left : node->right;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                {
                    *node = *temp;
                    delete temp;
                }
            }
            else
            {
                AVLNode *temp = getMinValueNode(node->right);

                node->student = temp->student;

                node->right = remove(node->right, temp->student.id);
            }
        }

        if (node == NULL)
            return node;

        node->Height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);

        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return rotateLeft(node);

        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode *getMinValueNode(AVLNode *node)
    {
        AVLNode *current = node;

        while (current->left != NULL)
            current = current->left;

        return current;
    }
};
#endif /* AVL_H */