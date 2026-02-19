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

// BIPARTITE: if we can color the grpahs with two colors such that no adjacent nodes have the same color

// Linear graphs with no cycles are bipartite
// any graph with cycle length even can also be bipartite

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n ,-1); // -1: shows that the node is not yet colored
    for(int i=0;i<n;i++){
        if(color[i]==-1){
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

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem