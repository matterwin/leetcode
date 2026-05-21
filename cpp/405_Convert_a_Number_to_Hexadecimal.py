class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"

        n = num & 0xFFFFFFFF

        hex_chars = "0123456789abcdef";
        ret = "";

        while n:
            ret += hex_chars[n & 0xF]
            n >>= 4

        return ret[::-1]


