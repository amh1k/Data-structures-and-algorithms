#include <iostream>
using namespace std;
class Node
{
public:
    int height;
    Node *right;
    Node *left;
    int key;
    Node(int data)
    {
        this->key = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};
class AVLTree
{
public:
    Node *root;
    AVLTree()
    {
        root = NULL;
    }

    // Helper functions for aiding in insertion and deletions
    int findHeight(Node *root)
    {
        int leftHeight = root && root->left ? root->left->height : 0;
        int rightHeight = root && root->right ? root->right->height : 0;
        return max(leftHeight, rightHeight) + 1;
    }
    int balanceFactor(Node *root)
    {
        int leftHeight = root && root->left ? root->left->height : 0;
        int rightHeight = root && root->right ? root->right->height : 0;
        return leftHeight - rightHeight;
    }
    Node *findMin(Node *root)
    {
        if (root->left == NULL || root->right == NULL)
        {
            return root;
        }
        return findMin(root->left);
    }
    Node *LLRotation(Node *root)
    {
        Node *rootLChild = root->left;
        Node *rootLRChild = root->left->right;
        rootLChild->right = root;
        root->left = rootLRChild;
        root->height = findHeight(root);
        rootLChild->height = findHeight(rootLChild);
        if (root == this->root)
        {
            this->root = rootLChild;
        }
        return rootLChild;
    }
    Node *RRRotation(Node *root)
    {
        Node *rootRChild = root->right;
        Node *rootRLChild = root->right->left;
        rootRChild->left = root;
        root->right = rootRLChild;
        root->height = findHeight(root);
        rootRChild->height = findHeight(root);
        if (root == this->root)
        {
            this->root = rootRChild;
        }
        return rootRChild;
    }
    Node *LRRotation(Node *root)
    {
        root->left = RRRotation(root->left);
        return LLRotation(root);
    }
    Node *RLRotation(Node *root)
    {
        root->right = LLRotation(root->right);
        return RRRotation(root);
    }
    // Insert function
    Node *insert(Node *root, int key)
    {
        if (root == NULL)
        {
            Node *newNode = new Node(key);
            return newNode;
        }
        if (root->key < key)
        {
            root->right = insert(root->right, key);
        }
        else if (root->key > key)
        {
            root->left = insert(root->left, key);
        }

        // Updating height
        root->height = findHeight(root);

        // BalanceFactor and rotations
        if (balanceFactor(root) == 2 && balanceFactor(root->left) == 1)
        {
            return LLRotation(root);
        }
        if (balanceFactor(root) == 2 && balanceFactor(root->left) == -1)
        {
            root->left = LLRotation(root->left);
            return RRRotation(root);
        }
        if (balanceFactor(root) == -2 && balanceFactor(root->right) == -1)
        {
            return RRRotation(root);
        }
        if (balanceFactor(root) == -2 && balanceFactor(root->right) == 1)
        {
            root->right = RRRotation(root->right);
            return LLRotation(root);
        }
        return root;
    }

    // Deletion function
    Node *deleteFunc(Node *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->key < key)
        {
            root = deleteFunc(root->right, key);
        }
        else if (root->key > key)
        {
            root = deleteFunc(root->left, key);
        }
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteFunc(root->left, temp->key);
        }
        root->height = findHeight(root);
        if (balanceFactor(root) == 2 && balanceFactor(root->left) == 1) // L1 rotation
        {
            return LLRotation(root);
        }
        if (balanceFactor(root) == 2 && balanceFactor(root->left) == -1) // L -1 rotation
        {
            return LRRotation(root);
        }
        if (balanceFactor(root) == -2 && balanceFactor(root->right) == -1) // R -1 rotation
        {
            return RRRotation(root);
        }
        if (balanceFactor(root) == -2 && balanceFactor(root->right) == 1) // R1 rotation
        {
            return RLRotation(root);
        }
        if (balanceFactor(root) == 2 && balanceFactor(root->left) == 0) // L0 rotation
        {
            return LLRotation(root);
        }
        if (balanceFactor(root) == -2 && balanceFactor(root->right) == 0) // R0 rotation
        {
            return RRRotation(root);
        }
        return root;
    };
    void print(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        print(root->left);
        cout << root->key << "  ";
        print(root->right);
    }
    void print()
    {
        print(this->root);
    }
};
int main()
{

    AVLTree tree;

    // Inserting elements into the tree
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 25);
    tree.root = tree.insert(tree.root, 35);

    cout << "Tree after insertion:" << endl;
    tree.print();
    cout << endl;

    // Deleting an element from the tree
    tree.root = tree.deleteFunc(tree.root, 15);
    cout << "Tree after deleting 15:" << endl;
    tree.print();
    cout << endl;

    // Deleting another element from the tree
    tree.root = tree.deleteFunc(tree.root, 20);
    cout << "Tree after deleting 20:" << endl;
    tree.print();
    cout << endl;

    return 0;
}