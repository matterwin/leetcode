class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        int n = edges.size();
        vector<int64_t> weights(n);
        for (int i = 0; i < n; ++i)
            weights[edges[i]] += i;

        int64_t mxw = INT_MIN;
        int ret = -1;
        
        for (int i = 0; i < n; ++i)
        {
            if (weights[i] > mxw)
            {
                mxw = weights[i];
                ret = i;
            }
        }

        return ret;
    }
};


