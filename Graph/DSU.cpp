class DisjointSet{
public:
    vector<int>rank,parent,size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else{
            parent[ulp_v]=ulp_u;
            if(rank[ulp_u]==rank[ulp_v]){
                rank[ulp_u]++;
            }
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v)return ;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DisjointSet ds(20001);
        int n=stones.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int x=stones[i][0];
            int y=stones[i][1]+10001;
            if(mp.find(x)!=mp.end()){
                ds.unionBySize(ds.findPar(mp[x]),i);
            }else{
                mp[x]=i;
            }
            if(mp.find(y)!=mp.end()){
                ds.unionBySize(ds.findPar(mp[y]),i);
            }else{
                mp[y]=i;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i){
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};