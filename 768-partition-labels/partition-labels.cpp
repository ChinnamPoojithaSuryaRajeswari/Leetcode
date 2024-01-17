class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>last;
        int k=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(last[s[i]]==0){
                last[s[i]]=i;
                cout<<s[i]<<" "<<last[s[i]]<<" ";
            }
        }
        vector<int>v;
        int f=0,l=last[s[0]];
        for(int i=0;i<s.size();i++)
        {
            if(i==l)
            {
                v.push_back(l-f+1);
                f=l+1;
                l=last[s[f]];
            }
            else{
                if(last[s[i]]>l)
                {
                    l=last[s[i]];
                }
            }
        }
        return v;
    }
};
