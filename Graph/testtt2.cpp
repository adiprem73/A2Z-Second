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


bool func(long long lim, int N, int Q, const vector<long long> &cal)
{
    int eng = 1;
    long long mx = 0;
    long long s = 0;

    for (int i = 0; i < N; i++)
    {
        long long nmx = max(mx, cal[i]);
        long long nsize = s + 1;

        if (nmx * nsize <= lim)
        {
            mx = nmx;
            s = nsize;
        }
        else
        {
            eng++;
            mx = cal[i];
            s = 1;

            if (mx > lim)
                return false;
        }
    }

    if (eng <= Q)
    {
        return true;
    }
    return false;
}

long long telescopeCalibration(int N, int Q, vector<long long> cal)
{

    long long l = 0;
    long long r = (long long)1e12;
    long long ans = r;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;

        if (func(mid, N, Q, cal))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    FAST_IO;
    vector<long long> cal = {10, 3, 8, 6, 4};
    cout<<telescopeCalibration(5,5, cal);
    return 0;
}

// by ad73prem