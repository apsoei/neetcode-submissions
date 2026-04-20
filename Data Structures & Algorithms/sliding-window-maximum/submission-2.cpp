class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        // monotonic decreasing (storing index instead of value)
        deque<int> dq;

        int L = 0;
        int n = nums.size();
        vector<int> res;
        for (int R = 0; R < n; ++R)
        {
            // maintain monotonic decrasing deque
            while (!dq.empty() && nums[dq.back()] < nums[R])
            {
                dq.pop_back();
            }
            dq.push_back(R);

            if (L > dq.front())
            {
                dq.pop_front();
            }

            if (R + 1 >= k)
            {
                res.push_back(nums[dq.front()]);
                L++;
            }
        }

        return res;
    }
};
