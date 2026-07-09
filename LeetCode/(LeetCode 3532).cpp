//? 3532. Path Existence Queries in a Graph I

// You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

// You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.

// An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

// You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.

// Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise.

class DSU{
private:
    vector<int>par,sze;

public:
    DSU(int n){
        par.resize(n+1);
        sze.resize(n+1,1);
        iota(par.begin(),par.end(),0);
    }

    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }

    void unite(int x, int y){
        x=find(x);
        y=find(y);
        if(x==y) return ;
        if(sze[x]<sze[y]){
            swap(x,y);
        }
        par[y]=x;
        sze[x]+=sze[y];
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<bool>ans(q);
        DSU ds(n+1);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                ds.unite(i,i-1);
            }
        }
        for(int i=0;i<q;i++){
            if(ds.find(queries[i][0])==ds.find(queries[i][1])){
                ans[i]=true;
            }
        }
        return ans;
    }
};