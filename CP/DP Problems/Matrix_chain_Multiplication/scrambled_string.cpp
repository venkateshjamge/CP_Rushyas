class Solution {
public:

    int dp[31][31][31][31];

    bool dfs(int s1, int e1, int s2, int e2, string& st1, string& st2){
        if(e1-s1!=e2-s2){
            return false;
        }
        int n=e1-s1+1;
        if(n<=0){
            return true;
        }
        if(n==1){
            return st1[s1]==st2[s2];
        }
        int& ans=dp[s1][e1][s2][e2];
        if(~ans){
            return ans; 
        }
        bool ok=true;
        for(int i=s1, j=s2;i<=e1 && j<=e2;i++, j++){
            if(st1[i]!=st2[j]){
                ok=false;
            }
        }
        if(ok){
            return ans=true;
        }
        ok=true;
        for(int i=s1, j=e2;i<=e1 && j>=s2;i++,j--){
            if(st1[i]!=st2[j]){
                ok=false;
            }
        }
        if(ok){
            return ans=true;
        }
        for(int len=1;len<n;len++){
            if(dfs(s1,s1+len-1,s2,s2+len-1,st1,st2) && dfs(s1+len,e1,s2+len,e2,st1,st2)){
                return ans=true;
            }
            if(dfs(s1,s1+len-1,e2-len+1,e2,st1,st2) && dfs(s1+len,e1,s2,e2-len,st1,st2)){
                return ans=true;
            }
        }
        return ans=false;
    }

    bool isScramble(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return dfs(0, s1.size()-1, 0, s2.size()-1, s1, s2);
    }
};