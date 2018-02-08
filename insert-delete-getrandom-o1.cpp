//Runtime: 52 ms
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    map<int, int> mp;
    vector<int> temp;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ret = false;
        if (mp.find(val) == mp.end()) {
            ret = true;
            mp[val] = temp.size();
            temp.push_back(val);
        }

        return ret;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ret = false;
        if (mp.find(val) != mp.end()) {
            ret = true;
            int idx = mp[val];
            swap(temp[temp.size() - 1], temp[idx]);
            mp[temp[idx]] = idx;
            temp.pop_back();
            mp.erase(val);
        }

        return ret;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return temp[rand() % temp.size()];
    }
};


//Runtime: 134 ms
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    set<int> s;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ret = false;
        if (s.find(val) == s.end())
            ret = true;
        s.insert(val);
        return ret;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ret = false;
        if (s.find(val) != s.end())
            ret = true;
        s.erase(val);
        return ret;
    }

    /** Get a random element from the set. */
    int getRandom() {
        auto it = s.begin();
        advance(it, (rand() % s.size()));
        return *it;
    }
};
