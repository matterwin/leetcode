#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
#include <unordered_set>
#include <algorithm>
using namespace std;
#define fast           ios_base::sync_with_stdio(false); cin.tie(NULL);
#define cy             cout<<"YES\n"
#define cn             cout<<"NO\n"
#define nl             cout<<"\n"
#define fset(arr, val) memset(arr, val, sizeof(arr))
#define fset(arr, val) memset(arr, val, sizeof(arr))
#define fcopy(dest, src) memcpy(dest, src, sizeof(dest))
#define fmove(dest, src) memmove(dest, src, sizeof(dest))
#define fcmp(arr1, arr2) memcmp(arr1, arr2, sizeof(arr1))
#define sci(x) scanf("%d", &x)
#define scll(x) scanf("%lld", &x)
#define scs(str) scanf("%s", str)
#define scf(x) scanf("%f", &x)
#define scd(x) scanf("%lf", &x)
#define scc(x) scanf(" %c", &x)
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define prv1d(vec) for (const auto& x : vec) std::cout << x << " "; std::cout << "\n";
#define prv2d(vec2d) do { for (const auto& row : vec2d) { for (const auto& x : row) std::cout << x << " "; std::cout << "\n"; } } while(0)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        fast;
        unordered_set<int> st(nums.begin(), nums.end());
        int cnt = 0;
        for (int n : st)
        {
            if (st.find(n - 1) == st.end())
            {
                int cur_cnt = 1;
                while (st.find(n + 1) != st.end())
                {
                    cur_cnt++;
                    n++;
                }
                cnt = max(cnt, cur_cnt);
            }
        }
        return cnt;
    }
};
