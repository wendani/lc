class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = vp.find(key);
		if (it != vp.end()) {
			recencies.splice(recencies.end(), recencies, it->second->recency_pos);
			return it->second->val;
		}

		return -1;
	}

	void put(int key, int value) {
		auto it = vp.find(key);
		if (it != vp.end()) {
			it->second->val = value;
			recencies.splice(recencies.end(), recencies, it->second->recency_pos);
			return;
		}

		// reach here when key is not present
		if (size == cap) {
			vp.erase(recencies.front());
			recencies.pop_front();
		}
		else {
			// size < cap
			++size;
		}

		auto p = vp.emplace(key, new node(value, recencies.end()));
		recencies.push_back(p.first);
	}

private:
	struct node {
		node(int v, list<unordered_map<int, node *>::iterator>::iterator it) : val(v), recency_pos(it) {
		}

		int val;
		list<unordered_map<int, node *>::iterator>::iterator recency_pos;
	};

	list<unordered_map<int, node *>::iterator> recencies;

	unordered_map<int, node *> vp;

	int cap;
	int size = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
