class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ani;
        int pooj=*max_element(arr.begin(),arr.end());
        int k,anu=0,work=0;
        sort(arr.begin(),arr.end());
        while(pooj)
        {
            pooj=pooj>>1;
            work+=1;
        }
        for(int i=0;i<arr.size();i++)
        {
            k=arr[i];
            while(k)
            {
                if(k&1)
                {
                    anu+=1;
                }
                k=k>>1;
            }
            ani.push_back(arr[i]);
            ani.push_back(anu);
            anu=0;
        }
        arr.clear();
        for(int i=0;i<work;i++)
        {
        for(int j=1;j<ani.size();j++)
        {
            if(ani[j]==i)
            {
                // cout<<(ani[j-1])<<" ";
                arr.push_back(ani[j-1]);
            }
            j+=1;
        }
        }
        return arr;
    }
};