// Last updated: 19/12/2025, 19:23:46
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        int getPerfectSubtreeSize(TreeNode* node) {
        if (!node) return 0;

        // Get sizes of left and right subtrees
        int leftSize = getPerfectSubtreeSize(node->left);
        int rightSize = getPerfectSubtreeSize(node->right);
        
        // Calculate total size
        int totalSize = leftSize + rightSize + 1;

        // Check if it's a perfect binary tree
        if (isPerfect(node, totalSize)) {
            perfectSizes.push_back(totalSize);
        }

        return totalSize;
    }

    // Helper function to check if a tree is perfect
    bool isPerfect(TreeNode* node, int size) {
        int h = height(node);
        return size == (1 << h) - 1; // 2^h - 1
    }

    // Function to compute the height of the tree
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    // Main function to find the k-th largest perfect subtree
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        perfectSizes.clear();
        getPerfectSubtreeSize(root);
        
        // Sort the sizes in descending order
        std::sort(perfectSizes.rbegin(), perfectSizes.rend());

        // Return the k-th largest or -1 if not enough elements
        if (k <= perfectSizes.size()) {
            return perfectSizes[k - 1];
        }
        return -1; // Not enough perfect subtrees
    }

private:
    std::vector<int> perfectSizes; // Store sizes of perfect subtrees
};