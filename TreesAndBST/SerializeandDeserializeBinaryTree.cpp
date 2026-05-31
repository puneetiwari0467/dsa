/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        queue<TreeNode*>q;
        q.push(root);
        string ans="";
        while(q.size()>0){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* tp=q.front();q.pop();
                if(tp==NULL)ans+='#';
                else ans+=to_string(tp->val);
                ans+=",";
                if(tp){
                    q.push(tp->left);
                    q.push(tp->right);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")return NULL;
        //cout<<"data="<<data<<endl;
        vector<string>vs;
        string val="";
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                vs.push_back(val);
                val="";
            }else{
                val+=data[i];
            }
        }
        // for(auto x:vs){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        queue<TreeNode*>q;
        TreeNode* head=new TreeNode(stoi(vs[0]));
        q.push(head);
        int idx=1;
        while(q.size()>0){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* tp=q.front();q.pop();
                if(vs[idx]=="#")tp->left=NULL;
                else {tp->left=new TreeNode(stoi(vs[idx]));q.push(tp->left);}
                idx++;
                if(vs[idx]=="#")tp->right=NULL;
                else {tp->right=new TreeNode(stoi(vs[idx]));q.push(tp->right);}
                idx++;
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));