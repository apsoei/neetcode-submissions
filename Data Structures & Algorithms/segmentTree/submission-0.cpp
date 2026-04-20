class Node
{
public:
    int sum;
    int L, R;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int sum, int L, int R) : sum(sum), L(L), R(R) {}
    Node() {}
};

class SegmentTree 
{
public:
    Node* root;
    SegmentTree(vector<int>& nums) 
    {
        // build
        root = build(nums, 0, nums.size() - 1);
    }

    Node* build(vector<int>& nums, int L, int R)
    {
        if (L == R)
        {
            return new Node(nums[L], L, R);
        }

        int M = L + (R - L) / 2;

        Node* node = new Node(0, L, R);
        node->left = build(nums, L, M);
        node->right = build(nums, M + 1, R);
        node->sum = node->left->sum + node->right->sum;

        return node;
    }
    
    void update(int index, int val) 
    {
        updateHelper(root, index, val);
    }

    void updateHelper(Node* node, int index, int val)
    {
        if (node->L == node->R)
        {
            node->sum = val;
            return;
        }

        int M = node->L + (node->R - node->L) / 2;
        if (index > M)
        {
            updateHelper(node->right, index, val);
        }
        else
        {
            updateHelper(node->left, index, val);
        }

        node->sum = node->left->sum + node->right->sum;
    }
    
    int query(int L, int R) 
    {
        return queryHelper(root, L, R);
    }

    int queryHelper(Node* node, int L, int R)
    {
        if (node->L == L && node->R == R)
        {
            return node->sum;
        }

        int M = node->L + (node->R - node->L) / 2;

        if (L > M)
        {
            return queryHelper(node->right, L, R);
        }
        else if (R <= M)
        {
            return queryHelper(node->left, L, R);
        }
        
        return queryHelper(node->left, L, M) + queryHelper(node->right, M + 1, R);
    }
};
