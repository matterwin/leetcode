using namespace std;
#define fast           ios_base::sync_with_stdio(false); cin.tie(NULL);

#include <string>
#include <algorithm>

class Solution {
public:
  int longestPalindrome(std::string s) {
    fast;
    int count[128] = {0};
    for (char c : s) count[c]++;

    int length = 0;
    bool hasOdd = false;
    for (int i = 0; i < 128; i++) {
        length += (count[i] / 2) * 2;
        if (count[i] % 2 == 1) hasOdd = true;
    }
    if (hasOdd) length += 1;
    return length;
  }
};

/* Time */
// O(n)

/* Space */
// O(1)

