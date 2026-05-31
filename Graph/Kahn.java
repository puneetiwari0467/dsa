class Solution {
    public boolean canFinish(int V, int[][] edges) {
        List<List<Integer>>adj=new ArrayList<>();
        for(int i=0;i<V;i++){
            adj.add(new ArrayList<>());
        }
        int indegree[]=new int[V];
        for(int[] edge:edges){
            adj.get(edge[0]).add(edge[1]);
            indegree[edge[1]]++;
        }
        Queue<Integer>q=new ArrayDeque<>();
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.add(i);
            }
        }
        ArrayList<Integer>ans=new ArrayList<>();
        while(!q.isEmpty()){
            Integer tp=q.peek();q.poll();
            ans.add(tp);
            for(Integer x:adj.get(tp)){
                indegree[x]--;
                if(indegree[x]==0){
                    q.add(x);
                }
            }
        }
        return ans.size()==V?true:false;
    }
}