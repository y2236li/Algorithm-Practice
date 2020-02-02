"""
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
"""


using namespace std;
class Solution {
public:
    // record the depth d, if d%2 = 1 left to right else right to left
    void zzOrderHelper(TreeNode* root, int depth, vector<vector<int>> &res){
        if (root == NULL) return;
        if (depth > res.size()){
            res.push_back({});
        }
        if (depth % 2 == 1) res[depth-1].push_back(root->val);
        else res[depth-1].insert(res[depth-1].begin(), root->val);
        zzOrderHelper(root->left, depth +1, res);
        zzOrderHelper(root->right, depth +1, res);
        return;
    }
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int depth = 1;
        vector<vector<int>> res({});
        zzOrderHelper(root, 1, res);
        return res;
    }
};