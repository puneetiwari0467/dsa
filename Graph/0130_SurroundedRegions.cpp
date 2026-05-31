class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){q.push({i,0});visited[i][0]=1;}
            if(board[i][m-1]=='O'){q.push({i,m-1});visited[i][m-1]=1;}
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){q.push({0,j});visited[0][j]=1;}
            if(board[n-1][j]=='O'){q.push({n-1,j});visited[n-1][j]=1;}
        }

        while(q.size()>0){
            pair<int,int>tp=q.front();q.pop();
            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int x=tp.first+dx[k];
                int y=tp.second+dy[k];
                if(x>=0 && x<n &&y>=0 && y<m && visited[x][y]==0 && board[x][y]=='O'){
                    q.push({x,y});
                    visited[x][y]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};