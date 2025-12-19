# Last updated: 19/12/2025, 19:22:37
class Solution:
    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        cc = sum(abs(a - b) for a, b in zip(arr, brr))
        arr.sort()
        brr.sort()
        rc = sum(abs(a - b) for a, b in zip(arr, brr)) + k
        return min(cc, rc)