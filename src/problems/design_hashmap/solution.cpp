class MyHashMap {
public:
    MyHashMap() {
        value.resize(1000001, -1);
    }
    
    void put(int key, int v) {
        value[key] = v;
    }
    
    int get(int key) {
        return value[key];
    }
    
    void remove(int key) {
        value[key] = -1;
    }

private:
    vector<int32_t> value;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */