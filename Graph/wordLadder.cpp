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


int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int n = wordList.size();
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue <pair<string, int>> q;
    q.push({beginWord, 1});
    while(!q.empty()){
        auto [word, dist] = q.front();
        q.pop();
        if(word == endWord) return dist;
        for(int i=0;i<word.length();i++){
            char temp = word[i];
            for(char ch = 'a'; ch <= 'z';ch++){
                word[i] = ch;
                if(st.count(word)){
                    q.push({word, dist+1});
                    st.erase(word);
                }
            }
            word[i] = temp;
        }
    }
    return 0;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    int n = wordList.size();
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    vector<vector<string>> ans;
    vector<string> path;
    path.push_back(beginWord);
    while (!q.empty())
    {
        auto [word, dist] = q.front();
        path.push_back(word);
        q.pop();
        if (word == endWord){
            ans.push_back(path);
        }
        for (int i = 0; i < word.length(); i++)
        {
            char temp = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.count(word))
                {
                    q.push({word, dist + 1});
                    st.erase(word);
                }
            }
            word[i] = temp;
        }
        path.pop_back();
    }
}

int main()
{
    FAST_IO;
    vector<string> wordList = {"hot", "dot","dog","lot","log","cog"};
    ladderLength("hit", "cog", wordList);
    return 0;
}

// by ad73prem