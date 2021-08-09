class Solution {
public:

    Solution() {
        alphas = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        prefix = "http://tinyurl.com/";
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key;
        do {
            key = getRandom();
        } while(cache.find(key) != cache.end());

        cache[key] = longUrl;
        return prefix + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return cache[shortUrl.substr(shortUrl.find_last_of('/') + 1)];
    }

    string getRandom() {
        string result;
        for(int i = 0; i < 6; i++) {
            result.append(1, alphas[rand() % 62]);
        }
        return result;
    }

private:
    unordered_map<string, string> cache;
    string alphas;
    string prefix;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
