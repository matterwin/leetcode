#include <cstdio>
#include <bits/stdc++.h>
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
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        fast; 
        int abc[26] = {0};
        for (char c : licensePlate)
        {
            char _c = tolower(c);
            if (_c >= 'a' && _c <= 'z')
                abc[_c-'a']++;
        }

        int abc_word[26] = {0};
        string ret = "";
        int min_len = INT_MAX;
        for (string word : words)
        {
            memset(abc_word, 0, sizeof(abc_word));
            for (char c : word)
            {
                char _c = tolower(c);
                if (_c >= 'a' && _c <= 'z')
                    abc_word[_c-'a']++;
            }

            bool flag = true;
            for (int i=0; i < 26; ++i)
            {
                if (abc_word[i] < abc[i])
                {
                    flag = false; 
                    break;
                }
            }
            if (flag)
            {
                if (word.length() < min_len)
                {
                    min_len = word.length();
                    ret = word;
                }
            }
        }


        return ret;
    }
};

