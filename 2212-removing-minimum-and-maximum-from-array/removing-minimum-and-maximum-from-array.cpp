class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        int Mind=-1;
        int mind=-1;
        for(int i=0;i<n;i++){
            if(Mind!=-1 && mind !=-1) break;
            if(nums[i]==maxi) Mind=i;
            if(nums[i]==mini) mind=i;
        }
        int a=max(mind,Mind) +1;
        int b=min(Mind,mind) +n-max(Mind,mind)+1;
        int c=n-min(mind,Mind);
        return min({a,b,c});

    }
};