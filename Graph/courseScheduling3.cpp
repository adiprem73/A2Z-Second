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

// the basic idea that we are going to follow is greedy algorithm
// we will: for any iteration, check if taking up current course would get completed in the designated itme or not
// if YES: add the new course and update the itme
// if NO: if it exceeds the deadline, swap it iwht the biggest duration from the ones taken already
// the swap should reduce the time taken till now

// sort array
// take priorityqueue<maxHeap> to store the durations
// iterate over inputt and tru to minimize the edntime while maximizing the courses
// retune: course completed: size opf the pq at the end

bool sorting (vector<int>& a, vector<int>& b){
    return a[1]==b[1] ? a[0]<b[0] : a[1]<b[1];
}

int scheduleCourse(vector<vector<int>> &courses)
{
    sort(courses.begin(), courses.end(), sorting);
    priority_queue<int> pq;
    int time =0; // time taken to complete the course til now

    for(auto course: courses){
        if(course[0] <= course[1]){ // check if we consider curren t oucrse : if duration<=lastday
            if(course[0]+time <=  course[1]){ // current course can be completed with the lastday given
                pq.push(course[0]); // we want the duration in the priority queue
                time += course[0];
            }else{
                // check if we can swap
                if (!pq.empty() && pq.top() > course[0])
                {
                    time -= pq.top();
                    pq.pop();
                    pq.push(course[0]);
                }
            }
        }
    }
    return pq.size();
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem