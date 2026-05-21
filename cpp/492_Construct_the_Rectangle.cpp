#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int r = sqrt(area);

        for (int w = r; w >= 1; --w) {
            if (area % w == 0) {
                int l = area / w;
                // return immediately on first factor
                // starting with sqrt of area
                return {l, w};
            }
        }

        return {area, 1};
    }
};

