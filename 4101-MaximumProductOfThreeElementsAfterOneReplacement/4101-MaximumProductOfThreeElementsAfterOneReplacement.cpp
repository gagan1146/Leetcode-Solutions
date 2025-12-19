// Last updated: 19/12/2025, 19:20:04
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long product = LLONG_MIN;
        int n = nums.size();
        product = max(product,1LL*nums[0]*nums[1]*100000LL);
        product = max(product,1LL*nums[0]*nums[1]*(-100000LL));
        product = max(product,1LL*nums[n-1]*nums[n-2]*100000);
        product = max(product, 1LL*nums[n-1]*nums[n-2]*(-100000));
        product = max(product,1LL*nums[0]*nums[n-1]*100000);
        product = max(product,1LL* nums[0]*nums[n-1]*(-100000));
        return product;
    }
};