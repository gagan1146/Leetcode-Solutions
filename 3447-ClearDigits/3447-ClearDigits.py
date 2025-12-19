# Last updated: 19/12/2025, 19:24:00
class Solution:
    def clearDigits(self, s: str) -> str:
        s=s[::-1]
        ans=[]
        for i in range(len(s)):
            flag=0
            if(s[i].isdigit()):
                ans.append(i)
                flag=1
            if(flag==1):
                for j in range(i+1,len(s)):
                    if(not(s[j].isdigit()) and (j not in ans)):
                        ans.append(j)
                        break
        a=""
        for i in range(len(s)):
            if(i not in ans):
                a+=s[i]
        a=a[::-1]
        print(ans,a)
        return a
        