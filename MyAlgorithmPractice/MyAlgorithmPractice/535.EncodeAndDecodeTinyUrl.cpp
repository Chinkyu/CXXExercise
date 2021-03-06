#include <iostream>
#include <string>
#include <map>

using namespace std;


class ShortUrlTest_Solution {
public:
	string idToShortURL(long int n)
	{
		// Map to store 62 possible characters
		char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
			"GHIJKLMNOPQRSTUVWXYZ0123456789";

		string shorturl;

		// Convert given integer id to a base 62 number
		while (n)
		{
			shorturl.push_back(map[n % 62]);
			n = n / 62;
		}

		// Reverse shortURL to complete base conversion
		reverse(shorturl.begin(), shorturl.end());

		return shorturl;
	}

	// Function to get integer ID back from a short url
	long int shortURLtoID(string shortURL)
	{
		long int id = 0; // initialize result

		// A simple base conversion logic
		for (int i = 0; i < shortURL.length(); i++)
		{
			if ('a' <= shortURL[i] && shortURL[i] <= 'z')
				id = id * 62 + shortURL[i] - 'a';
			if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
				id = id * 62 + shortURL[i] - 'A' + 26;
			if ('0' <= shortURL[i] && shortURL[i] <= '9')
				id = id * 62 + shortURL[i] - '0' + 52;
		}
		return id;
	}



	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {

	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {

	}
};


int _main() {
	char c;
	ShortUrlTest_Solution sol;

	for (int i = 0; i < 100000; ++i) {
		string s = sol.idToShortURL(i);
		cout << i << " " << s << " : " << sol.shortURLtoID(s) << endl;
	}


	cin >> c;
}


class Solution {
public:
	map<string, int> mUrltoId;
	map<int, string> mIdtoUrl;
	int idx = 0;

	string idToShortURL(int n)
	{
		// Map to store 62 possible characters
		char map[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
			"GHIJKLMNOPQRSTUVWXYZ0123456789";

		string shorturl;

		// Convert given integer id to a base 62 number
		while (n)
		{
			shorturl.push_back(map[n % 62]);
			n = n / 62;
		}

		// Reverse shortURL to complete base conversion
		reverse(shorturl.begin(), shorturl.end());

		return shorturl;
	}

	// Function to get integer ID back from a short url
	int shortURLtoID(string shortURL)
	{
		long int id = 0; // initialize result

		// A simple base conversion logic
		for (int i = 0; i < shortURL.length(); i++)
		{
			if ('a' <= shortURL[i] && shortURL[i] <= 'z')
				id = id * 62 + shortURL[i] - 'a';
			if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
				id = id * 62 + shortURL[i] - 'A' + 26;
			if ('0' <= shortURL[i] && shortURL[i] <= '9')
				id = id * 62 + shortURL[i] - '0' + 52;
		}
		return id;
	}


	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		auto it = mUrltoId.find(longUrl);
		if (it != mUrltoId.end()) {
			return idToShortURL(it->second);
		}
		else {
			mUrltoId[longUrl] = idx;
			mIdtoUrl[idx] = longUrl;
			return idToShortURL(idx++);
		}
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		int id = shortURLtoID(shortUrl);
		return mIdtoUrl[id];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

