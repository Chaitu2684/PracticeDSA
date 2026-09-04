class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>sufix(100);
        sufix[n-1]=nums.back();
        for(int i=n-2;i>=0;i--){
            sufix[i]=min(sufix[i+1],nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-sufix[i]<=k) return i;
        }
         return -1;


    }
};