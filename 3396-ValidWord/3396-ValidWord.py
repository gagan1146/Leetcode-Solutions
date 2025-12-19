# Last updated: 19/12/2025, 19:24:08
class Solution:
    def isValid(self, word: str) -> bool:
        if(len(word)<3):
            return False
        x, y, z=1, 0,0
        for j in word:
            if(j in 'AEIOUaeiou'):
                y=1
            elif(j.isalpha()):
                z=1
            elif(not j.isalnum()):
                return False
        if(x and y and z):
            return True
        return False