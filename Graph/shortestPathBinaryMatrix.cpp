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

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    int n = grid.size();
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
    // make a visited matrix
    vector<vector<int>> vis(n, vector<int>(n, 0));
    // make a queue that can store (row, col, steps)
    queue<pair<pair<int, int>, int>> q; // (row, col, steps)
    // we always start with the starting node (0,0)
    q.push({{0,0},1});
    vis[0][0] = 1;

    while(!q.empty()){
        auto [coordinates, dist]= q.front();
        q.pop();
        int r = coordinates.first;
        int c = coordinates.second;
        if(r==n-1 && c == n-1)return dist;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nr =r+i;
                int nc =c+j;
                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nc][nr] == 0 && grid[nc][nr] != 1){
                    vis[nr][nc]= 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    FAST_IO;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    cout<<shortestPathBinaryMatrix(grid);
    return 0;
}

// by ad73prem