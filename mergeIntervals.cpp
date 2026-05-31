#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mii map<int, int>
#define mll map<ll, ll>

#define vprint(v)         \
    for (auto &e : v)     \
        cout << e << " "; \
    cout << endl;
#define mprint(m)                                     \
    for (auto &p : m)                                 \
        cout << p.first << " : " << p.second << endl; \
    cout << endl;

#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int INF = 1e9;
const ll MOD = 1e9 + 7;

// -------- Linked List Definition --------
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// -------- Binary Tree Definition --------
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    bool is_last_merged = false;
    sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b)
         {
        if(a[0]==b[0])return a[1]<b[1];
        else return a[0]<b[0]; });
    for (int i = 0; i < n - 1; i++)
    {
        if (intervals[i][0] <= intervals[i + 1][0] && intervals[i][1] >= intervals[i + 1][1])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        if (intervals[i][1] >= intervals[i + 1][0])
        {
            ans.push_back({intervals[i][0], intervals[i + 1][1]});
            if (i == n - 2)
            {
                is_last_merged = true;
            }
            i++;
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    if (!is_last_merged)
    {
        ans.push_back(intervals[n - 1]);
    }
    return ans;
}

bool isOverlap(int curr, int curr2, vector<vector<int>> &intervals)
{
    auto interval1 = intervals[curr];
    auto interval2 = intervals[curr2];

    if ((interval1[1] >= interval2[0] && interval1[1] <= interval2[1]) || (interval1[0] < interval2[0] && interval1[1] >= interval2[1]))
        return true;

    else
        return false;
}

vector<int> join(int curr, int curr2, vector<vector<int>> &intervals)
{
    int x1 = intervals[curr][0];
    int x2 = intervals[curr][1];
    int x3 = intervals[curr2][0];
    int x4 = intervals[curr2][1];
    int x = min(x1, x2);
    int y = max(x3, x4);
    return {x, y};
}

vector<vector<int>> merge2(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b)
         {
        if(a[0]==b[0])return a[1]<b[1];
        else return a[0]<b[0]; });

    int currInterval = 0;
    vector<vector<int>> ans;
    while (true)
    {
        if (isOverlap(currInterval, currInterval + 1, intervals))
        {
            auto it = join(currInterval, currInterval + 1, intervals);
            ans.push_back(it);
        }
        else
        {
            ans.push_back(intervals[currInterval]);
            currInterval++;
        }
    }
    for (auto it : ans)
    {
        vprint(it);
    }
    return ans;
}

vector<vector<int>> mergeFinal(vector<vector<int>> & intervals){
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    ans.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(ans.back()[1] >= intervals[i][0]){
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }else{
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

int main()
{
    FAST_IO;
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    merge(nums);
    return 0;
}

// by ad73prem