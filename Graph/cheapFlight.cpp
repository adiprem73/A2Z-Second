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


// (from, to , price)
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int,int>>> adj(n);
    vector<vector<int>> costs(n, vector<int>(k+2, 1e9));
    for(auto it: flights){
        adj[it[0]].push_back({it[1], it[2]}); 
    }
    // we have made the matrix
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, src}});  // (cost,(steps, city))
    costs[src][0] = 0;
    while(!pq.empty()){
        auto [cost, temp] = pq.top();
        int city = temp.second;
        int steps = temp.first;
        pq.pop();

        if (steps > k)
            continue;
        if (city == dst)
        {
            return cost;
        }

        for(auto it: adj[city]){
            auto extraCost = it.second;
            auto stop = it.first;
            if(cost+extraCost < costs[stop][steps+1]){
                pq.push({cost+extraCost, {steps+1,stop}});
                costs[stop][steps+1] = cost+extraCost;
            }
        }
    }
    return -1;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem