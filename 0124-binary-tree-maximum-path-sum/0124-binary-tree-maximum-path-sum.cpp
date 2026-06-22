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
       int maxSum = INT_MIN;
    int maxOfEachNode(TreeNode* root){
        //base case
        if(root == nullptr)
        return 0;

        int left = max(maxOfEachNode(root->left), 0);
        int right = max(maxOfEachNode(root->right), 0);

        int path = root->val + left + right; //candidate path

        maxSum = max(maxSum, path);

        return root->val + max(left, right);//return value
    }

    int maxPathSum(TreeNode* root) {
        maxOfEachNode(root);
        return maxSum;
    }
};