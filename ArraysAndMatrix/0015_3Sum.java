class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n=nums.length;
        Set<List<Integer>>st=new HashSet<>();
        Arrays.sort(nums);
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int h=n-1;
            while(l<h){
                if(nums[i]+nums[l]+nums[h]==0){
                    st.add(Arrays.asList(nums[i], nums[l], nums[h]));
                    l++;h--;
                }else if(nums[i]+nums[l]+nums[h]>0){
                    h--;
                }else l++;
            }
        }
        List<List<Integer>>ans=new ArrayList<>();
        for(List<Integer> l:st){
            ans.add(l);
        }
        return ans;
    }
}