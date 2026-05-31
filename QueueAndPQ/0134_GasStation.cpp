class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int nextIdx=0;
        int sum=0,total=0;
        for(int i=0;i<n;i++){
            sum+=(gas[i]-cost[i]);
            total+=(gas[i]-cost[i]);
            if(sum<0){
                sum=0;
                nextIdx=i+1;
            }
        }
        if(total<0)return -1;
        return nextIdx;
    }
};