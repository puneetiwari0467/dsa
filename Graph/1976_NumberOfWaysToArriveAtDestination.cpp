#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll mod=1e9+7;
        vector<vector<pair<ll,ll>>>adj(n);
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        vector<ll>time(n,1e18);
        vector<ll>ways(n,0);
        ways[0]=1;
        time[0]=0;
        map<ll,ll>mp;
        while(pq.size()>0){
            pair<ll,ll>tp=pq.top();pq.pop();
            ll timer=tp.first;
            ll currVtx=tp.second;
            if(currVtx==n-1){ 
                continue;}
            for(auto x:adj[currVtx]){
                ll dest=x.first;
                ll wt=x.second;
                //cout<<"currVtx="<<currVtx<<" dest="<<dest<<" wt="<<wt<<endl;
                if(time[dest]>wt+timer){
                    time[dest]=wt+timer;
                    ways[dest]=(ways[currVtx])%mod;
                    pq.push({time[dest],dest});
                }else if(time[dest]==wt+timer){
                    ways[dest]=(ways[dest]+ways[currVtx])%mod;
                }
                // cout<<"i= ";
                // for(int i=0;i<n;i++){
                //     cout<<i<<" ";
                // }
                // cout<<"\nways= ";
                // for(int i=0;i<n;i++){
                //     cout<<ways[i]<<" ";
                // }
                // cout<<"\ntime= ";
                // for(int i=0;i<n;i++){
                //     cout<<time[i]<<" ";
                // }
                // cout<<endl;
            }
        }
        return ways[n-1];
    }
};