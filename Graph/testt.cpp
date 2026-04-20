#include <bits/stdc++.h>
using namespace std;

bool func(int gap, int n, int k, vector<int> &pos)
{
    int placed = 1;
    int prev = pos[0];

    for (int i = 1; i < n; i++)
    {
        if (pos[i] - prev >= gap)
        {
            placed++;
            prev = pos[i];
        }
        if (placed >= k)
            return true;
    }

    return false;
}

int signalTowers(int n, int k, vector<int> pos)
{
    sort(pos.begin(), pos.end());

    int lo = 0;
    int hi = pos[n - 1] - pos[0];
    int res = 0;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (func(mid, n, k, pos))
        {
            res = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return res;
}

int main(){
    vector<int> nums = {2,5,9,14,21,30,40};
    cout<<signalTowers(7,4, nums);
}