# Last updated: 19/12/2025, 19:21:51
class Solution(object):
    def findClosest(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: int
        """
        if(abs(x-z)<abs(y-z)):
            return 1
        if(abs(x-z)>abs(y-z)):
            return 2
        else:
            return 0