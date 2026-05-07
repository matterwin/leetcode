class Solution {
public:
    bool canJump(vector<int>& nums) {
		int max_reachable_index = 0;       

		for (int i = 0; i < nums.size(); ++i) {
			if (i > max_reachable_index) return false;
			max_reachable_index = max(max_reachable_index, i + nums[i]);
		}

		return true;
    }
};


// Also very good solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;
    }
};
