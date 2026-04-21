class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        ret = []
        cur_val = groups[0]
        ret.append(words[0])

        for i in range (1, len(groups)):
            if (not cur_val and groups[i]) or (cur_val and not groups[i]):
                ret.append(words[i])
                cur_val = groups[i]

        return ret

