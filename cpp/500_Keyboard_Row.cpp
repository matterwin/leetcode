#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
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
    vector<string> findWords(vector<string>& words) {
        fast;
        vector<string> out;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        int freqs[26*3] = {0};
        for (char c : row1) freqs[tolower(c) - 'a']++;
        for (char c : row2) freqs[tolower(c) - 'a' + 26]++;
        for (char c : row3) freqs[tolower(c) - 'a' + 52]++;

        for (string w : words)
        {
            int asgn_row = -1;
            bool flag = 1;
            for (int i=0; i < w.length(); ++i)
            {
                char c = tolower(w[i]);
                if (asgn_row == -1)
                {
                    if (freqs[c - 'a']) asgn_row = 0;
                    else if (freqs[c - 'a' + 26]) asgn_row = 1;
                    else if (freqs[c - 'a' + 52]) asgn_row = 2;
                }

                if (!freqs[c - 'a' + (26 * asgn_row)])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                out.push_back(w);
        }

        return out;
    }
};
