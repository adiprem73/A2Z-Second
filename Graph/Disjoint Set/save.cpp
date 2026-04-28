class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        bool flag = false;
        int bp = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                bp = i;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            sort(nums.begin(), nums.end());
        }
        else
        {
            for (int i = bp + 1; i < n; i++)
            {
                if (nums[i] > nums[bp])
                {
                    swap(nums[i], nums[bp]);
                }
            }
        }
    }
};