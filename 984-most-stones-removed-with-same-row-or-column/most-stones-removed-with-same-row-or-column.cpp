#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank_, parent_, size_;

public:
    DisjointSet(int n) {
        rank_.resize(n + 1, 0);
        parent_.resize(n + 1);
        size_.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent_[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent_[node]) 
            return node;
        return parent_[node] = findUPar(parent_[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (rank_[ulp_u] < rank_[ulp_v]) {
            parent_[ulp_u] = ulp_v;
        } else if (rank_[ulp_u] > rank_[ulp_v]) {
            parent_[ulp_v] = ulp_u;
        } else {
            parent_[ulp_v] = ulp_u;
            rank_[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (size_[ulp_u] < size_[ulp_v]) {
            parent_[ulp_u] = ulp_v;
            size_[ulp_v] += size_[ulp_u];
        } else {
            parent_[ulp_v] = ulp_u;
            size_[ulp_u] += size_[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:stoneNodes){
            if(ds.findUPar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;


        
    }
};