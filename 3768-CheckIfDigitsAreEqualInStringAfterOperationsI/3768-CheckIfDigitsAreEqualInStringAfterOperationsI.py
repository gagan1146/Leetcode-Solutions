# Last updated: 19/12/2025, 19:22:19
class Solution:
    def hasSameDigits(self, s: str) -> bool:
        if(len(s)==1):
            return False
        while True:
            if(len(s)==2):
                if(s[0]==s[1]):
                    return True
                else:
                    return False
            c=""
            for i in range(1,len(s)):
                x=(int(s[i])+int(s[i-1]))%10
                c+=str(x)
            s=c
        return True