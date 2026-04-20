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

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it: times){
        adj[it[0]].push_back({it[1], it[2]}); // {node, time}
    }
    // the adjacency list is ready now
    vector<int> time(n+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, k}); //{time, node}
    time[k]= 0;
    while(!pq.empty()){
        auto [timeTaken, node] = pq.top();
        pq.pop();
        for(auto neigh : adj[node]){
            int wt = neigh.second;
            int nd = neigh.first;
            if(time[nd] > timeTaken+wt){
                time[nd] =  timeTaken+wt; // relaxed
                pq.push({timeTaken+wt, nd});
            }
        }
    }
    int sum =0;
    for(auto it: time){
        if(it == 1e9)return -1;
        else{
            sum+=it;
        }
    }
    return sum;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem