class LRUCache {
  int capacity;
  list<pair<int, int>> cacheList;
  unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    if (cacheMap.find(key) == cacheMap.end())
      return -1;
    auto it = cacheMap[key];
    cacheList.splice(cacheList.begin(), cacheList, it);
    return it->second;
  }

  void put(int key, int value) {
    if (cacheMap.find(key) != cacheMap.end()) {
      auto it = cacheMap[key];
      cacheList.erase(it);
    }
    cacheList.push_front({key, value});
    cacheMap[key] = cacheList.begin();
    if (cacheList.size() > capacity) {
      auto last = cacheList.back();
      cacheMap.erase(last.first);
      cacheList.pop_back();
    }
  }
};
