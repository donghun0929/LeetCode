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
    int val = 0;
    int minCameraCover(TreeNode* root) {
        int n = dfs(root);
        if(n == 10)
            return val + 1;
        return val;
    }
    
    // 100 = null - > 10 = leaf -> 1 = add - > null;
    int dfs(TreeNode* root)
    {
        if(!root)
            return 100; // Null
        
        int left = dfs(root->left), right = dfs(root->right);
        
        if(left == 10 || right == 10)
        {
            val += 1;
            return 1;
        }
        
        return left == 1 || right == 1 ? 100 :10;
    }
};