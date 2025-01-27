//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity; // Maximum capacity of the cache.
    std::list<int> order; // Doubly linked list to store keys in LRU order.
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache; 
    // Hash map: key -> {value, iterator to key's position in `order`}.

public:
    // Constructor to initialize the cache with given capacity.
    LRUCache(int cap) : capacity(cap) {}

    // Function to return value corresponding to the key.
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found in the cache.
        }
        // Move the accessed key to the front (most recently used).
        order.erase(cache[key].second); // Remove the key from its current position.
        order.push_front(key); // Move key to the front.
        cache[key].second = order.begin(); // Update iterator in the hash map.
        return cache[key].first; // Return the associated value.
    }

    // Function to store a key-value pair.
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If the key exists, update the value and move it to the front.
            order.erase(cache[key].second); // Remove the key from its current position.
        } else {
            if (cache.size() == capacity) {
                // If the cache is at capacity, evict the least recently used key.
                int lru = order.back(); // Get the least recently used key.
                order.pop_back(); // Remove the LRU key from the list.
                cache.erase(lru); // Remove the LRU key from the hash map.
            }
        }
        // Insert the new key-value pair or update the existing one.
        order.push_front(key); // Insert the key at the front.
        cache[key] = {value, order.begin()}; // Update the hash map with the new value and iterator.
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends