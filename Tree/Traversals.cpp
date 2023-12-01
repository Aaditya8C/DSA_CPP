
#include <iostream>

using namespace std;

class Tree
{
public:
    int info;
    Tree *left;
    Tree *right;

    Tree()
    {
        info = 0;
        left = NULL;
        right = NULL;
    }
};

class BST
{

public:
    Tree *root;
    BST()
    {
        root = NULL;
    }

    void insert(int data)
    {
        Tree *node = new Tree();
        node->info = data;
        Tree *current = root;
        Tree *prev = NULL;

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

    void preorder(Tree* root){
        if(root != NULL){
            cout << root->info << "\t";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(Tree *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->info << "\t";
            inorder(root->right);
        }
    }
    void postorder(Tree *root)
    {
        if (root != NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->info << "\t";
        }
    }
};

int main()
{
    int ch;
    int data, pos;
    BST bt;
    bt.insert(20);
    bt.insert(10);
    bt.insert(27);
    bt.insert(5);
    bt.insert(12);
    bt.insert(30);
    bt.insert(40);
    bt.insert(60);
    while (1)
    {
        cout << "\n1. Insert in BST: " << endl;
        cout << "2. Preorder: " << endl;
        cout << "3. Inorder: " << endl;
        cout << "4. Postorder: " << endl;
        // cout << "5. Exit: " << endl;

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
            bt.preorder(bt.root);
            break;
        case 3:
            bt.inorder(bt.root);
            break;
        case 4:
            bt.postorder(bt.root);
            break;
        default:
            return 0;
        }
    }

    return 0;
}