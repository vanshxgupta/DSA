#include <bits/stdc++.h>
using namespace std;


struct Node{
    int key;
    int val;
    Node*next;
    Node*prev;

    Node(int k,int v){//constructor
        key=k;
        val=v;
        next=NULL;
        prev=NULL;
    }
};


//now we will implement the LRU cache class

class LRUCache{
    public:
    Node*head;
    Node*tail;
    int capacity;
    unordered_map<int,Node*>mp;//{key,address}

    //create a construcor
    LRUCache(int capacity){
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    //now we will be creating some functions inside the LRUcache ,to get , put in the LRU cache

    int get(int key){

        if(mp.find(key)==mp.end()){
            //that means the element is not present , so we will be returning -1
            return -1;
        }
        else{
            //we will return the element , and also change the position of that node to the front

            //so delete node from the list
            Node*node=mp[key];
            remove(node);

            // Add a node right after the head 
            // (most recently used position)
            add(node);

            return mp[key]->val;
        }
    }

    void put(int key,int val){
        //putting the element in the LRU cache 

        //first we will check if the element is already present or not 
        //if already present , we will just delete that value from the list and add that update the value of the node and add to the front
        if(mp.find(key)!=mp.end()){
            Node*node=mp[key];
            remove(node);
            delete node;

            node=new Node(key,val);
            mp[key]=node;
            add(node);
        }
        else{
            //if not already present , then make a new node and put it in the cache
            Node*node=new Node(key,val);
            mp[key]=node;
            add(node);

            //we will check if the size of LRU_cache does not exceed its capacity
            if(mp.size()>capacity){
                //remove the least recently used from the last of the LRU_cache
                Node*nodetodelete=tail->prev;
                remove(nodetodelete);
                mp.erase(nodetodelete->key);
                delete nodetodelete; // fixed: delete the correct node
            }
        }
    }


    // Add a node right after the head 
    // (most recently used position)
    void add(Node*node){
        Node*headnext=head->next;
        head->next=node;
        node->prev=head;
        node->next=headnext;
        headnext->prev=node;
    }

    //delete the node from the list 
    void remove(Node*node){
        Node*nodeprev=node->prev;
        Node*nodenext=node->next;
        nodeprev->next=nodenext;
        nodenext->prev=nodeprev;
    }

    
};

// //with stl of doublylinked list
// class LRU_Cache {
//   public:
//     int capacity;
//     list<pair<int, int>> List;

//     // Map from key to list iterator
//     unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

//     // Constructor to initialize the 
//       //cache with a given capacity
//     LRU_Cache(int capacity) {
//         this->capacity = capacity;
//     }

//     // Function to get the value for a given key
//     int get(int key) {
//         auto it = cacheMap.find(key);
//         if (it == cacheMap.end()) {
//             return -1;
//         }

//         // Move the accessed node to the 
//           //front (most recently used position)
//         int value = it->second->second;
//         List.erase(it->second);
//         List.push_front({key, value});

//         // Update the iterator in the map
//         cacheMap[key] = List.begin();
//         return value;
//     }

//     // Function to put a key-value pair into the cache
//     void put(int key, int value) {
//         auto it = cacheMap.find(key);
//         if (it != cacheMap.end()) {
//             // Remove the old node from the list and map
//             List.erase(it->second);
//             cacheMap.erase(it);
//         }

//         // Insert the new node at the front of the list
//         List.push_front({key, value});
//         cacheMap[key] = List.begin();

//         // If the cache size exceeds the capacity,
//           //remove the least recently used item
//         if (cacheMap.size() > capacity) {
//             auto lastNode = List.back().first;
//             List.pop_back();
//             cacheMap.erase(lastNode);
//         }
//     }
// };

int main(){
    LRUCache cache(2);
  
    cache.put(1, 5); 
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout  << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    // LRU_Cache cachewithstl(2);
    // cachewithstl.put(1, 5); 
    // cachewithstl.put(2, 2);
    // cout << cachewithstl.get(1) << endl;
    // cachewithstl.put(3, 3);
    // cout  << cachewithstl.get(2) << endl;
    // cachewithstl.put(4, 4);
    // cout << cachewithstl.get(1) << endl;
    // cout << cachewithstl.get(3) << endl;
    // cout << cachewithstl.get(4) << endl;


    return 0;
}



