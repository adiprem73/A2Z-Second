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

// Can the graph be bipartite?
// if Yes: then we can split it into grps
// if No: return -1

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1); // -1: shows that the node is not yet colored
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto neigh : graph[node])
                {
                    if (color[neigh] == -1)
                    {
                        color[neigh] = !color[node];
                        q.push(neigh);
                    }
                    else
                    {
                        if (color[neigh] == color[node])
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int bfs(vector<vector<int>> adj, int currNode, int n){
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(currNode);
    visited[currNode]= true;

    int level = 1;
    while(!q.empty()){
        int size = q.size();
        while(size --){
            int curr = q.front();
            q.pop();

            for(int & ngbr : adj[curr]){
                if(visited[ngbr])continue;

                q.push(ngbr);
                visited[ngbr]= true;
            }
        }
        level++; // one extra will be implemented
    }
    return level-1;
}

int getMaxFromEachComp(vector<vector<int>> adj, int curr, vector<bool>& visited, vector<int>&levels){
    int maxGroup = levels[curr];
    visited[curr]= true;

    for(int & ngbr: adj[curr]){
        if(!visited[ngbr]){
            maxGroup = max(maxGroup, getMaxFromEachComp(adj, ngbr, visited, levels));
        }
    }
    return maxGroup;
}

    int magnificentSets(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n+1);
    for(auto it: edges){
        adj[it[1]-1].push_back(it[0]-1);
        adj[it[0]-1].push_back(it[1]-1);
    }
    if(isBipartite(adj) == false){
        return -1;
    }
    
    // now we will do bfs from each node, so that all disconnected graphs are included. we will count the maximum levels of each bfs and then we will take the sum
    
    vector<int> levels(n,0);
    for(int i=0;i<n;i++){
        levels[i] = bfs(adj, i, n);
    }

    int maxGroupEachComp = 0;
    vector<bool> visited(n, false);
    for(int node =0;node<n;node++){
        if(!visited[node]){
            maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
        }
    }
    return maxGroupEachComp;

}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem