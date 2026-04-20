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

// since its weighted types, we must use djikstra algorithm



int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts)
{
    // WE NEED TO USE DJIKSTRA
    priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<>>pq;

    int m = rowCosts.size();
    int n = colCosts.size();
    vector<vector<int>> costs(m, vector<int>(n, 1e9));
    pq.push({0,{startPos[0], startPos[1]}});
    costs[startPos[0]][startPos[1]]= 0;
    vector<int> dr = {-1, 0 , 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    while(!pq.empty()){
        auto [cost, coord]= pq.top();
        int r = coord.first;
        int c = coord.second;
        if(r== homePos[0] && c == homePos[1]){
            return cost;
        }
        pq.pop();
        if (cost > costs[r][c])
            continue;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            int newCost =0;
            
            if(nr>=0 && nr<m && nc>=0 && nc<n ){
                if (nr != r)
                {
                    newCost = cost + rowCosts[nr];
                }
                else if (nc != c)
                {
                    newCost = cost + colCosts[nc];
                }
                if (newCost < costs[nr][nc]){
                    costs[nr][nc] = newCost;
                    pq.push({costs[nr][nc], {nr, nc}});
                }
                    
            }
        }
    }
    
}

int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts){
    int x = startPos[0];
    int y = startPos[1];
    int a = homePos[0];
    int b = homePos[1];
    int totalCost=0;
    if(x<a){
        while(x<=a){
            x++;
            totalCost+= rowCosts[x];
        }
    }
    else if(x>a){
        while(x>=a){
            x--;
            totalCost+=rowCosts[x];
        }
    }
    

    if(y<b){
        while(y<=b){
            y++;
            totalCost+= colCosts[y];
        }
    }
    else if(y>b){
        while(y>=b){
            y--;
            totalCost+= colCosts[y];
        }
    }

    return totalCost;
}

    int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem