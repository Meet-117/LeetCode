class Solution {
public:
    vector<int> spf;

    void sieve(int MAXV) {
        spf.resize(MAXV + 1);

        for (int i = 0; i <= MAXV; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= MAXV; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    bool isPrime(int x) { return x >= 2 && spf[x] == x; }

    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        while (x > 1) {
            int p = spf[x];
            factors.push_back(p);

            while (x % p == 0) {
                x /= p;
            }
        }

        return factors;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        int MAXV = *max_element(nums.begin(), nums.end());

        sieve(MAXV);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            vector<int> factors = getPrimeFactors(nums[i]);

            for (int p : factors) {
                mp[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1)
                return d;

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (isPrime(val)) {
                for (int nxt : mp[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }

                mp[val].clear();
            }
        }

        return -1;
    }
};