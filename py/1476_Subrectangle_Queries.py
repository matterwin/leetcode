# https://leetcode.com/problems/subrectangle-queries/description/

class SubrectangleQueries(object):
    def __init__(self, rectangle):
        """
        :type rectangle: List[List[int]]
        """
        self.mx = rectangle


    def updateSubrectangle(self, row1, col1, row2, col2, newValue):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :type newValue: int
        :rtype: None
        """

        for r in range(row1, row2 + 1):
            for c in range(col1, col2 + 1):
                self.mx[r][c] = newValue


    def getValue(self, row, col):
        """
        :type row: int
        :type col: int
        :rtype: int
        """
        return self.mx[row][col]



# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)

