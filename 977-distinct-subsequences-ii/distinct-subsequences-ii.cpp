class Solution {
    long long mod=1e9+7;
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        int tot=0;
        vector<int>dp(26);
        for(auto &c : s){
            c-='a';
            int add=(tot-dp[c]+mod)%mod;
            dp[c]=1+tot;
            tot=(dp[c]+add)%mod;
        }
        return tot;
        
    }
};