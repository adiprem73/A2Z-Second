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

int minimumEffortPath(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> vis(m, vector<int>(n,0));
    priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<>>pq;
    pq.push({0, {0,0}});
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0, 1, 0, -1};
    while(!pq.empty()){
        auto [dist, coordinates] = pq.top();
        pq.pop();
        int r = coordinates.first;
        int c = coordinates.second;
        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0){

            }
        }
    }

}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem