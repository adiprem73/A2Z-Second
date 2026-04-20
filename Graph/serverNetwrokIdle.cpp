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

int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
{
    unordered_map<int, vector<int>> adj;
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int n = patience.size();
    // the adjacency list is ready now
    vector<int> time(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0}); //{time, node}
    time[0] = 0;
    while (!pq.empty())
    {
        auto [timeTaken, node] = pq.top();
        cout<< " Node : "<<node<<endl;
        pq.pop();
        for (auto neigh : adj[node])
        {
            if (time[neigh] > timeTaken + 1)
            {
                time[neigh] = timeTaken + 1; // relaxed
                pq.push({timeTaken + 1, neigh});
            }
        }
    }
    int ans = INT_MIN;
    for(int i=1;i<n;i++){
        int x =0;
        if(2* time[i] <= patience[i]){
            x = 2* time[i];
        }else if((2* time[i]) %patience[i] == 0){
            x = 2* time[i] + (2* time[i] - patience[i]);
        }else{
            x = 4* time[i] - ((2*time[i] )% patience[i]);
        }
        ans = max(ans, x);
    }
    return ans;
}

int main()
{
    FAST_IO;
    vector<vector<int>> edges= {{0,1},{1,2}};
    vector<int> patience = {0,2,1};
    networkBecomesIdle(edges, patience);
    return 0;
}

// by ad73prem