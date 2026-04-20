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

// Djikstra fails when graphs have negative cycles. hence bellman fords allows for detecting negative cycles. it specially tells when a negative cycles is present. it tells wehn a path weight is negative in total

// ✅✅ Relax all the edges N-1 times sequentially. Edges can be in any order
// Relax means if(dist[u] + wt)<dist[v] then we do dist[v]=  dist[u] + wt
// 🤔⁉️ Why n-1 cycles? --> This is bcoz any shortest path in a graph can have at most n-1 edges. since ballman-ford works by relaxing the apths one edge longer per iteration, we need to perform n-1 iteratyions
// how to detect negative cycles? --> on nth iteration, the relaxation will be done. if the dist[i] still reduces then its negative cycles

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S){
    vector<int> dist(V, 1e9);
    dist[S] =0;
    for(int i=0;i<V-1;i++){ // for n-1 cycles
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // to check for the negative cycles(Nth relaxation)
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e9 && dist[u] + wt < dist[v])
        {
            return {-1}; // since relaxation is still possible. hence we detect negative cycles and hence we return -1
        }
    }

    return dist;
}

int main() {
    FAST_IO;
    return 0;
}

// by ad73prem