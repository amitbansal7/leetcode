//Runtime: 19 ms
// O(nLog(n))
class Solution {
public:

    void MaxHeapify(vector<pair<int,int> >&nums, int i)
    {
        int l = 2*i+1;
        int r = 2*i+2;
        int largest = i;

        if(l < nums.size() && nums[l] > nums[largest])
            largest = l;

        if(r < nums.size() && nums[r] > nums[largest])
            largest = r;

        if(largest!=i)
        {
            swap(nums[largest], nums[i]);
            MaxHeapify(nums, largest);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> Mp;
        for(int a:nums)
            Mp[a]++;

        vector<pair<int,int> >Heap;

        for(auto M:Mp)
            Heap.push_back(make_pair(M.second,M.first));

        for(int i=Heap.size()/2-1;i>=0;i--)
            MaxHeapify(Heap, i);

        vector<int>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(Heap[0].second);
            Heap[0].first = -1;
            MaxHeapify(Heap, 0);
        }
        return res;
    }
};

//Runtime: 23 ms
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> Mp;
        for(int a:nums)
            Mp[a]++;

        priority_queue<pair<int,int> > pq;
        vector<int>res;
        for(auto M:Mp)
        {
            pq.push(make_pair(M.second, M.first));
            if(pq.size() > Mp.size()-k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }

        return res;
    }
};
