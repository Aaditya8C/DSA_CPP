
#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node *left;
    Node *right;

    Node()
    {
        info = 0;
        left = NULL;
        right = NULL;
    }
};

class BST
{

public:
    Node *root;
    BST()
    {
        root = NULL;
    }

    void insert(int data)
    {
        Node *node = new Node();
        node->info = data;
        Node *current = root;
        Node *prev = NULL;

        if (current == NULL)
            root = node;
        else
        {
            while (current != NULL)
            {
                prev = current;

                if (node->info > current->info)
                    current = current->right;
                else
                    current = current->left;
            }
            if (node->info > prev->info)
                prev->right = node;
            else
                prev->left = node;
        }
    }

    void countLeaf(Node *root, int &count)
    {
        if (root != NULL)
        {
            if (root->left == NULL && root->right == NULL)
                count++;
            countLeaf(root->left, count);
            countLeaf(root->right, count);
        }
    }

    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->info << "\t";
            inorder(root->right);
        }
    }
};

int main()
{
    int ch;
    int data, count = 0;
    BST bt;
    bt.insert(20);
    bt.insert(8);
    bt.insert(12);
    bt.insert(22);
    bt.insert(4);
    bt.insert(10);
    bt.insert(14);
    // bt.inorder(bt.root);
    bt.countLeaf(bt.root, count);

    cout << "\nNo of leaf nodes in your BST is: " << count << endl;
    // while (1)
    // {
    //     cout << "\n1. Find inorder successor: " << endl;

    //     cout << "\nEnter operation to perform: ";
    //     cin >> ch;

    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter node to find it's inorder successor: ";
    //         cin >> data;
    //         bt.inorderSuccessor(data);
    //         break;
    //     default:
    //         return 0;
    //     }
    // }

    return 0;
}