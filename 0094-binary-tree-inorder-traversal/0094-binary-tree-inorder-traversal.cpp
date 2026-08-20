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
private:
    void inorder_traversal(TreeNode* root, vector<int>&ans){
        if(root == NULL){
            return;
        }
        inorder_traversal(root->left, ans);
        ans.emplace_back(root->val);
        inorder_traversal(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder_traversal(root, ans);
        return ans;
    }
};