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

#define vprint(v) for (auto &e : v) cout << e << " "; cout << endl;
#define mprint(m) for (auto &p : m) cout << p.first << " : " << p.second << endl; cout << endl;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int INF = 1e9;
const ll MOD = 1e9 + 7;

// -------- Linked List Definition --------
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// -------- Binary Tree Definition --------
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countDays(int days, vector<vector<int>> &meetings)
{
    vector<vector<int>> mergedIntervals;
    sort(meetings.begin(), meetings.end());
    mergedIntervals.push_back(meetings[0]);
    int n = meetings.size();
    for(int i=1;i<n;i++){
        if(meetings[i][0]<=mergedIntervals.back()[1]){
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], meetings[i][1]);
        }else{
            mergedIntervals.push_back(meetings[i]);
        }
    }
    int totalSpread =0;
    for(auto it: mergedIntervals){
        vprint(it);
        int diff = it[1]-it[0]+1;
        totalSpread+=diff;
    }
    return days - totalSpread;
}

int main()
{
    FAST_IO;
    vector<vector<int>> meetings = {{2,4},{1,3}};
    cout<<countDays(5,meetings);
    return 0;
}

// by ad73prem