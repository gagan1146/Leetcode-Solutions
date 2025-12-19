# Last updated: 19/12/2025, 19:21:07
class Solution:
    def numOfSubsequences(self, s: str) -> int:
        n=len(s)
        a1,a2=[0]*(n+2), [0]*(n+2)
        for i in range(1,n+1):
            a1[i]=a1[i-1] + (1 if s[i-1]=='L' else 0)
        for i in range(n-1,-1,-1):
            a2[i]=a2[i+1] + (1 if s[i]=='T' else 0)
        ch1,ch2=0,[]
        for i in range(n):
            if(s[i]=='C'):
                ch2.append(i)
                ch1+=(a1[i]*a2[i+1])
        il=0
        for i in ch2:
            il += (a1[i]+1)*a2[i+1]
        it=0
        for i in ch2:
            it += a1[i] * (a2[i+1]+1)
        maxi=0
        for i in range(n+1):
            cf=a1[i]*a2[i]
            if cf>maxi:
                maxi=cf
        ic=ch1+maxi
        return max(ch1,il,it,ic)