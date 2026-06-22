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
    int countGoodNodes(TreeNode* root, int maxSoFar){
        //base case
        if(root == NULL)
        return 0;

        int cnt = 0;
        if(root->val >= maxSoFar){//good nodes
        cnt++;
        maxSoFar = root->val;
        }
        //left and right good nodes
        cnt += countGoodNodes(root->left, maxSoFar);
        cnt += countGoodNodes(root->right, maxSoFar);

        return cnt;
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, INT_MIN);
    }
};