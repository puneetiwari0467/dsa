class DisjointSet{
    int rank[],parent[],size[];
    DisjointSet(int n){
        rank=new int[n+1];
        parent=new int[n+1];
        size=new int[n+1];
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
}
class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        DisjointSet ds=new DisjointSet(1001);
        int n=accounts.size();
        Map<String,Integer>mp=new HashMap<>();
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts.get(i).size();j++){
                if(mp.containsKey(accounts.get(i).get(j))){
                    ds.unionByRank(mp.get(accounts.get(i).get(j)),i);    
                }
                mp.put(accounts.get(i).get(j),ds.findPar(i));
            }
        }
        Map<Integer,List<String>>ump=new HashMap<>();
        for(Map.Entry<String,Integer>e:mp.entrySet()){
            int actualParent=ds.findPar(e.getValue());
            if(ump.containsKey(actualParent)){
                ump.get(actualParent).add(e.getKey());
            }else{
                ump.put(actualParent,new ArrayList<>(Arrays.asList(e.getKey())));
            }
        }
        List<List<String>>ans=new ArrayList<>();
        for(Map.Entry<Integer,List<String>>es:ump.entrySet()){
            es.getValue().sort(null);
            es.getValue().add(0,accounts.get(es.getKey()).get(0));
            ans.add(es.getValue());
        }
        return ans;

    }
}
