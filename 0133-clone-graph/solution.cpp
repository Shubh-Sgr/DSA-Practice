/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> ump;
        queue<Node*> q;
        if (!node){
            return NULL;
        }
        Node* root = new Node(node->val);   
        ump[node] = root;
        q.push(node);
        while (!q.empty()){
            Node* curr = q.front();
            q.pop();
            vector<Node*> neighb = curr->neighbors;
            int len = neighb.size();
            for (int i=0; i<len; i++){
                if (ump.find(neighb[i])==ump.end()){
                    Node* cloneNeighb = new Node(neighb[i]->val);
                    ump[neighb[i]] = cloneNeighb;
                    q.push(neighb[i]);
                }
                ump[curr]->neighbors.push_back(ump[neighb[i]]);
            }
        }
        return root;
    }
};
