// Runtime: 712 ms
// Memory Usage: 166 MB
class Solution {
public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if(!original) return NULL;
    if(original == target) return cloned;
    TreeNode* l = getTargetCopy(original->left, cloned->left, target);
    if(l != NULL) return l;
    return getTargetCopy(original->right, cloned->right, target);
  }
};