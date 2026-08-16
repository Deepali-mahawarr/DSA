class Node{
  public:  
    int key,val;
    Node* next;
    Node* prev;
    Node(int _key, int _val){
       key=_key;
       val=_val;
       next=NULL;
       prev=NULL;
    }
};

   class LRUCache {
    unordered_map<int,Node*> mpp;
    int cap;
    Node* head;
    Node* tail;
   
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void deletenode(Node* node){
      Node* prevNode=node->prev;
      Node* nextNode=node->next;
      prevNode->next=nextNode;
      nextNode->prev=prevNode;
   }    
   void insertAfterhead(Node* node){
      Node* curr=head->next;
      head->next=node;
      node->prev=head;
      node->next=curr;
      curr->prev=node;
   }
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        deletenode(node);
        insertAfterhead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deletenode(node);
            insertAfterhead(node);
        }
        else{
            if(mpp.size()==cap){
                Node* node=tail->prev;
                mpp.erase(node->key);
                deletenode(node);
            }
                Node* temp=new Node(key,value);
                insertAfterhead(temp);  
                mpp[key]=temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */