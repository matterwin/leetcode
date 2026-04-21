class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        sp, tp = 0, 0
        slen, tlen = len(s), len(t)

        if slen > tlen:
            return False

        while sp < slen and tp < tlen:
            if tlen - tp < slen - sp:
                return False

            if s[sp] == t[tp]:
                sp += 1

            tp += 1

        return sp == slen
