// Runtime: 13 ms
class Solution {
public:
    static bool compare(const Interval &a, const Interval &b)
    {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<=1)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);

        while(1)
        {
            int f = 1;
            vector<Interval> res;
            int done = 0;
            for(int i=0;i<intervals.size()-1;i++)
            {
                if(intervals[i].end >= intervals[i+1].start)
                {
                    res.push_back(Interval(intervals[i].start, max(intervals[i+1].end, intervals[i].end)));
                    i++;
                    f = 0;
                    if(i == intervals.size()-1)
                        done = 1;
                }
                else if(intervals[i].start == intervals[i+1].start)
                {
                    res.push_back(Interval(intervals[i].start, max(intervals[i+1].end,intervals[i].end)));
                    i++;
                    f = 0;
                    if(i == intervals.size()-1)
                        done = 1;

                }
                else
                {
                    res.push_back(intervals[i]);
                    if(i+1 == intervals.size()-1)
                        res.push_back(intervals[i+1]);
                }
            }
            if(!done)
                    res.push_back(intervals[intervals.size()-1]);

            if(f)   break;
            intervals = res;
        }
        return intervals;
    }
};
