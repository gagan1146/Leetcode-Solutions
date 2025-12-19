# Last updated: 19/12/2025, 19:19:46
class Solution:
    def Count(self, s: str) -> int:
        c = 0
        x = "aeiou"
        for i in s:
            if(i in x):
                c+=1
        return c
    def reverseWords(self, s: str) -> str:
        l = s.split()
        d = {self.Count(l[0]):1}
        for i in range(1,len(l)):
            x = self.Count(l[i])
            if(x in d):
                l[i]=l[i][::-1]
        result = " ".join(l)
        return result