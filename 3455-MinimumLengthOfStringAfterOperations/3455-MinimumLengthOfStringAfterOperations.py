# Last updated: 19/12/2025, 19:23:56
class Solution:
    def minimumLength(self, s: str) -> int:
        return sum(1 if x % 2 else 2 for x in Counter(s).values())