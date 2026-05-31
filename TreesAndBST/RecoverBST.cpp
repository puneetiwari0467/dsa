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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    void inorder(TreeNode* root){
        if(root==NULL)return ;
        inorder(root->left);
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=NULL;
        first=NULL;
        middle=NULL;
        last=NULL;
        inorder(root);
        if(last==NULL){
            swap(first->val,middle->val);
        }else{
            swap(first->val,last->val);
        }
    }
};