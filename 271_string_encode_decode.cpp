class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string msg;

        for (const string &str : strs)
        {
            const int len = str.size();

            char buf[9];
            snprintf(buf, sizeof(buf), "%08x", len);

            // length
            msg += buf;
            // value
            msg += str;
        }

        return msg;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;

        const int tLen = s.size();
        size_t pos = 0;
        while (pos < tLen)
        {
            // length
            const int len = stoi(s.substr(pos, 8), nullptr, 16);

            // value
            pos += 8;
            strs.push_back(s.substr(pos, len));

            pos += len;
        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

/*
 * 271. Encode and Decode Strings
 *
 * Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
 *
 * Machine 1 (sender) has the function:
 *
 * string encode(vector<string> strs) {
 *   // ... your code
 *   return encoded_string;
 * }
 * Machine 2 (receiver) has the function:
 * vector<string> decode(string s) {
 *   //... your code
 *   return strs;
 * }
 * So Machine 1 does:
 *
 * string encoded_string = encode(strs);
 * and Machine 2 does:
 *
 * vector<string> strs2 = decode(encoded_string);
 * strs2 in Machine 2 should be the same as strs in Machine 1.
 *
 * Implement the encode and decode methods.
 *
 * You are not allowed to solve the problem using any serialize methods (such as eval).
 */
