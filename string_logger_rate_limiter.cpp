class Logger {
public:
	/** Initialize your data structure here. */
	Logger() {
	}

	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
	    If this method returns false, the message will not be printed.
	    The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		auto it = strTimestamp.find(message);
		if (it != strTimestamp.end()) {
			if (timestamp - it->second >= 10) {
				it->second = timestamp;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			// it == strTimestamp.end()
			strTimestamp.emplace(message, timestamp);
			return true;
		}
	}
private:
	unordered_map<string, int> strTimestamp;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

/*
 * Example:
 *
 * Logger logger = new Logger();
 *
 * // logging string "foo" at timestamp 1
 * logger.shouldPrintMessage(1, "foo"); returns true;
 *
 * // logging string "bar" at timestamp 2
 * logger.shouldPrintMessage(2,"bar"); returns true;
 *
 * // logging string "foo" at timestamp 3
 * logger.shouldPrintMessage(3,"foo"); returns false;
 *
 * // logging string "bar" at timestamp 8
 * logger.shouldPrintMessage(8,"bar"); returns false;
 *
 * // logging string "foo" at timestamp 10
 * logger.shouldPrintMessage(10,"foo"); returns false;
 *
 * // logging string "foo" at timestamp 11
 * logger.shouldPrintMessage(11,"foo"); returns true;
 */
