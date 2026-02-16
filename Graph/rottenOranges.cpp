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

// 0 is empty, 1 is ripe, and 2 is rotten

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size(); // number of rows
    int n = grid[0].size(); // number of cols

    // for such question we always do bfs. since we need to move in four directions and bfs naturally takes the motions of four directions
    // bfs in grpahs requires a queue
    // each entry in the queue will the (i, j, time). 
    // the starting points of the bfs will be those which ocntaitn '2' that is which are rotten
    queue<vector<int>>q;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {-1, 0, 1, 0};
    int countFresh = 0;
    // here the rottening occurs from each rotten orange at once. and not one by one
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j,0});
            }else if(grid[i][j]==1){
                countFresh++;
            }
        }
    }

    int ansTime =0;
    
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        int x = node[0];
        int y = node[1];
        int time = node[2];
        ansTime= max(ansTime, time);
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                q.push({nx, ny, time+1});
                grid[nx][ny] = 2;
                countFresh--;
            }
        }
    }
           
    // now if all the cells have been visited, then we can return the ansTime or else we will return -1
    if(countFresh == 0)return ansTime;
    else return -1;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem