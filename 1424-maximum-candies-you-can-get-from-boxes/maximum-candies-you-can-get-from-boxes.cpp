class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        vector<int>visited(status.size(),0);
        vector<int>ky(status.size(),0);
        for(int i=0;i<keys.size();i++){
            for(int j=0;j<keys[i].size();j++){
                ky[keys[i][j]]=1;
            }
        }
        for(int i=0;i<initialBoxes.size();i++){
            queue<int>q;
            int res = 0;
            q.push(initialBoxes[i]);
            visited[initialBoxes[i]]=1;
            for(int j=0;j<keys[initialBoxes[i]].size();j++){
                if(keys[initialBoxes[i]][j]!=initialBoxes[i])status[keys[initialBoxes[i]][j]]=1;
            }
            while(!q.empty()){
                int val = q.front();
                q.pop();
                for(int j=0;j<containedBoxes[val].size();j++){
                    if(visited[containedBoxes[val][j]]==0)q.push(containedBoxes[val][j]);
                    visited[containedBoxes[val][j]]=1;
                    // cout<<containedBoxes[val][j]<<" ";
                    for(int k=0;k<keys[containedBoxes[val][j]].size();k++){                 
                        if(keys[containedBoxes[val][j]][k]!=containedBoxes[val][j]){
                            status[keys[containedBoxes[val][j]][k]]=1;
                        }
                    }
                }
            }
            for(int i=0;i<visited.size();i++){
                if(visited[i]!=0 and status[i]!=0)res+=candies[i];
            }
            ans = max(res,ans);
        }
        return ans;
    }
};