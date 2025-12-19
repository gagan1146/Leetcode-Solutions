// Last updated: 19/12/2025, 19:22:48
class TaskManager {
private:
    struct T {
        int a, b, c;
        bool operator<(const T& d) const {
            if (a != d.a) return a > d.a;
            return c > d.c;
        }
    };

    unordered_map<int, T> mp;
    set<T> s;

public:
    TaskManager(vector<vector<int>>& d) {
        for (const auto& b : d) {
            T t = {b[2], b[0], b[1]};
            mp[b[1]] = t;
            s.insert(t);
        }
    }

    void add(int a, int b, int c) {
        T t = {c, a, b};
        mp[b] = t;
        s.insert(t);
    }

    void edit(int b, int a) {
        if (mp.count(b)) {
            T t = mp[b];
            s.erase(t);
            T nt = {a, t.b, t.c};
            mp[b] = nt;
            s.insert(nt);
        }
    }

    void rmv(int b) {
        if (mp.count(b)) {
            T t = mp[b];
            s.erase(t);
            mp.erase(b);
        }
    }

    int execTop() {
        if (s.empty()) return -1;
        T t = *s.begin();
        s.erase(t);
        mp.erase(t.c);
        return t.b;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */