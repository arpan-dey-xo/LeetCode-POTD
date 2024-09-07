class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        bool result = dfs(root, head);
        result |= isSubPath(head, root->left);
        result |= isSubPath(head, root->right);
        return result;
    }

private:
    bool dfs(TreeNode* node, ListNode* head) {
        if (!head) return true;
        if (!node) return false;
        bool result = false;
        if (node->val == head->val) {
            result |= dfs(node->left, head->next);
            result |= dfs(node->right, head->next);
        }
        return result;
    }
};