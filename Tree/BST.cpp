
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

    Node *getMinimumKey(Node *current)
    {
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    void deleteNode(Node *root, int val)
    {
        Node *parent = NULL;
        Node *current = root;

        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        while (current != NULL && current->info != val)
        {
            parent = current;
            if (val < current->info)
                current = current->left;
            else
                current = current->right;
        }

        if (current == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }

        if (current->left == NULL && current->right == NULL)
        {
            if (current != root)
            {
                if (current == parent->left)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else
                root = NULL;
            delete current;
        }
        else if (current->left && current->right)
        {
            Node *inorderSuccessor = getMinimumKey(current->right);
            int data = inorderSuccessor->info;
            cout << data;
            deleteNode(root, data);
            current->info = data;
        }
        else if (current->left || current->right)
        {
            Node *temp = current->left ? current->left : current->right;

            if (current != root)
            {
                if (current == parent->left)
                    parent->left = temp;
                else
                    parent->right = temp;
                delete current;
            }
            else
            {
                parent = temp;
                delete temp;
            }
        }
        else
            root = NULL;
        // delete current;
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
    int data, pos;
    BST bt;
    // bt.insert(20);
    // bt.insert(10);
    // bt.insert(27);
    // bt.insert(5);
    // bt.insert(12);
    // bt.insert(30);
    bt.insert(40);
    bt.insert(60);
    // bt.inorder(bt.root);
    while (1)
    {
        cout << "\n1. Insert in BST: " << endl;
        cout << "2. Delete in BST: " << endl;
        cout << "3. Display List: " << endl;

        cout << "\nEnter operation to perform: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter data to insert: ";
            cin >> data;
            bt.insert(data);
            break;
        case 2:
            cout << "Enter data to delete: ";
            cin >> data;
            bt.deleteNode(bt.root, data);
            break;
        case 3:
            bt.inorder(bt.root);
            cout << endl;
            break;
        default:
            return 0;
        }
    }

    return 0;
}