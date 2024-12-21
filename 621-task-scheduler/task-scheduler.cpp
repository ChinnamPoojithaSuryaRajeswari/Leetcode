class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]+=1;
        }
        priority_queue<int>pq;
        priority_queue<pair<int,int>>p;
        for(auto i:mp){
            pq.push(i.second);
        }
        for(int i=0;i<pq.top()-1;i++){
            p.push({n,i});
        }
        cout<<n<<" ";
        vector<pair<int,int>>vec;
        int r = pq.top()-1;
        int maxi = pq.top()+((pq.top()-1)*n);
        cout<<maxi<<" ";
        pq.pop();
        while(!pq.empty()){
            int tp = pq.top();
            if(p.empty()){
                 maxi+=pq.top();
            }
            else{
                int cntt=0;
                while(!p.empty() and tp){
                    int index = p.top().second;
                    int val = p.top().first;
                    if(val-1!=0){
                        vec.push_back({val-1,index});
                    }
                    else{
                        cntt++;
                    }
                    p.pop();
                    tp--;
                }
                cout<<tp<<" "<<vec.size()<<endl;
                if(tp==1){
                    maxi=maxi+1;
                    for(int i=0;i<vec.size();i++){
                        p.push(vec[i]);
                    }
                    vec.clear(); 
                }
                else{
                    maxi+=(tp);
                    for(int i=0;i<vec.size();i++){
                        p.push(vec[i]);
                    }
                    vec.clear(); 
                }
            }
            cout<<maxi<<" ";
            pq.pop();
        }
        return maxi;
    }
};