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

int compare(int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);
    int x = min(sa.length(), sb.length());
    int cnt =0;
    for(int i=0;i<x;i++){
        if(sa[i] == sb[i]){
            cnt++;
        }else{
            break;
        }
    }
    return cnt;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<string> st;
    for(auto it: arr1){
        string s = to_string(it);
        string temp="";
        for(auto ch: s){
            temp+=ch;
            st.insert(temp);
        }
    }
    int ans =0;
    for(auto it:arr2){
        string s = to_string(it);
        string temp="";
        for(auto ch: s){
            temp+=ch;
            if(st.count(temp)>0){
                if(temp.length()>ans){
                    ans=temp.length();
                }
            }
        }
    }
    return ans;
}

int main() {
    FAST_IO;
    vint nums = {1,10,100};
    vint nums2 = {1000};
    cout<<longestCommonPrefix(nums, nums2);
    return 0;
}

// by ad73prem