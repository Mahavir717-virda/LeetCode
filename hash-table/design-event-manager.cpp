class EventManager {
public:
    unordered_map<int, int> mp;
    set<pair<int, int>> active;

    EventManager(vector<vector<int>>& events) {

        for (auto& e : events) {
            int id = e[0], p = e[1];
            mp[id] = p;
            active.insert({-p, id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldPrio = mp[eventId];
        active.erase({-oldPrio, eventId});
        
        mp[eventId] = newPriority;
        active.insert({-newPriority, eventId});
    }
    
    int pollHighest() {
        if (active.empty()) return -1;

        auto it = active.begin();
        int id = it->second;

        active.erase(it);
        mp.erase(id);

        return id;
    }
};
