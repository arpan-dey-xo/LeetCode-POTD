class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder,
                                       vector<int>& postorder) {
            int numOfNodes = preorder.size();
            return constructTree(0, numOfNodes - 1, 0, preorder, postorder);
        }
    
    private:
        TreeNode* constructTree(int preStart, int preEnd, int postStart,
                                vector<int>& preorder, vector<int>& postorder) {
            if (preStart > preEnd) return NULL;
    
            if (preStart == preEnd) {
                return new TreeNode(preorder[preStart]);
            }
    
            int leftRoot = preorder[preStart + 1];
    
            int numOfNodesInLeft = 1;
            while (postorder[postStart + numOfNodesInLeft - 1] != leftRoot) {
                numOfNodesInLeft++;
            }
    
            TreeNode* root = new TreeNode(preorder[preStart]);
    
            root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                       postStart, preorder, postorder);
    
            root->right =
                constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                              postStart + numOfNodesInLeft, preorder, postorder);
    
            return root;
        }
    };