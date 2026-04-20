class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> res;
        for (int j = 0; j < n; ++j) {
            while (!dq.empty() && nums[dq.back()] <= nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if (j >= k - 1) {
                res.push_back(nums[dq.front()]);
                int i = j - k + 1;
                if (dq[0] <= i) {
                    dq.pop_front();
                }
            }
        }

        return res;
    }
};
