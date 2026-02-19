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

void func(int currNode, int n, int currheight, int &height, vector<vector<int>>& adj, vector<int>& visit){
    visit[currNode]= 1;
    height = max(height, currheight);
    for(auto neighbours: adj[currNode]){
        if(visit[neighbours]== 0){
            func(neighbours, n, currheight+1, height, adj, visit);
        }
    }
}

int findHeight(int root, int n, vector<vector<int>>& adj){
    int currHeight =0;
    int height =0;
    vector<int> visited(n);
    func(root, n, currHeight, height, adj, visited);
    return height;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    // first we need to make the adjacency list
    vector<vector<int>> adj(n);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    map<int, int> mp;
    int minHeight =n;
    for(int i=0;i<n;i++){
        mp[i] = findHeight(i, n, adj);
        minHeight= min(minHeight, mp[i]);
    }
    vector<int> ans;
    for(auto it: mp){
        if(it.second == minHeight){
            ans.push_back(it.first);
        }
    }
    return ans;
}

vector<int> findMinHeightTrees2(int n, vector<vector<int>> &edges){
    // first we need to make the adjacency list
    vector<vector<int>> adj(n);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // the idea here is that we will find all the leaf nodes. that is those with their indegree as 1. then we will remove them one by one layer by layer evenly from all sides which will give us the answer at last

    // first find the indregree of each elelment
    vector<int> indegrees(n);
    for(auto it: edges){
        for(auto itr: it){
            indegrees[itr]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegrees[i]==1){
            q.push(i);
        }
    }
    int remaining= n;

    while (remaining > 2)
    {
        int size = q.size();
        remaining -= size;

        while (size--)
        {
            int node = q.front();
            q.pop();

            for (auto nei : adj[node])
            {
                indegrees[nei]--;
                if (indegrees[nei] == 1)
                    q.push(nei);
            }
        }
    }

    vector<int> ans;
    while(q.empty()== false){
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}

int main()
{
    FAST_IO;
    vector<vector<int>> edges= {{3,0},{3,1},{3,2},{3,4},{5,4}};
    vector<int> ans = findMinHeightTrees2(6, edges);
    vprint(ans);
    return 0;
}

// by ad73prem