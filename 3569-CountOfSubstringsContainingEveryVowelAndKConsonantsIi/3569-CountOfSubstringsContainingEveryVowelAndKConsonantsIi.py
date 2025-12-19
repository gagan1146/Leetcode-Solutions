# Last updated: 19/12/2025, 19:23:35
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        def atLeast(word,k):
            vowels,d,low,high,n,c,ans="aeiou",{},0,0,len(word),0,0
            while(high<n):
                if(word[high] in vowels):
                    d[word[high]]=d.get(word[high],0)+1
                else:
                    c+=1
                while(c>=k and len(d)==5):
                    ans+=n-high
                    if(word[low] in vowels):
                        d[word[low]]-=1
                        if(d[word[low]]==0):
                            del d[word[low]]
                    else:
                        c-=1
                    low+=1
                high+=1
            return ans
        return atLeast(word,k) - atLeast(word,k+1)