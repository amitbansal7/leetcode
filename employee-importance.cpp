//Runtime: 22 ms
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        queue<int>Q;
        Q.push(id);

        while(!Q.empty())
        {
            int t = Q.front();
            Q.pop();

            for(auto it:employees)
            {
                if(it->id == t)
                {
                    ans+=it->importance;

                    for(int emp:it->subordinates)
                        Q.push(emp);

                    break;
                }
            }
        }
        return ans;
    }
};
