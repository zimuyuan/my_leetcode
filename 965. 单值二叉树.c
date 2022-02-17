/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root)
{
    if(root == NULL)
    {
        return false;
    }

    else if((root != NULL) && ((root->left == NULL) && (root->right == NULL)))
    {
        return true;
    }
    else
    {
        if(isUnivalTree(root->left) && isUnivalTree(root->right))
        {
            return root->val == root->left->val && root->val == root->right->val;
        }
        else if(isUnivalTree(root->left) && (root->right == NULL))
        {
            return root->val == root->left->val;
        }
        else if((root->left == NULL) && isUnivalTree(root->right))
        {
            return root->val == root->right->val;
        }
    }

    return false;
}
