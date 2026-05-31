class Solution {
    boolean sumMaker(int nums[],int visited[],int sum,int tsum,int k,int idx){
        if(k==1)return true;
        if(sum==0)return sumMaker(nums,visited,tsum,tsum,k-1,0);
        for(int i=idx;i<nums.length;i++){
            if(visited[i]==0 && sum>=nums[i]){
                visited[i]=1;
                if(sumMaker(nums,visited,sum-nums[i],tsum,k,i+1))return true;
                visited[i]=0;
            }
        }
        return false;
    }
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum=0;
        for(int i=0;i<nums.length;i++){sum+=nums[i];}
        int visited[]=new int[nums.length];
        if(sum%k!=0)return false;
  
        return sumMaker(nums,visited,sum/k,sum/k,k,0);
    }
}