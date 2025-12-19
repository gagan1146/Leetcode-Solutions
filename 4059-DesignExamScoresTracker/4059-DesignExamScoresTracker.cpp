// Last updated: 19/12/2025, 19:20:23
class ExamTracker {
public:
    vector<pair<int,long long>>v;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        if(v.empty()) v.push_back({time,score});
        else v.push_back({time,v.back().second+score});
    }
    
    long long totalScore(int startTime, int endTime) {
        auto it1=lower_bound(v.begin(),v.end(),make_pair(startTime,0LL));
        auto it2 = upper_bound(v.begin(),v.end(),make_pair(endTime, LLONG_MAX));
        if(it1==v.end() || it1==it2) return 0;
        long long r = prev(it2)->second, l=(it1==v.begin()?0:prev(it1)->second);
        return r-l;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */