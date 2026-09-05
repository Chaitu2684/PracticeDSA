class Solution {
    long long mod=1e9+7;

    long long modpow(long long base,long long exp,long long mod){
        base%=mod;
        long long result=1;
        while (exp > 0) {
            if (exp & 1) result = (__int128)result * base % mod;
            base = (__int128)base * base % mod;
            exp >>= 1;
        }
        return result;
    }
public:
    int sumDecoded(vector<long long>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long wi=nums[i]%10;
            long long di=floor(nums[i]/10);
            int cnt=0;
            string num=to_string(di);
            int k=num.size();
            long long xi=0;
            long long yi=0;
            string temp="";
            while(cnt<k-wi){
                int rem=di%10;
                temp+='0'+rem;
                di/=10;
                cnt++;
         }
         reverse(temp.begin(),temp.end());
          yi = temp.empty() ? 0 : stoll(temp);
         xi=di;
         long long dv = modpow(xi, yi, mod);
         sum=(sum+dv)%mod;


        }
        return (int)sum;

        
    }
};