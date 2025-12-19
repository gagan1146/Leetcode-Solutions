# Last updated: 19/12/2025, 19:22:44
class Solution(object):
    def hasMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        x=set(s)
        y=p.find('*')
        z=str(p[:y]+p[y+1:])
        if(z in s):
            return True
        x1=s.find(str(p[:y]))
        x2=s.rfind(str(p[y+1:]))
        if(x1==-1 or x2==-1):
            return False
        if((x1+len(str(p[:y])))<x2):
            return True
        else:
            return False