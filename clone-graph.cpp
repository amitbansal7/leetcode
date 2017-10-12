//Runtime: 36 ms
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if(!node) return NULL;
        queue<UndirectedGraphNode*> Q;
        map<UndirectedGraphNode*, UndirectedGraphNode* > Mp;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        Mp[node] = copy;
        Q.push(node);

        while(!Q.empty())
        {
            UndirectedGraphNode* t = Q.front();
            Q.pop();

            for(UndirectedGraphNode* crawl:t->neighbors)
            {
                if(Mp.find(crawl) == Mp.end())
                {
                    UndirectedGraphNode* newnode = new UndirectedGraphNode(crawl->label);
                    Mp[crawl] = newnode;
                    Q.push(crawl);
                }
                Mp[t]->neighbors.push_back(Mp[crawl]);
            }
        }

        return copy;
    }
};
