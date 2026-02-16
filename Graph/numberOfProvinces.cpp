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

// Goal:
// Count number of connected components (provinces) in a graph.

// Input format:
// isConnected[i][j] = 1 means city i is connected to city j.
// This represents an adjacency matrix of a graph.

// Step 1: Convert adjacency matrix → adjacency list
// Reason:
// DFS traversal is easier and cleaner with adjacency list representation.

// Step 2: Build adjacency list
// For every pair (i, j):
// if matrix[i][j] == 1 → add edge between i and j
// Since graph is undirected → add both directions.

// Step 3: Create visited array
// Purpose:
// Prevent revisiting nodes
// Avoid infinite recursion
// Ensure each node processed once

// Step 4: DFS function logic
// When DFS is called on node u:
// 1. Mark u as visited
// 2. Traverse all neighbors of u
// 3. For each unvisited neighbor → recursively call DFS
// Effect:
// Entire connected component gets marked visited

// Step 5: Count provinces
// Loop through all nodes:
// If a node is not visited →
// it belongs to a new connected component
// Call DFS from that node
// Increase province count

// Key Insight:
// Each DFS call = exactly one connected component discovered.

// Time Complexity:
// Building adjacency list → O(n²)
// DFS traversal → O(V + E)
// Overall → O(n²) due to matrix scan

// Final Result:
// cnt stores number of provinces (connected components)


void dfs(int u, vector<vector<int>> &adj, vector<bool> & visited){
    // mark this visited
    visited[u]= true;
    for(auto neighbours: adj[u]){ // traverse through all the neighbouring nodes
        if(visited[neighbours] == false){
            dfs(neighbours, adj, visited);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    // the very first thing to do will be to convert the graph from matrix form to vector form so that we can perform  our traversals easily
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // we will maintain a count variable to count the number of times dfs gets called from this main function: this will only give the correct number of provinces
    int cnt=0;


    // now first we will try for a dfs approach
    // for this we will need a visited array as well so that we do not go aorund in circles
    vector<bool> visited(n);
    for(int i=0;i<n;i++){
        if(visited[i]== false){
            dfs(i, adj, visited);
            cnt++;
        }
    }
    return cnt;
}

// we can also do hte above questions without ever changin it into adjaceny list. we can do directly dfs on adjacency matrix

void dfs2( int u ,vector<vector<int>> &isConnected, vector<bool> &visited){
    // mark this as visited
    visited[u]= true;
    int n= isConnected.size();
    for(int i=0;i<n;i++){
        if(isConnected[u][i]==1 && visited[i]== false){
            // then this node is not visited yet
            dfs2(i, isConnected, visited);
        }
    }
}

    int findCircleNum2(vector<vector<int>> &isConnected)
{
    // make a visited matrix
    int n = isConnected.size();
    vector<bool> visited(n);
    // the basic idea is that the idea of neighbourship we get is from the j component of the i node. 
    int cnt=0;
    for(int i=0;i<n;i++){
        if(visited[i]== false){
            dfs2(i, isConnected, visited);
            cnt++;
        }
    }
}

int main() {
    FAST_IO;
    return 0;
}

// by ad73prem