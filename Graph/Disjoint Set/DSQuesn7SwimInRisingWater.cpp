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

void dfs(int r, int c, int n, int currCost, vector<vector<int>>& grid, vector<vector<int>>&vis, int &ans){
    vis[r][c]= 1;
    int dx[]= {-1,0,1,0};
    int dy[]={0,1,0,-1};

    if(r == n-1 && c == n-1){
        ans = min(ans, currCost);
        vis[r][c]=0;
        return;
    }


    // travelling in four directions
    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc] == 0){
            int newCost = max(currCost, grid[nr][nc]);
            dfs(nr,nc,n,newCost, grid, vis, ans);
        }
    }
    vis[r][c]=0; //backtracking required to explore all paths
}

int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    int ans = INT_MAX;
    vector<vector<int>>vis(n, vector<int>(n,0));
    dfs(0,0,n,grid[0][0], grid, vis, ans);
    return ans;
}

int swimInWater2(vector<vector<int>>& grid){
    int n = grid.size();

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    vector<vector<int>> vis(n, vector<int>(n,0));

    pq.push({grid[0][0],{0,0}});

    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int cost = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if(vis[r][c]==1)continue;

        vis[r][c]=1;

        // base case
        if(r == n-1 && c== n-1){
            return cost;
        }

        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];

            if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                int newCost = max(cost, grid[nr][nc]);

                pq.push({newCost, {nr,nc}});
            }
        }
    }
    return -1;
}

int main()
{
    FAST_IO;
    // grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
    vector<vector<int>> grid = {
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };
    cout<<swimInWater2(grid);
    return 0;
}

// by ad73prem