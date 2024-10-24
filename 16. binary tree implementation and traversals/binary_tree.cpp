#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int val;
    Node(int data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }
    Node *buildTree(Node *root)
    {
        cout << "Enter data" << endl;
        int data;
        cin >> data;
        if (data == -1)
            return NULL;
        root = new Node(data);
        cout << "Enter data for inserting in left node" << endl;
        root->left = buildTree(root);
        cout << "Enetr data for inserting in right Node" << endl;
        root->right = buildTree(root);
        return root;
    }
    void levelOrderTraversal(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            cout << temp->val;
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
    void preOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->val;
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val;
    }
    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->val;
        inOrder(root->right);
    }
    // Building tree from level Order
    Node *buildFromLevelOrder(Node *root)
    {
        queue<Node *> q;
        int data;
        cout << "Enter data" << endl;
        cin >> data;
        Node *root = new Node(data);
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << "Enter data for left Node" << endl;
            int leftData;
            cin >> leftData;
            if (leftData != -1)
            {
                temp->left = new Node(leftData);
                q.push(temp->left);
            }
            cout << "Enter data for right Node" << endl;
            int rightData;
            cin >> rightData;
            if (rightData != -1)
            {
                temp->right = new Node(rightData);
                q.push(temp->right);
            }
        }
    }
};