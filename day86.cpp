
struct cmp
{
    bool operator()(pair<int,string> const&a , pair<int,string> const&b){
        if(a.first==b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
class Solution {
public:
    typedef pair<int,string>pd;
    vector<string> watchedVideosByFriends(vector<vector<string>>& nums, vector<vector<int>>& friends, int id, int level) {
        int n = nums.size();
        vector<int>vis(n+1,0);
        queue<int>q;
        q.push(id);
        vis[id] = 1;
        int lvl = -1;
        while(!q.empty())
        {
            int sz = q.size();
            lvl++;
            if(lvl == level)
            {
                break;
            }
            while(sz--)
            {
                int val = q.front();
                q.pop();
                for(int i = 0 ; i < friends[val].size() ; i++)
                {
                    if(!vis[friends[val][i]])
                    {
                        q.push(friends[val][i]);
                        vis[friends[val][i]] = 1;
                    }
                }
            }
        }
        map<string,int>seen;
        while(!q.empty())
        {
            int val = q.front();
            for(int i = 0 ; i < nums[val].size() ; i++)
            {
                seen[nums[val][i]]++;
            }
            q.pop();
        }
        priority_queue<pd , vector<pd>, cmp>pq;
        for(auto it : seen)
        {
             pq.push({it.second,it.first});
        }
        vector<string>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};