# Last updated: 19/12/2025, 19:21:17
class Solution:
    def processStr(self, s: str) -> str:
        res=""
        for i in s:
            if(i=='*'):
                if(len(res)>0):
                    res=res[:len(res)-1]
            elif(i=='#'):
                res=res+res
            elif(i=='%'):
                res=res[::-1]
            else:
                res+=i
        return res