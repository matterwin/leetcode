class Solution {
public:
    int mySqrt(int x) 
    {
        if (x < 2) return x;
        uint32_t right = x, left = 0;      
        uint64_t mid = left + (right - left) / 2;
        int ans = 0;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (mid * mid > x)
                right = mid - 1;
            else if (mid * mid <= x)
            {
                left = mid + 1;
                ans = mid;
            }
        }

        return ans;
    }
};
