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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>vs;
        stack<TreeNode*>st;
        TreeNode* temp=root;
        while(temp!=NULL||st.size()>0){
            //cout<<"data="<<temp->val<<endl;
            while(temp){
                st.push(temp);
                temp=temp->left;
            }
            temp=st.top();st.pop();
            vs.push_back(temp->val);
            temp=temp->right;
        }
        return vs;
    }
};