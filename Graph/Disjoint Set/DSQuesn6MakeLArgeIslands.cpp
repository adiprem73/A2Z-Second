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

class DisjointSet
{

public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]); // this is how path compression would take place. we store the parent in parent[node]
    }
    // Union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool isValid(int newr, int newc , int n){
    return newr>=0 && newr<n && newc>=0 && newc<n;
}

int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet ds(n*n);
    for(int row =0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col] == 0)continue;
            int dr[]= {-1,0,1,0};
            int dc[]= {0,-1,0,1};
            for(int ind =0; ind<4;ind++){
                int newr = row+dr[ind];
                int newc = col+dc[ind];
                if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                    int nodeNo = row*n + col;
                    int adjNodeNo = newr*n + newc;
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }
    int mx =0;
    for(int row =0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col] == 1)continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> components;
            for (int ind = 0; ind < 4; ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if(isValid(newr, newc, n)){
                    if(grid[newr][newc] == 1){
                        components.insert(ds.findUPar(newr*n + newc));
                    }
                }
            }
            int sizeTotal =0;
            for(auto it: components){
                sizeTotal+= ds.size[it];
            }
            mx = max(mx, sizeTotal+1);
        }
    }

    for(int cellNo = 0; cellNo<n*n ; cellNo++){
        mx = max(mx, ds.size[ds.findUPar(cellNo)]);
    }
    return mx;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem