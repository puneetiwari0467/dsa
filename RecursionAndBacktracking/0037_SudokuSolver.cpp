class Solution {
public:
    vector<vector<char>>ans;
    unordered_set<int> filledPlaces(vector<vector<char>>&board,int cr,int cc){
        int n=board.size();
        int m=board[0].size();
        unordered_set<int>visited;
        for(int j=0;j<m;j++){
            if(board[cr][j]=='.')continue;
            visited.insert(board[cr][j]);
        }
        int ss=(cr/3)*3;
        int se=(cc/3)*3;
        for(int i=ss;i<ss+3;i++){
            for(int j=se;j<se+3;j++){
                if(board[i][j]=='.')continue;
                visited.insert(board[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][cc]=='.')continue;
            visited.insert(board[i][cc]);
        }
        return visited;
    }

    bool solver(vector<vector<char>>& board,int cr,int cc,bool row[9][10],bool col[9][10],bool box[9][10]){
        int n=board.size();
        int m=board[0].size();
        //cout<<"cr="<<cr<<" cc="<<cc<<endl;
        bool isFinish=true;
        if(cr==n-1 &&cc==m){
            ans=board;
            return isFinish;
        }
        if(cc>=m){
            cr++;cc=0;
        }
        if(board[cr][cc]=='.'){
            isFinish=false;
            //unordered_set<int>visited=filledPlaces(board,cr,cc);
            for(int val=1;val<=9;val++){
                if(!row[cr][val] && !col[cc][val] && !box[(cr/3)*3+((cc/3)*3)/3][val]){
                    row[cr][val]=1;
                    col[cc][val]=1;
                    box[(cr/3)*3+((cc/3)*3)/3][val]=1;
                    board[cr][cc]=val+'0';               
                    if(solver(board,cr,cc+1,row,col,box)==true){return true;}
                    board[cr][cc]='.';
                    row[cr][val]=0;
                    col[cc][val]=0;
                    box[(cr/3)*3+((cc/3)*3)/3][val]=0;
                }
            }
        }else {
            return solver(board,cr,cc+1,row,col,box);
        }
        return isFinish;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        bool row[9][10]={0}, col[9][10]={0}, box[9][10]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    row[i][board[i][j]-'0']=1;
                    col[j][board[i][j]-'0']=1;
                }
            }
        }

        for(int i=0;i<n;i=i+3){
            for(int j=0;j<m;j=j+3){
                int bx=(i/3)*3+((j/3)*3)/3;
                for(int cr=i;cr<i+3;cr++){
                    for(int cc=j;cc<j+3;cc++){                    
                         if(board[cr][cc]!='.'){
                            box[bx][board[cr][cc]-'0']=1;
                         }
                    }
                }
            }
        }
        solver(board,0,0,row,col,box);
        board=ans;
    }
};