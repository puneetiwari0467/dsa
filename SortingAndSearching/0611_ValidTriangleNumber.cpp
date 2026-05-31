class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int idx =lower_bound(nums.begin()+j+1,nums.end(),nums[i]+nums[j])-nums.begin();
                ans+=idx-j-1;
            }
        }
        return ans;
    }
};