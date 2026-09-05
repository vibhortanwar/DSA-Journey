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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        if(root) q.push({root, {0,0}});
        while(!q.empty()){
            auto [curr, pos] = q.front();
            q.pop();
            int col = pos.first;
            int row = pos.second;
            ans[col][row].insert(curr->val);
            if(curr->left) q.push({curr->left, {col-1, row+1}});
            if(curr->right) q.push({curr->right, {col+1, row+1}});
        }
        vector<vector<int>> res;
        for(auto& [col, rowMap]: ans){
            vector<int> colVals;
            for(auto& [row, values]: rowMap) {
                colVals.insert(colVals.end(),values.begin(),values.end());
            }
            res.push_back(colVals);
        }return res;
    }
};