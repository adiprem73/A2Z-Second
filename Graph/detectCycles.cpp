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

bool dfs(int u, int v, vector<vector<int>> &adj, vector<bool> & visit){
    visit[u]= true;
    for(auto neighbour : adj[u]){
        if(visit[neighbour]==false){
            if(dfs(neighbour, u, adj, visit)){
                return true;
            }
        }else if(neighbour != v){
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> adj)
{
    vector<bool> visit (V, false);
    for(int i=0;i<V;i++){
        if(visit[i]== false){
            if(dfs(i, -1, adj, visit)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem