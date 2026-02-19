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

// first we will marks all the cells with time it would tak efor fire to spread to them--> we will do this via BFS

// we will also do binary search on answers for the time the person can wait in the starting celkl. the range for the time for binary search on answers will be : 0 to m*n+1

void updateFireTime(vector<vector<int>> & grid, vector<vector<int>> & fireTime){
    int m = grid.size();
    int n = grid[0].size();
    
    // first we will push the cells which contatin fire inside the queue
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]== 1){
                q.push({i, j});
                fireTime[i][j]=0;
            }else{
                fireTime[i][j]= INT_MAX;
            }
        }
    }
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!q.empty()){
        auto cell = q.front(); q.pop();
        int x = cell.first;
        int y = cell.second;
        for(int i=0;i<4;i++){
            int nx = x+ dx[i];
            int ny = y+ dy[i];

            if(nx>=0 && nx<m && ny>=0 && ny<n  && grid[nx][ny]!= 2){
                if(fireTime[nx][ny] > fireTime[x][y]+1){
                    q.push({nx, ny});
                    fireTime[nx][ny] = fireTime[x][y] + 1;
                }
            }
        }
    }
}

bool isPossible(int mid, vector<vector<int>> &fireTime){
    int m = fireTime.size();
    int n = fireTime[0].size();
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    queue<pair<int,int>> q;

    int currTime = mid; // this is the wait time

    // in case the fire reaches us before we start moving
    if(fireTime[0][0]<= currTime){
        return false;
    }

    // now we will perform bfs from the 0.0 cell because we were standing there only waiting

    q.push({0,0});
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    visited[0][0] = true;
    while(!q.empty()){
        currTime++; // new step
        int size = q.size();
        for(int i=0;i<size;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // checking all four neighbours
            for(int j=0;j<4;j++){
                int nx = x+dx[j];
                int ny = y+dy[j];

                // check for boundarym wall and already visited
                if(nx<0 || ny < 0 || nx >= m || ny>=n || (fireTime[nx][ny] == -1) || visited[nx][ny])continue;

                // destination cell has been reached
                if(nx == m-1 && ny == n-1 && currTime<= fireTime[m-1][n-1]){
                    return true;
                }

                // if we can move to this neghbour before the fire reaches it
                if(currTime < fireTime[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny]= true;
                }
            }
        }
    }
    return false; // the final destination cannot be reached
}

int maximumMinutes(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> fireTime( m, vector<int> (n, INT_MAX));
    // to update the firetime for each cell
    updateFireTime(grid, fireTime);

    int ans =-1;
    int left  =0;
    int right = m*n+1;

    while(left <= right){
        int mid = left + (right-left)/2;
        if(isPossible(mid, fireTime)){
            left = mid+1;
            ans = mid;
        }else{
            right = mid-1;
        }
    }
    return ans == m*n+1 ? 1e9 : ans;
}

int main()
{
    FAST_IO;
    return 0;
}

// by ad73prem