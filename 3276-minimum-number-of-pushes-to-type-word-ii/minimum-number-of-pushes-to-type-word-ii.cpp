class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        int s=0;
        for(int i=0;i<word.size();i++)
        {
            mp[word[i]]+=1;
        }
        vector<int>v;
        for(auto it:mp)
        {
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i=1;i<=v.size();i++)
        {
            if(i%8==0 and i!=0)
            {
                s=s+(v[i-1]*(i/8));
            }
            else{
                s=s+(v[i-1]*(((i)/8)+1));
            }
            // cout<<" s "<<s<<"  ";
        }
        return s;
    }
};