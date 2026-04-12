class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int one_first = edges[0][0];
        int one_second = edges[0][1];
        
        int sec_first = edges[1][0];
        int sec_second = edges[1][1];

        if (one_first == sec_first || one_first == sec_second)
            return one_first;

        return one_second;
    }
};

