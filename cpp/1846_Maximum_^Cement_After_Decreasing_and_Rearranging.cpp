#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
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
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ret = 1;
        arr[0] = 1;
        int i=0, j=1;
        while (j < arr.size())
        {
            if (abs(arr[i] - arr[j]) > 1) 
            {
                ret = arr[i]+1;
                arr[j] = ret;
            }
            else 
                ret = arr[j];
            i++;
            j++;
        }
        return ret;
    }
};
