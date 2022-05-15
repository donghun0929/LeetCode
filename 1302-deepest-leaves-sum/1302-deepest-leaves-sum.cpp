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
    vector<int> sumVal;
    int deepestLeavesSum(TreeNode* root) {
        TreeNode * SearchNode;
        sumVal.push_back(root->val);
        searchNodeSum(root, 1);
        return sumVal.back();
    }
    
    void searchNodeSum(TreeNode *root, int deep)
    {
        
        if(sumVal.size() <= deep)
            sumVal.push_back(0);
        if(root->val != 0)
            sumVal[deep] += root->val;
        if(root->left)
            searchNodeSum(root->left, deep+1);
        if(root->right)
            searchNodeSum(root->right, deep+1);
            
    }
};