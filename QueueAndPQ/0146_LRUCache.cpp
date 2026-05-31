class LRUCache {
public:
    unordered_map<int,pair<int,list<int>::iterator>>mp;
    list<int>l;
    int sz;
    LRUCache(int capacity) {
        sz=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            list<int>::iterator addr = mp[key].second;
            l.erase(addr);
            l.push_front(key);
            mp[key]={mp[key].first,l.begin()};
            return mp[key].first;
        }else return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
             list<int>::iterator addr = mp[key].second;
             l.erase(addr);
             l.push_front(key);
             mp[key]={value,l.begin()};
        }else{
            if(l.size()>=sz){
                int ele=l.back();
                l.erase(mp[ele].second);
                mp.erase(ele);
                l.push_front(key);
                mp[key]={value,l.begin()};
            }else{
                l.push_front(key);
                mp[key]={value,l.begin()};
            }
        }
    }
};

