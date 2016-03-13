/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int ldepth, rdepth;

    if (!root)
        return 0;

    ldepth = maxDepth(root->left);
    rdepth = maxDepth(root->right);

    if (ldepth < rdepth)
        return rdepth + 1;

    return ldepth + 1;
}
