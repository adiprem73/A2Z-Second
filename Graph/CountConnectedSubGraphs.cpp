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

/*
Hint 1
Enumerate all subsets with bitmasks
Hint 2
For each subset, check whether the induced subgraph is connected using DFS or BFS
Hint 3
Keep track of the parity of the sum of nums in the subset
Hint 4
Count the subset only if it is connected and the sum is even
Hint 5
Since n <= 13, a brute-force bitmask solution is feasible
*/

void makeSubSets(vector<int>& curr, vector<int> &arr, vector<vector<int>> & combination, int ind, int &n){
    if(ind == n){
        combination.push_back(curr);
        return;
    }

    // pick this index
    curr.push_back(arr[ind]);
    makeSubSets(curr, arr, combination, ind+1, n);

    //back-tracking
    curr.pop_back();

    // do not pick and move ahead
    makeSubSets(curr, arr, combination, ind+1,n);
}

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, set<int>& subSet, int &sum, vector<int>& nums){
    vis[u]= true;
    sum+=nums[u]; // take sum
    for(auto neigh: adj[u]){
        if(vis[neigh]==false && subSet.count(neigh)>0){
            dfs(neigh, adj, vis, subSet,sum, nums);
        }
    }
}

int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
    // first we will make a adj matrix
    int n = nums.size();
    vector<vector<int>> adj(n);
    for(auto &it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    // now let us create all possible subsets
    vector<int> arr;
    for(int i=0;i<n;i++){
        arr.push_back(i);
    }
    vector<int> curr;
    vector<vector<int>> combination;
    makeSubSets(curr, arr, combination, 0, n);
    int cnt =0;
    for(int i =0;i<combination.size();i++){
        if (combination[i].empty())
            continue;
        vector<bool> vis(n, false);
        if(combination[i].size()==1){
            if(nums[combination[i][0]] %2 == 0){
                cnt++;
                continue;
            }
        }
        else{
            set<int> subSet(combination[i].begin(), combination[i].end());
            int sum=0;
            dfs(combination[i][0], adj, vis, subSet, sum, nums);
            // for(auto it:vis){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            // vprint(combination[i]);
            // // cout<<endl;
            // cout<<sum<<endl;
            // cout<<"--------"<<endl;
            bool flag = true;
            for(int j=0;j<combination[i].size();j++){
                if(vis[combination[i][j]]==false){
                    flag = false;
                    break;
                }
            }
            if(flag==false){
                continue; // no need to go further than this
            }
            if(sum%2!=0){
                continue;
            }
            cnt++;
        }
    }
    return cnt;
}

int main() {
    FAST_IO;
    vector<int> nums = {1,0,1};
    vector<vector<int>> edges ={
        {0,1},
        {1,2}
    };
    cout<<evenSumSubgraphs(nums, edges);
    return 0;
}

// by ad73prem