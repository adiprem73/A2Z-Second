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

int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
{
    vector<vector<int>> adj(n+1);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> dist1(n+1, 1e9);
    vector<int> dist2(n + 1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [curTime, node] = pq.top();
        pq.pop();
        if (curTime > dist2[node])
            continue;
        int sig= curTime/change;
        if ((curTime / change) % 2 == 1)
        {
            curTime = (curTime / change + 1) * change;
        }
        for(auto neigh : adj[node]){
            if(curTime + time < dist1[neigh]){
                dist1[neigh] = curTime+ time;
                pq.push({dist1[neigh] , neigh});
            }else if(curTime + time < dist2[neigh] && curTime+time > dist1[neigh]){
                dist2[neigh] = curTime + time;
                pq.push({dist2[neigh], neigh});
            }
        }
    }
    return dist2[n];
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem