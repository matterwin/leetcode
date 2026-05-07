class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps, cur_end, farthest = 0, 0, 0

        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])

            if i == cur_end:
                cur_end = farthest
                jumps += 1

        return jumps


