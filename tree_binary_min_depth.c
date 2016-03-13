/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    int ldepth, rdepth;

    if (!root)
        return 0;

    ldepth = minDepth(root->left);
    rdepth = minDepth(root->right);

    if (!ldepth)
        return rdepth + 1;

    if (!rdepth)
        return ldepth + 1;

    // reach here if both ldepth and rdepth are non-zero
    if (ldepth > rdepth)
        return rdepth + 1;

    return ldepth + 1;
}
