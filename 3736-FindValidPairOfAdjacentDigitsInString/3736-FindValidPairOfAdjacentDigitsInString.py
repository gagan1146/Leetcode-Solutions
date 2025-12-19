# Last updated: 19/12/2025, 19:22:32
class Solution(object):
    def findValidPair(self, s):
        """
        :type s: str
        :rtype: str
        """
        d={}
        ans=-1
        for i in s:
            try:
                d[i]+=1
            except:
                d[i]=1
        for i in s:
            if(d[i]==int(i) and ans==-1):
                ans =i
            elif(i==str(d[i]) and ans!=i):
                return ans+i
            elif(d[i]==int(i)):
                ans=i
            else:
                ans=-1
        return ""