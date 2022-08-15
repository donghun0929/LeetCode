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
    int maxPathSum(TreeNode* root) {
        TreeNode *MaxTree;
        
        memcpy(&MaxTree, &root, sizeof(struct TreeNode*));
        int maxNum = INT_MIN;
        
        GetTreeNum(root, MaxTree, maxNum);
        return maxNum;
    }
    
    int GetTreeNum(TreeNode* root, TreeNode* MaxTree, int& maxNum)
    {
        int nLeft, nRight;
        if(root->left)
        {
            nLeft = GetTreeNum(root->left, MaxTree-> left, maxNum);
        }
        else if(!root->left)
        {
            nLeft = 0;
        }
        if(root->right)
        {
            nRight = GetTreeNum(root->right, MaxTree-> right, maxNum);
        }
        else if(!root->right)
        {
            nRight = 0;
        }
        nRight = nRight > 0 ? nRight : 0;
        nLeft = nLeft > 0 ? nLeft : 0;
        
        //int nowVal = nRight + nLeft + root->val;
        int nowVal = nRight + root->val;
        nowVal = nowVal > nLeft + root->val? nowVal : nLeft + root->val;
        int TempVal = nRight + nLeft + root->val;
        TempVal = TempVal > nowVal ? TempVal :nowVal;
        MaxTree->val = nowVal;
        maxNum = maxNum > TempVal ?  maxNum : TempVal;
        return nowVal;
    }
};