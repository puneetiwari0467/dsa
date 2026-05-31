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
    TreeNode* generateTree(vector<int>& inorder,int is,int ie,vector<int>& preorder,int ps, map<int,int>&mp){
        cout<<"is="<<is<<" ie="<<ie<<" ps="<<ps<<endl;
        if(is>ie ||ps>=preorder.size())return NULL;
        int inIdx=mp[preorder[ps]];
        TreeNode* root=new TreeNode(inorder[inIdx]);
        root->left=generateTree(inorder,is,inIdx-1,preorder,ps+1,mp);
        root->right=generateTree(inorder,inIdx+1,ie ,preorder,ps+inIdx-is+1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return generateTree(inorder,0,inorder.size()-1,preorder,0,mp);
    }
};