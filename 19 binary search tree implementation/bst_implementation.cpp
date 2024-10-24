#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        left = NULL;
        right = NULL;

    }
    Node* insertIntoBST(Node* &root, int d) {
        if (root == NULL) {
            root = new Node(d);
            return root;
        }
        if (d > root->data) {
            root->right = insertIntoBST(root->right, d);
        }
        else {
            root->left = insertIntoBST(root->left, d);
        }
        return root;
    }
    void takeInput(Node* root) {
        int d;
        cin >> d;
        while (d != -1 ) {
            root = insertIntoBST(root, d);
            cin >> d;

        }
    }

    //Iterative approach
    bool searchInBST(Node* root, int d) {
        Node* temp = root;
        while (temp != NULL) {
            if (temp->data == d) {
                return true;
            }
            if (temp->data < d) {
                searchInBST(root->right, d);
            }
            else {
                searchInBST(root->left, d);
            }
        }
        return false;
    }
    //Recursive approach
    bool searchInBST(Node* root, int d) {
        if (root == NULL) {
            return false;
        }
        if (root->data == d) {
            return true;
        }
        if (root->data > d) {
            searchInBST(root->left, d);
        }
        else {
            searchInBST(root->left, d);

        }
    }

    //Min and Max value
    Node* minVal(Node* root) {
        Node* temp = root;
        while (temp->left != NULL) {
            temp = temp ->left;
        }
        return temp;
    }
     Node* maxVal(Node* root) {
        Node* temp = root;
        while (temp->right != NULL) {
            temp = temp ->right;
        }
        return temp;
    }

    //Deletion code
    Node* deleteFromBST(Node* root, int d ) {
        if (root->data == d) {
            //Deletion code
            //For 0 child
            if (root->right == NULL && root->left == NULL) {
                
                delete root;
                return NULL;
            }
            //For one child
            if (root->left != NULL && root->right == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right != NULL && root->left == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            //FOr two childs
            if (root->right != NULL && root->left != NULL) {
                int mini = minVal(root->right)->data;
                root->data = mini;
                root->right = deleteFromBST(root->right, mini);
            }

        }
        if (root->data < d) {
            deleteFromBST(root->right, d);
        }
        else {
            deleteFromBST(root->left, d);

        }
    }

};