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

// KAHN's algorithm
// TOPO SORT is only valid in a DAG (Directed Acyclic Graphs)
// here we do BFS + concepts of InDegree
// indegree is the number of incoming edges of a node

// #1 mark indegrees of all the elements
// #2 place the elements with zero 0 indegree into the queue 
// #3 now traverse trhough the queue. and take them out from the graph. this will reduce the indegrees of some elements. now since we took some elements, some elements indegree will become zero. now add those elements into the queue. repeat 🔁🔁

// insert all the nodes with indegree zero into the queue... take them out of the graph and then reudce the indegrees of other elements to zero and then repeat

// if there are cycles in the graph, then topo sort skips those elements

vector<int> toposort(int V, vector<vector<int>> adj){
    vector<int> indegrees(V,0);
    for(auto it: adj){
        for (int node: it){
            indegrees[node]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegrees[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // removing that node while reducing the indegrees
        for(auto it: adj[node]){
            indegrees[it]--;
            if(indegrees[it]==0){
                q.push(it);
            }
        }


    }
    return topo;
}

int main() {
    FAST_IO;
    return 0;
}

// by ad73prem