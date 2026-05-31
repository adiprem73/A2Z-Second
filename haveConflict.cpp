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

int timeConvert(string s){
    int a = s[0]-'0';
    int b = s[1]-'0';
    int c = s[3]-'0';
    int d = s[4]-'0';

    int time=0;
    time = a*1000 + b*100 + c*10 + d;
    return time;
}

bool haveConflict(vector<string>& event1, vector<string>& event2) {
    vector<int> e1= {timeConvert(event1[0]), timeConvert(event1[1])};
    vector<int> e2 = {timeConvert(event2[0]), timeConvert(event2[1])};
    vector<vector<int>> events = {e1, e2};
    sort(events.begin(), events.end());

    if(events[0][1]>=events[1][0])return true;
    else return false;
}

int main() {
    FAST_IO;
    vector<string> event1 = {"01:15", "02:00"};
    vector<string> event2 = {"02:30", "03:00"};
    cout<<haveConflict(event1, event2);
    return 0;
}

// by ad73prem