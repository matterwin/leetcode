class Solution:
    def convertToTitle(self, colNum: int) -> str:
        ret = ""

        while colNum > 0:
            colNum -= 1
            ret += chr(ord('A') + (colNum % 26))
            colNum //= 26

        return ret[::-1]
