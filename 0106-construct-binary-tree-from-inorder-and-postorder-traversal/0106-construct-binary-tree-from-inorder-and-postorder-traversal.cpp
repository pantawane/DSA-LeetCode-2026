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
    TreeNode* buildTreeFromPostorderAndInorder(vector<int>& inorder, int startIn, int endIn, vector<int>& postorder, int startP, int endP, map<int, int> &mp){

        //base case
        if(startIn > endIn || startP > endP) return NULL; 

        TreeNode* root = new TreeNode(postorder[endP]);

        int inRoot = mp[postorder[endP]];
        int leftOfRoot = inRoot - startIn;

        root->left = buildTreeFromPostorderAndInorder(inorder, startIn, inRoot-1, postorder, startP, startP+leftOfRoot-1, mp);

        root->right = buildTreeFromPostorderAndInorder(inorder, inRoot+1, endIn, postorder, startP+leftOfRoot, endP-1, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())  return NULL;

        //map inorder nums with index
        map<int, int> mp;

        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return buildTreeFromPostorderAndInorder(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};