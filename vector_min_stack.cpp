class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		stk.push(x);

		if (minElmtStk.empty() || x <= minElmtStk.top()) {
			minElmtStk.push(x);
		}
	}

	void pop() {
		if (!stk.empty()) {
			if (stk.top() == minElmtStk.top()) {
				minElmtStk.pop();
			}
			stk.pop();
		}
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minElmtStk.top();
	}

private:
	stack<int> stk;
	stack<int> minElmtStk;
};

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		stk.push(x);

		if (!minElmtStk.empty()) {
			int &currMin = minElmtStk.top();
			if (currMin < x) {
				minElmtStk.push(currMin);
			}
			else {
				minElmtStk.push(x);
			}
		}
		else {
			minElmtStk.push(x);
		}
	}

	void pop() {
		if (!stk.empty()) {
			stk.pop();
			minElmtStk.pop();
		}
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minElmtStk.top();
	}

private:
	stack<int> stk;
	stack<int> minElmtStk;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
