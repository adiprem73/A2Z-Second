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

// MINIMUM SPANNING TREE
// a tree in which we have n nodes and n-1 edhes. all nodes must be reachable to each other
// Point to remember is that a graph may have more than one spanning trees.Among all possible spanning trees of a graph, the minimum spanning tree is the one for which the sum of all the edge weights is the minimum.

// PRIM'S ALGORITHM: helps in finding the MST
// priority queue: (wt, node, parent)
// starts with any given node
// we do not mark them visited when inserting into the min. heap.

// we need ot take the parent node in the pq only when we need to get the mst. if we only need the sum of the mst then not needed. only (weight , node)

int spanningTree(int V, vector<vector<int>> &adj[]){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> vis(V, 0);

    pq.push({0,0});
    int sum =0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if(vis[node] == 1) continue;
        vis[node]= 1; // we mark them visited when we add it to the mst
        sum+= wt;

        for(auto neigh : adj[node]){
            int adjNode = neigh[0];
            int edWt = neigh[1];

            if(!vis[adjNode]){
                pq.push({edWt, adjNode});
            }
        }
    }
    return sum;
}


int main() {
    FAST_IO;
    return 0;
}

// by ad73prem