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

void dfs(int u, vector<vector<int>> & adj, vector<bool> &vis, int &nodes){
    for(auto neigh : adj[u]){
        if(vis[neigh] == false){
            vis[neigh] = true;
            nodes++;
            dfs(neigh, adj, vis, nodes);
        }
    }
}

long long countPairs(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    // the idea here is the we will start fresh dfs from each node and then based on the visited array we will count the unvisited from eahc dfs --> this idea will give TLE

    // the next idea is to find the number of ndoes in each connected components. suppose it comes out to be {s1, s2, s3, ..}. then the final answe will be s1*s2 + s2*s3 + ...
    vector<int> nos;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]= true;
            int nodes =1;
            dfs(i, adj, vis, nodes);
            nos.push_back(nodes);
        }
    }
    long long ans=0;
    for(int i=0;i<nos.size()-1;i++){
        ans+= nos[i]*nos[i+1];
    }
    return ans;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem