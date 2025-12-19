// Last updated: 19/12/2025, 19:20:05
class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false; 
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false; 
        for (int i = 3; 1LL * i * i <= n; i += 2) { 
            if (n % i == 0)
                return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        int num1 = stoi(s);
        while (num > 0) {
            if (!isPrime(num))
                return false;
            num /= 10;
        }
        num = num1;
        while (num > 0) {
            string s = to_string(num);
            reverse(s.begin(),s.end());
            int x = stoi(s);
            if (!isPrime(x))
                return false;
            num /= 10;
        }
        return true;
    }
};