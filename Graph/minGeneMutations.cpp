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

int minMutation(string startGene, string endGene, vector<string> &bank)
{
    unordered_set<string>st (bank.begin(), bank.end());

    queue<pair<string,int>> q;
    q.push({startGene, 1});
    vector<char> ch  = {'A', 'C', 'G', 'T'};
    while(!q.empty()){
        auto [gene, steps] = q.front();
        if(gene == endGene){
            return steps; // base case
        }

        for(int i=0;i<8;i++){
            string temp = gene;
            for(auto chr: ch){
                temp[i] = chr;
                if(st.count(temp)){
                    q.push({temp, steps+1});
                    st.erase(temp);
                }
            }
        }
    }
    return 0;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem