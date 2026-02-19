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

vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
{
    // first we will paply topo sort to find the orders for both row conditions and col conditions
    // topo sosrt to find the order for rwo conditons
    vector<vector<int>> adjRow (k);
    for(auto it: rowConditions){
        adjRow[it[0]].push_back(it[1]);
    }
    // now we have prepared the adjacency vector
    vector<int> indegree(k);
    for(auto it: adjRow){
        for(auto itr: it){
            indegree[itr] ++;
        }
    }   
    queue<int> q;
    vector<int> topoRow;
    for(int i=0;i<k;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoRow.push_back(node);
        for(auto it: adjRow[node]){
            indegree[it--];
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    // now we will need to do the same for column as well
    vector<int> topoCol;
    vector<vector<int>> adjCol(k);
    for (auto it : colConditions)
    {
        adjCol[it[0]].push_back(it[1]);
    }
    vector<int> indegree2(k);
    for (auto it : adjCol)
    {
        for (auto itr : it)
        {
            indegree2[itr]++;
        }
    }
    queue<int> q2;
    for (int i = 0; i < k; i++)
    {
        if (indegree2[i] == 0)
        {
            q2.push(i);
        }
    }

    while (!q2.empty())
    {
        int node = q2.front();
        q2.pop();
        topoCol.push_back(node);
        for (auto it : adjCol[node])
        {
            indegree2[it--];
            if (indegree2[it] == 0)
            {
                q2.push(it);
            }
        }
    }

    // now we have built the topo row and topo col
    map<int,int> mpRow, mpCol;
    for(int i=0;i<k;i++){
        mpRow[topoRow[i]]= i;
        mpCol[topoCol[i]]= i;
    }

    vector<vector<int>> ans(k, vector<int>(k,0));
    for(int i=0;i<k;i++){
        int x = mpRow[topoRow[i]];
        int y = mpCol[topoRow[i]];
        ans[x][y] = topoRow[i];
    }

    return ans;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem