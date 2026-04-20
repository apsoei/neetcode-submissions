#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class TreeMap 
{
public:
    struct Node
    {
        int key = 0;
        int val = 0;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int k, int v) : key(k), val(v) {}
        Node(){}
    };

    Node* sentinel;
    // sentinel will be dummy root and real root is left of this sentinel
    TreeMap() 
    {
        sentinel = new Node();
    }

    void insert(int key, int val) 
    {

        if (!sentinel->left)
        {
            sentinel->left = new Node(key, val);
            return;
        }

        Node* node = sentinel->left;

        while (true)
        {
            if (node->key == key) 
            {
                node->val = val;
                break;
            }
            if (node->key > key)
            {
                if (!node->left)
                {
                    node->left = new Node(key, val);
                    break;
                }
                node = node->left;
            }
            else
            {
                if (!node->right)
                {
                    node->right = new Node(key, val);
                    break;
                }
                node = node->right;
            }
        }

    }

    int get(int key) 
    {
        Node* node = sentinel->left;
        if (!node) return -1;

        while (node && node->key != key)
        {
            if (node->key > key)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }

        if (!node) return -1;

        return node->val;
    }

    int getMin() 
    {
        // left most node will have minimum key
        Node* node = sentinel->left;
        if (!node) return -1;

        while (node->left)
        {
            node = node->left;
        }

        return node->val;
    }

    int getMax() 
    {
        // right most node will have maximum key
        Node* node = sentinel->left;
        if (!node) return -1;
        while (node->right)
        {
            node = node->right;
        }

        return node->val;
    }

    void remove(int key) 
    {

        Node* node = sentinel->left;
        if (!node) return;
        // find node with the key
        Node* parent = sentinel;
        bool isLeftChild = true;

        while (node && node->key != key)
        {
            parent = node;
            if (node->key > key)
            {
                isLeftChild = true;
                node = node->left;
            }
            else
            {
                isLeftChild = false;
                node = node->right;
            }
        }

        // node is the one to delete
        if (!node) return;
        Node* LRM = node->left;
        Node* LRMParent = node;
        bool isLRMLeftChild = true;
        while (LRM && LRM->right)
        {
            isLRMLeftChild = false;
            LRMParent = LRM;
            LRM = LRM->right;
        }

        if (!LRM)
        {
            if (isLeftChild)
            {
                parent->left = node->right;
            }
            else
            {
                parent->right = node->right;
            }
            delete node;
            return;
        }

        node->key = LRM->key;
        node->val = LRM->val;
        if (isLRMLeftChild)
        {
            LRMParent->left = LRM->left;
        }
        else
        {
            LRMParent->right = LRM->left;
        }
        
        delete LRM;

        
    }

    std::vector<int> getInorderKeys() 
    {
        vector<int> res;

        Node* node = sentinel->left;
        if (!node) return res;

        // stack<Node*> st;

        // while (!st.empty() || node)
        // {
        //     while (node)
        //     {
        //         st.push(node);
        //         node = node->left;
        //     }

        //     node = st.top();
        //     st.pop();
        //     res.push_back(node->key);
        //     node = node->right;
        // }

        // return res;

        inorder(node, res);
        return res;
    }

    void inorder(Node* node, vector<int>& res)
    {
        if (!node)
        {
            return;
        }

        inorder(node->left, res);
        res.push_back(node->key);
        inorder(node->right, res);
    }
};
