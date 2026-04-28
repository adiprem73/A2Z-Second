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

void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<pair<int, int>>> &dir, int m, int n, vector<vector<bool>>& vis){
    vis[r][c]= true;
    auto movement = dir[grid[r][c]];
    for(auto it: movement){
        int nr = r+it.first;
        int nc = c+it.second;
        if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==false){
            for(auto back: dir[grid[nr][nc]]){
                if(back.first == -1*it.first && back.second == -1*it.second){
                    dfs(nr, nc, grid, dir, m, n, vis);
                    break;
                }
            }
            
        }
    }
}

bool hasValidPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis (m, vector<bool>(n, false));
    vector<vector<pair<int,int>>> dir ={
        {},
        {{0,-1},{0,1}},
        {{-1,0},{1,0}},
        {{0,-1},{1,0}},
        {{1,0},{0,1}},
        {{0,-1},{-1,0}},
        {{-1,0},{0,1}}
    };
    dfs(0,0,grid,dir,m,n,vis);
    if(vis[m-1][n-1]==true){
        return true;
    }else return false;
}

int main() {
    FAST_IO;
    // vector<vector<int>> nums = {
    //     {2,4,3},
    //     {6,5,2}
    // };

    vector<vector<int>> nums = {
        {1,1,2}};
    cout<<hasValidPath(nums);
    return 0;
}

// by ad73prem