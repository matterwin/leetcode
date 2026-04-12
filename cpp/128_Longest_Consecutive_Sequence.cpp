#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> st;
        for (int n : nums) st.insert(n);

        int ret = 0;
        for (int num : st)
        {
            // only start at nums that are beg of a seq
            if (st.find(num - 1) == st.end()) 
            {
                int len = 1;
                int rhs = num + 1;
                while (st.find(rhs) != st.end()) 
                {
                    ++len;
                    ++rhs;
                }

                ret = max(ret, len);
            }
        }

        return ret;
    }
};



