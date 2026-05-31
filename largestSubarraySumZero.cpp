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

// 15  -2  2  -8  1  7  10  23

int maxLen(vector<int>& arr) {
    int n = arr.size();
    int l =0;
    int r =0;
    int ans =0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==0){
                ans= max(ans, j-i+1);
            }
        }
    }
    return ans;
}

int maxLen2(vector<int>& arr){
    int n = arr.size();
    map<int,int>mp;
    int sum=0, mx=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            mx= max(mx, i+1);
        }else{
            if(mp.count(sum)>0){
                mx = max(mx, i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
    }
    return mx;
}

int main() {
    FAST_IO;
    vint nums = {1, 0, -4, 3, 1, 0};
    cout<<maxLen2(nums);
    return 0;
}

// by ad73prem