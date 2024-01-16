class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>win;
        map<int,int>loose;
        for(int i=0;i<matches.size();i++)
        {
            for(int j=0;j<matches[0].size();j++)
            {
                loose[matches[i][j]]=0;
            }
        }
        for(int i=0;i<matches.size();i++)
        {
            loose[matches[i][1]]+=1;
        }
        vector<int>w;
        vector<int>l;
        vector<vector<int>>p;
        map<int, int>::iterator itr;
        for (itr = loose.begin(); itr != loose.end(); ++itr)
        {
            if(itr->second==0){
                w.push_back(itr->first);
            }
            else if(itr->second==1)
            {
                l.push_back(itr->first);
            }
        }
        p.push_back(w);
        p.push_back(l);
        return p;
    }
};