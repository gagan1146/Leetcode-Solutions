# Last updated: 19/12/2025, 19:23:41
class Solution(object):
    def reportSpam(self, message, bannedWords):
        """
        :type message: List[str]
        :type bannedWords: List[str]
        :rtype: bool
        """
        d={}
        count=0
        for item in bannedWords:
            d[item]=1
        for item in message:
            if item in d:
                count+=1
            if(count==2):
                return True
        return False