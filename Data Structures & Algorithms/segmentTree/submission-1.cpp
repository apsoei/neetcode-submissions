class SegmentTree 
{
public:
    struct Node
    {
        int L, R;
        int sum;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int L, int R, int sum) : L(L), R(R), sum(sum) {}
    };

    Node* root;

    SegmentTree(vector<int>& nums) 
    {
        root = build(nums, 0, nums.size() - 1);
    }

    Node* build(vector<int>& nums, int L, int R)
    {
        if (L >= R)
        {
            return new Node(L, R, nums[L]);
        }

        Node* node = new Node(L, R, 0);
        int M = (L + R) / 2;
        node->left = build(nums, L, M);
        node->right = build(nums, M + 1, R);

        node->sum = node->left->sum + node->right->sum;
        
        return node;
    }

    void update(Node* node, int index, int val)
    {
        if (node->L >= node->R && node->L == index)
        {
            node->sum = val;
            return;
        }

        int M = (node->L + node->R) / 2;
        if (index <= M)
        {
            update(node->left, index, val);
        }
        else
        {
            update(node->right, index, val);
        }

        node->sum = node->left->sum + node->right->sum;
    }
    
    void update(int index, int val) 
    {
        update(root, index, val);
    }

    int query(Node* node, int L, int R)
    {
        if (node->L == L && node->R == R)
        {
            return node->sum;
        }

        int M = (node->L + node->R) / 2;

        if (R <= M)
        {
            return query(node->left, L, R);
        }
        else if (L > M)
        {
            return query(node->right, L, R);
        }

        return query(node->left, L, M) + query(node->right, M + 1, R);
    }
    
    int query(int L, int R) 
    {
        return query(root, L, R);
    }
};
