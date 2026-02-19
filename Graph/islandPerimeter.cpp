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

int islandPerimeter(vector<vector<int>> & grid){
    int m = grid.size();
    int n = grid[0].size();
    int ans =0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]== 1){
                if(i==0)ans++;
                if(i==m-1)ans++;
                if(j==0 )ans++;
                if(j==n-1)ans++;
                if(i>0 && grid[i-1][j]==0)ans++;
                if(i<m-1 && grid[i+1][j]==0)ans++;
                if(j>0 && grid[i][j-1] == 0)ans++;
                if(j<n-1 && grid[i][j+1]==0)ans++;
            }
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    // vmat grid = {
    //     {0,1,0,0},
    //     {1,1,1,0},
    //     {0,1,0,0},
    //     {1,1,0,0}
    // };

    vmat grid = {{1,0}};
    cout<<islandPerimeter(grid);
    return 0;
}

// by ad73prem