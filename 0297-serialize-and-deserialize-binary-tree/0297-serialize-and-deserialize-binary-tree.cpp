class Codec {
public:

    void preorder(TreeNode* root, string &s){
        if(root == NULL){
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    TreeNode* buildTree(vector<string> &nodes, int &index){

        if(nodes[index] == "#"){
            index++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = buildTree(nodes,index);
        root->right = buildTree(nodes,index);

        return root;
    }

    TreeNode* deserialize(string data) {

        vector<string> nodes;
        string temp;

        for(char c : data){
            if(c == ','){
                nodes.push_back(temp);
                temp.clear();
            }
            else{
                temp += c;
            }
        }

        int index = 0;
        return buildTree(nodes,index);
    }
};