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

void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>>&grid, int &area){
    vis[x][y]= true;
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && vis[nx][ny] == false)
        {
            area+=1;
            dfs(nx, ny, vis, grid, area);
        }
    }
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> vis (m, vector<bool> (n, false));
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && vis[i][j]== false){
                int area =0;
                dfs(i, j, vis, grid, area);
                ans= max(ans, area);
            }
        }
    }
    return ans;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem