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

void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>> & visit){
    // makr this row as visited
    visit[i][j]= true;
    int m = board.size();
    int n = board[0].size();

    // we need to move/ check in four directions 
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for(int k=0;k<4;k++){
        int nx = i +dx[k];
        int ny = j + dy[k];
        if(nx>=0 && nx<m && ny>=0 && ny <n && visit[nx][ny]==false && board[nx][ny]=='X'){
            dfs(nx, ny, board, visit);
        }
    }
}

int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> visit(m, vector<bool>(n, false)); // this will serve as the visited array
    int cnt=0; // this will be used to count the final answer

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]== 'X' && visit[i][j]== false){
                // if we find an x we will call the dfs from this cell
                dfs(i, j, board, visit);
                cnt++;
            }
        }
    }
    return cnt;
}


// the most optimla solution to this questions is: we only count the start of each battelships. the start of the ship can be determined by coutnign the cells which do not have 'X' on their top scell abd tgeir left cell.

int countBattleShips2(vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();

    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='X'){
                if(i>0 && board[i-1][j]=='X')continue;
                if(j>0 && board[i][j-1]=='X')continue;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    FAST_IO;
    return 0;
}

// by ad73prem