# Last updated: 19/12/2025, 19:22:22
class Solution:
    def findMaxSum(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        n = len(nums1)
        idx = sorted(range(n), key=lambda x: nums1[x])
        pq = []
        s = 0
        res = [0] * n
        p = 0
    
        for i in range(n):
            while p < i and nums1[idx[p]] < nums1[idx[i]]:
                heappush(pq, nums2[idx[p]])
                s += nums2[idx[p]]
                if len(pq) > k:
                    s -= heappop(pq)
                p += 1
            res[idx[i]] = s
    
        return res