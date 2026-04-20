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

vector<int> djikstra(int V, vector<vector<pair<int,int>>> & adj, int src){
    // djikstra algo will return the distance (shortest) of each node from the one source node
    // it uses oriority queue for this (min heap)
    vector<int> dist(V, INT_MAX);
    dist[src]=0; //mark the distance of the soruce to the soruce as zero
    // make the priority queue and isnert the src node in it
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src}); // the format would be {distance, source node}

    // main loop of djikstra
    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();

        // we will add a conditions so that if the idstance already assigned is shorter thatn this distance then we should not do anything more
        if(d > dist[node] )continue;

        for(auto [nbrNode, nbrWeight]: adj[node]){
            if(dist[node] + nbrWeight < dist[nbrNode]){
                dist[nbrNode]= dist[node] + nbrWeight;
                pq.push({dist[nbrNode], nbrNode});
            }
        }
    }
    return dist;
}

int main() {
    FAST_IO;
    return 0;
}

// by ad73prem