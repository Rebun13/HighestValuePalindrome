#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {
    int diffCounter = 0;
    for(int i = 0; i < n/2; ++i) {
        if(s.at(i) != s.at(n-1-i)) {
            diffCounter++;
        }
    }
    if(diffCounter > k) return "-1";
    int setBothCounter = k - diffCounter;
    cout << "diffCounter: " << diffCounter << "; setBothCounter: " << setBothCounter << endl;
    for(int i = 0; i < n/2; ++i) {
        if(setBothCounter > 0 && (s.at(i) != '9' || s.at(n-1-i) != '9')) {
            cout << "Set both at 9 in index " << i << endl;
            s.replace(i, 1, "9");
            s.replace(n - 1 - i, 1, "9");
            diffCounter--;
            k -= 2;
        } else {
            if(s.at(i) != s.at(n-1-i)) {
                if(s.at(i) > s.at(n-1-i)) {
                    cout << "Set right to: " << s.at(i) << endl;
                    s.replace(n - 1 - i, 1, 1, s.at(i));
                    k--;
                } else {
                    cout << "Set left to: " << s.at(n-1-i) << endl;
                    s.replace(i, 1, 1, s.at(n-1-i));
                    k--;
                }
            }
        }
    }
    cout << "Remaining changes: " << k << endl;
    if(n % 2 == 1 && k > 0) {
        cout << "Changed mid value!" << endl;
        s.replace(n / 2, 1, "9");
    }
    return s;
      
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
