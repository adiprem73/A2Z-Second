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


void dfs(int u, vector<vector<int>>& adj, vector<bool> & visited, int& count){
    // first thing is to makr that node as visited
    visited[u]= true;
    count++;

    for(auto neighbour : adj[u]){
        if(visited[neighbour]== false){
            dfs(neighbour, adj, visited, count);
        }
    }
}

// (x-a)2 + (y-b)2 = r2

int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> adj(n);

    // make the adjacency vector based on what bombs will detoaonte what bombs
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                long long g = bombs[i][0] - bombs[j][0];
                long long h = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                if (g*g + h*h <= r*r)
                {
                    adj[i].push_back(j);
                }
            }
        }
    } 
    
    // then we just need to find the length of the maximum spanning tree
    int ans =0;
    
    for(int i=0;i<n;i++){
        // we msut perform fresh detonations and fresh chain reactions for eahc node and then take the maximum one
        int count = 0;
        vector<bool> visited(n, false);
        dfs(i, adj, visited, count);
        ans = max(ans, count);
    }
    return ans;
}

int main() {
    FAST_IO;
    vector<vector<int>> bombs = {{2,1,3}, {6,1,4}};
    cout<<maximumDetonation(bombs);
    return 0;
}

// by ad73prem