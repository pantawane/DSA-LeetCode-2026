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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        //base case
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; //flag 0/1

        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i=0; i<size; i++){
                TreeNode* currNode = q.front();
                q.pop();

            //find position to fill nodes value
            int index = leftToRight ? i : size - 1 - i;

            row[index] = currNode->val;
            if(currNode->left)
               q.push(currNode->left);

            if(currNode->right)
               q.push(currNode->right);
            }
            leftToRight = !leftToRight;
            result.push_back(row);
        }

        return result;
    }
};