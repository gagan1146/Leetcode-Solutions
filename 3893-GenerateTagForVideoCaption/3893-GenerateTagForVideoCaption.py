# Last updated: 19/12/2025, 19:21:26
class Solution(object):
    def generateTag(self, caption):
        """
        :type caption: str
        :rtype: str
        """
        x=caption
        x=x.split()
        ans="#"
        if(len(x)>0):
            ans+=(x[0].lower())
        for i in range(1,len(x)):
            ans+=x[i].title()
        ans=ans[:100]
        return ans