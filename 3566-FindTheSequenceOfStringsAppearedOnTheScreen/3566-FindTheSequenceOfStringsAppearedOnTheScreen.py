# Last updated: 19/12/2025, 19:23:36
class Solution:
    def stringSequence(self, target: str) -> List[str]:
        a=[]
        s=""
        a.append('a')
        for i in range(len(target)):
            s1='a'
            while(s1!=target[i]):
                s1=chr(ord(s1)+1)
                a.append(s+s1)
            s=s+s1
            if(i!=len(target)-1):
                a.append(s+'a')
        return a