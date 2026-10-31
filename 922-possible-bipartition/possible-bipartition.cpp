class Solution {
public:
   
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<string>color(n+1,"WHITE");
        vector<vector<int>>adj(n+1);

        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i=1;i<=n;i++){
      
      if(color[i]!="WHITE") continue;
      
      color[i]="RED";
      queue<int>q;
      q.push(i);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: adj[node]){
            if(color[it]==color[node]) return false;
            else if(color[it]=="WHITE"){
                if(color[node]=="RED") color[it]="BLACK";
                else color[it]="RED";
                q.push(it);
            }
        }
    }
        }
 return true;

    }
};