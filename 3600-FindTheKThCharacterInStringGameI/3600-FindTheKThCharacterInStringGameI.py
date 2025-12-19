# Last updated: 19/12/2025, 19:23:27
class Solution:
    @staticmethod
    def next_character(char):
        return 'a' if char == 'z' else chr(ord(char) + 1)

    def kthCharacter(self, k: int) -> str:
        s = "a"
        if k == 1:
            return s
        
        while len(s) < k:
            current_char=""
            for i in s:
                current_char += self.next_character(i)
            s+=current_char
        
        return s[k - 1]