// Runtime: 108 ms
// Memory Usage: 38 MB
class LRUCache {

private:
  typedef list<pair<int, int> > lpii;

  lpii pairs;
  unordered_map<int, lpii::iterator> cache;
  int capacity;

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
  }

  int get(int key) {
    auto pt = cache.find(key);
    if (pt == cache.end()) return -1;

    //Move pair to the begining of the list.
    pairs.splice(pairs.begin(), pairs, pt->second);

    return pt->second->second;
  }

  void put(int key, int value) {
    auto pt = cache.find(key);
    if (pt == cache.end()) {

      if (pairs.size() == capacity) {
        cache.erase(pairs.back().first);
        pairs.pop_back();
      }

      pairs.emplace_front(key, value);
      cache[key] = pairs.begin();
    } else {
      pt->second->second = value;
      pairs.splice(pairs.begin(), pairs, cache[key]);
    }
  }
};