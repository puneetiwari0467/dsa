class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //ele<->[idx<>ListNumber]
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>npq;
        int cnt=0;
        int current_max=INT_MIN;
        int current_min=INT_MAX;
        for(vector<int> x:nums){
            current_max=max(current_max,x[0]);
            npq.push({x[0],{0,cnt}});
            cnt++;
        }
        vector<int>ans;
        int diff=INT_MAX;
        int ss=-1,se=-1;
        while(npq.size()>=nums.size()){
            pair<int,pair<int,int>>ntp=npq.top();
            npq.pop();
            current_min=ntp.first;
            if(current_max-current_min<diff){
                diff=current_max-current_min;
                se=current_max;
                ss=current_min;
            }
            //cout<<ntp.first<<"<>"<<ntp.second.first<<"<>"<<ntp.second.second<<endl;
            if(nums[ntp.second.second].size()>ntp.second.first+1){
                current_max=max(nums[ntp.second.second][ntp.second.first+1],current_max);
                npq.push({nums[ntp.second.second][ntp.second.first+1],{ntp.second.first+1,ntp.second.second}});
            }
            

            //cout<<"ss="<<ss<<" se="<<se<<" diff="<<diff<<endl;
        }
        return vector<int>{ss,se};
    }
};