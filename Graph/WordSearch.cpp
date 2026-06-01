class Solution {
public:
        bool dfs(vector<vector<char>>& board, string word,vector<vector<int>>visited,int i,int j,int idx){
        int n=board.size();
        int m=board[0].size();
        if(idx==word.size())return true;
        
        visited[i][j]=1;
        //cout<<"i="<<i<<" j="<<j<<" idx="<<idx<<endl;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==0 && idx<word.size() && board[x][y]==word[idx] ){
                if(dfs(board,word,visited,x,y,idx+1))return true;
            }
        }
        visited[i][j]=0;
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        map<char,int>mp;for(int i=0;i<n;i++)for(int j=0;j<m;j++)mp[board[i][j]]++;
        vector<string>formed;
        for(int i=0;i<words.size();i++){
            bool npossible=false;
            
            for(auto x:words[i]){
                if(mp.find(x)==mp.end()){
                    npossible=true;break;
                }
            }
            if(npossible==true)continue;
            vector<vector<int>>visited(n,vector<int>(m,0));
            for(int j=0;j<n;j++){
                bool found=false;
                for(int k=0;k<m;k++){
                    if(board[j][k] == words[i][0]){
                        if(dfs(board,words[i],visited,j,k,1)){
                            found=true;
                            formed.push_back(words[i]);break;
                        }
                    }
                }
                if(found)break;
            }

        }
        return formed;
    }
};
