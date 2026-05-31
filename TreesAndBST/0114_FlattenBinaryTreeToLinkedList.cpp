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
    TreeNode* head;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        head->left=NULL;
        head->val=root->val;
        head->right=new TreeNode(-101);
        head=head->right;
        inorder(root->left);
        //if(root->left!=NULL){head->right=new TreeNode(-1);head=head->right;}
        inorder(root->right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        head=new TreeNode(-101);
        TreeNode* start=head;
        inorder(root);
        while(start->val!=-101){
            root->left=start->left;
            root->val=start->val;
            //cout<<"val="<<start->val<<endl;
            if(start->right!=NULL &&start->right->val==-101){
                root->right=NULL;break;
            }else{
                root->right=start->right;
                root=root->right;
            }
            start=start->right;
        }
        root->right=NULL;
    }
};