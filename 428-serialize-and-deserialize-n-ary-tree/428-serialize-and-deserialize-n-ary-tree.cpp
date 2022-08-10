/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        
        string retVal = "";
        queue<vector<Node*>> bfsNode;
        
        if(!root)
            return retVal;
        else
        {
            retVal += to_string(root->val);
            bfsNode.push(root->children);
        }
        
        while(!bfsNode.empty())
        {
            retVal += ",null";
            vector<Node*> Nodes = bfsNode.front();
            bfsNode.pop();
            for(auto it = Nodes.begin(); it != Nodes.end(); it++)
            {
                Node* node = *it;
                retVal += ",";
                retVal += to_string(node->val);
                bfsNode.push(node->children);
            }
        }
        return retVal;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        
        Node* retNode = new Node();
        Node* tmpNode = new Node();
        if(data.length() == 0)
            return 0;
        
        queue<string> sptStr;
        
        map<int, vector<Node*>> mm;
        queue<Node*> q;
        vector<Node*> tempV;
        bool fst =  true;
        
        string temp;
        stringstream ss(data);
        
        while(getline(ss,temp,',')){
            sptStr.push(temp);
        }
        
        int start = stoi(sptStr.front());
        int fnt = stoi(sptStr.front());
        retNode = new Node(fnt);
        q.push(new Node(fnt));
        sptStr.pop();
        
        if(!sptStr.empty())
            sptStr.pop();
                
        while(!sptStr.empty() && !q.empty())
        {        
            string nowStr = sptStr.front();
            sptStr.pop();
                 
            if(nowStr == "null")
            {    
                tmpNode = q.front();
                if(fst)
                {
                    retNode = new Node(fnt, tempV);
                    fst = false;
                                    q.pop();
                tempV.clear();
                continue;
                }
                tmpNode->children = tempV;
                q.pop();
                tempV.clear();
                continue;
            }    
            Node *tt= new Node(stoi(nowStr));
            q.push(tt);
            tempV.push_back(tt);
        }
        
        //retNode = new Node(start, makeNode(start, mm));
        
        return retNode;
    }
    
    vector<Node*> makeNode(int NodeVal, map<int, vector<int>> mm)
    {
        vector<Node*> retNodes;
        vector<int> v = mm[NodeVal];
        
        for(int i = 0; i < v.size(); i++)
        {
            Node* N = new Node(v[i], makeNode(v[i], mm));
            retNodes.push_back(N);
        }
        
        return retNodes;    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));