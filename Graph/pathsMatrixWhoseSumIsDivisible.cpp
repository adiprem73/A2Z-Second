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

void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> & vis, int & m, int & n, int & sum, int & k, long long & ans){
    sum+=grid[r][c];
    vis[r][c]= 1; // makr visited
    // base case
    if(r == m-1 && c == n-1){ // destination reached
        if(sum%k== 0){
            ans++;
        }
    }

    if(r+1<m && vis[r+1][c] == 0){
        dfs(r+1, c, grid, vis, m, n, sum, k, ans);
    }
    if(c+1<n && vis[r][c+1]==0){
        dfs(r, c+1, grid, vis, m, n, sum, k, ans);
    }
    sum-= grid[r][c];
    vis[r][c] =0; // unvisit for backtracking
}

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int> (n, 0));
    int sum=0;
    long long ans =0;
    dfs(0,0, grid, vis, m, n, sum, k, ans);
    int mod = 1000000007;
    int ans2 = ans % mod;
    return ans2;
}

int main() {
    FAST_IO;
    vector<vector<int>> grid = {{7,3,4,9},{2,3,6,2},{2,3,7,0}};
    cout<<numberOfPaths(grid, 1);
    return 0;
}

// by ad73prem