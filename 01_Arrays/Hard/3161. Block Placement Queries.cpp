// There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

// You are given a 2D array queries, which contains two types of queries:

// For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
// For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
// Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.

 class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        int q = queries.size();
        vector<int> bar;
        map<int, pair<int,int>> mp;
        set<pair<int,int>> s;
        set<pair<int,int>>::iterator it;

        bar.push_back(0);
        bar.push_back(50001);
        for(int i=0; i<q; i++){
            if(queries[i][0] == 1){
                bar.push_back(queries[i][1]);
            }
        }
        
        sort(bar.begin(), bar.end());
        int bar_sz = bar.size();

        mp[bar[0]] = {bar[0], bar[1]};
        for(int i=1; i<bar_sz-1; i++){
            mp[bar[i]] = {bar[i-1], bar[i+1]};
        }
        mp[bar[bar_sz-1]] = {bar[bar_sz-2], 0};
        
        
        for(int i=0; i<bar.size()-1; i++){
            s.insert({bar[i+1]-bar[i], bar[i]});
        }
        s.insert({0,bar[bar_sz-1]});
        

        for(int i=q-1; i>=0; i--){
            if(queries[i][0] == 1){
                int x = queries[i][1];
                int x_f = mp[x].first;
                int x_l = mp[x].second;
                
                s.erase({x-x_f, x_f});
                s.erase({x_l-x, x});
                mp[x_f].second = x_l;
                mp[x_l].first = x_f;
                s.insert({x_l-x_f, x_f});
            }
            else{
                int x = queries[i][1];
                int y = queries[i][2];
                if(y>x){
                    ans.push_back(false);
                    continue;
                }
                
                it = s.lower_bound({y,0});
                bool can = false;
                for (it; it!=s.end(); it++){
                    if(y + it->second <= x){       
                        can = true;
                        break;
                    }
                }     
                ans.push_back(can);         
            }
        }
         
        reverse(ans.begin(), ans.end());
        return ans;
    }
}; 