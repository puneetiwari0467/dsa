class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n=wordList.size();
        vector<int>visited(n,0);
        queue<string>q;
        q.push(beginWord);
        int level=1;
        set<string>st;
        for(auto x:wordList){
            st.insert(x);
        }
        while(q.size()>0){
            int sze=q.size();            
            for(int i=0;i<sze;i++){
                string tp=q.front();q.pop();
                for(int j=0;j<tp.size();j++){
                    char original=tp[j];
                    for(char ch='a';ch<='z';ch++){
                        tp[j]=ch;
                        if(st.find(tp)!=st.end()){
                            if(tp==endWord)return level+1;
                            q.push(tp);
                            st.erase(tp);
                        }
                    }
                    tp[j]=original;
                }
            }
            level++;
        }
        return 0;
    }
};