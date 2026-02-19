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

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int m = image.size();
    int n = image[0].size();
    // let us do this quesitons by using BFS
    queue<pair<int,int>>q;
    q.push({sr,sc});
    vector<int> dx = {-1, 0, 1 , 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<vector<bool>> visited(m, vector<bool>(n,false));
    visited[sr][sc]= true;
    while(!q.empty()){
        // we mustmove in all four directions 
        auto [x, y] = q.front();
        q.pop();
        int prevcolor = image[x][y];
        image[x][y]= color;
        // we do not need to perform layer by layer bfs so we will jsut do normal bfs
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && visited[nx][ny]==false && image[nx][ny] == prevcolor){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return image;
}

int main()
{
    FAST_IO;
    vector<vector<int>> image = {
        {0,0,0},
        {0,0,0}
    };
    vmat ans =  floodFill(image, 1, 0, 2);
    for(auto it: ans){
        vprint(it);
    }
    return 0;
}

// by ad73prem