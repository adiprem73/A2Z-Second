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

vector<vector<int>> findFarmland(vector<vector<int>> &land)
{
    // we will try to solve this using bfs
    int m = land.size();
    int n = land[0].size();

    vector<vector<bool>> vis (m, vector<bool>(n, false));

    queue<pair<int,int>> q;
    vector<vector<int>> ans;

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vector<int> curr;
            if(land[i][j]==1 && vis[i][j]==false){
                q.push({i,j});
                vis[i][j]= true;
                curr.push_back(i);
                curr.push_back(j);
            }
            int g=-1,h=-1;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                g=max(g,x);
                h=max(h,y);
                for(int i=0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny] == false && land[nx][ny] == 1){
                        q.push({nx,ny});
                        vis[nx][ny]= true;
                    }
                }
            }
            if(g!=-1 && h!=-1){
                curr.push_back(g);
            curr.push_back(h);
            ans.push_back(curr);
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