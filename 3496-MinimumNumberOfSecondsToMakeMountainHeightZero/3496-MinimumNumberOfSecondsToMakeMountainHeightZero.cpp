// Last updated: 19/12/2025, 19:23:50
class Solution {
public:
    
bool canAchieveHeight(int mountainHeight, const vector<int>& workerTimes, long long maxTime) {
    long long totalHeightReduced = 0;

    for (int time : workerTimes) {
        // Calculate the maximum units this worker can reduce within maxTime
        long long maxUnits = (-1 + sqrt(1 + 8.0 * maxTime / time)) / 2;
        totalHeightReduced += maxUnits; // Add this worker's contribution

        // Early exit if we've already met the required height
        if (totalHeightReduced >= mountainHeight) {
            return true;
        }
    }
    
    return totalHeightReduced >= mountainHeight;
}

// Function to find the minimum time required to reduce the mountain height to 0
long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long long left = 1; // Start searching from 1 second
    long long right = 1e18; // A sufficiently large value for the upper bound
    long long result = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2; // Middle point for binary search
        if (canAchieveHeight(mountainHeight, workerTimes, mid)) {
            result = mid; // Found a feasible time
            right = mid - 1; // Try to find a smaller feasible time
        } else {
            left = mid + 1; // Increase the time
        }
    }
    
    return result;
    }
};