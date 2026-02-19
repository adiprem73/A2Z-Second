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

bool dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &grid1, vector<vector<int>> & grid2)
{
    vis[x][y] = true;
    int m = grid1.size();
    int n = grid1[0].size();
    bool isSub = (grid1[x][y] == 1); 
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid2[nx][ny] == 1 && vis[nx][ny] == false)
        {
            if(dfs(nx, ny, vis, grid1, grid2)==false){
                isSub = false;
            }
            
        }
    }
    return isSub;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int m = grid1.size();
    int n = grid1[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == false && grid2[i][j] == 1 )
            {
                if(dfs(i, j, vis, grid1, grid2)){
                    cnt++;
                }                
            }
        }
    }
    return cnt;
}

int main() {
    FAST_IO;
    return 0;
}

// by ad73prem