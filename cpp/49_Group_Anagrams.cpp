#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <string>
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        fast;
        unordered_map<string, vector<string>> mp;
        for (string w : strs)
        {
            int count[26] = {0};
            for (char c : w) count[c - 'a']++;

            char key[27];
            for (int i = 0; i < 26; ++i)
                key[i] = (unsigned char)count[i];
            key[26] = '\0';
            mp[string(key)] .push_back(w); 
        }

        vector<vector<string>> ret;
        for (auto [key, value] : mp)
            ret.push_back(value);

        return ret;
    }
};

