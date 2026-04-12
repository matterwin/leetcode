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
    bool detectCapitalUse(string word) {
        fast;               
        int capital_cnt = 0;
        int first_captial_idx = -1;
        for (int i=0; i < word.length(); ++i)
        {
            char c = word[i];
            if (c - 'A' >= 0 && c - 'A' < 27) 
            {
                if (first_captial_idx == -1)
                    first_captial_idx = i;
                    
                ++capital_cnt;
            }
        }

        if (capital_cnt == 1 && first_captial_idx == 0)
            return true;
        if (capital_cnt == word.length())
            return true;
        if (capital_cnt == 0)
            return true;
        return false;
    }
};



