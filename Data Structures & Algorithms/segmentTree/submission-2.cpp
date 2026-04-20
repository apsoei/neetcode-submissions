class SegmentTree {
public:
    SegmentTree* left = nullptr;
    SegmentTree* right = nullptr;
    int L, R, sum;
    SegmentTree(int total, int L, int R): sum(total), L(L), R(R) {}

    SegmentTree(vector<int>& nums) {
        SegmentTree* root = build(nums, 0, nums.size() - 1);
        // *this = *root;
        // delete root;
        this->left = root->left;
        this->right = root->right;
        this->sum = root->sum;
        this->L = root->L;
        this->R = root->R;
    }

    static SegmentTree* build(vector<int>& nums, int L, int R) {
        if (L >= R) {
            return new SegmentTree(nums[L], L, R);
        }

        int M = (L + R) / 2;
        auto node = new SegmentTree(0, L, R);
        node->left = build(nums, L, M);
        node->right = build(nums, M + 1, R);

        node->sum = node->left->sum + node->right->sum;
        
        return node;
    }
    
    void update(int index, int val) {
        if (L == R) {
            sum = val;
            return;
        }

        int M = (L + R) / 2;
        if (index <= M) {
            left->update(index, val);
        } else {
            right->update(index, val);
        }

        sum = left->sum + right->sum;
    }
    
    int query(int L, int R) {
        if (this->L == L && this->R == R) {
            return sum;
        }

        int thisM = (this->L + this->R) / 2;

        if (L > thisM) {
            return this->right->query(L, R);
        } else if (R <= thisM) {
            return this->left->query(L, R);
        } else {
            return this->left->query(L, thisM) + this->right->query(thisM + 1, R);
        }
        
    }
};
