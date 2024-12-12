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

        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> mp; // mapping old node to new node
        mp[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* topele = q.front();
            Node* copy_node;
            q.pop();

            if(mp.find(topele) == mp.end()){ //first time encountering the node
                copy_node = new Node(topele->val); // create a copy
                mp[topele] = copy_node; 
            }
            else{
                copy_node = mp[topele];
            }

            for(auto nbr: topele->neighbors){
                Node* neighbor;
                if(mp.find(nbr) == mp.end()){ //first time encountering the node
                    neighbor = new Node(nbr->val); // create a copy
                    mp[nbr] = neighbor;
                    q.push(nbr);
                }
                else{
                    neighbor = mp[nbr];
                }
                copy_node->neighbors.push_back(neighbor);
            }
        }

        return mp[node];
    }
};
