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
    int getLeftHeight(TreeNode* root){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return 0;
        if(root->left==NULL)return 0;
        return 1+getLeftHeight(root->left);
    }
    int getRightHeight(TreeNode* root){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL)return 0;
        if(root->right==NULL)return 0;
        return 1+getRightHeight(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=getLeftHeight(root);
        int rh=getRightHeight(root);
        //cout<<"lh="<<lh<<" rh="<<rh<<endl;
        if(lh==rh){
            return pow(2,lh+1)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);    
    }
};