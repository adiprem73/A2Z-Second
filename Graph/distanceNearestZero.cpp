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

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    // we will iterate from every zero and keep on updating the distance of each cell from it
    queue<pair<int,int>>q;
    int m = mat.size();
    int n = mat[0].size();
    // vector<vector<int>> ans(m, vector<int>(n, 1e9));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                q.push({i,j});
            }else{
                mat[i][j]= 1e9;
            }
        }
    }
    vector<int> dx={-1, 0, 1, 0};
    vector<int> dy={0, 1, 0, -1};
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        auto [x,y] = node;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny]> mat[x][y]+1){
                q.push({nx,ny});
                mat[nx][ny] = mat[x][y]+1;
            }
        }
    }
    return mat;
}

int main()
{
    FAST_IO;
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> ans = updateMatrix(mat);
    for(auto it : ans){
        vprint(it);
    }
    return 0;
}

// by ad73prem