#include <iostream>
#include <vector>
#include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity):capacity_(capacity) {
        
    }
    
    int get(int key) {
        if(caches_.empty()){
            return -1;
        }
    }
    
    void put(int key, int value) {

    }
public:
    list<int> caches_;
    int capacity_;
};

int main(){

}