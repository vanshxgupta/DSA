#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> vec(k);
    long long ansxor = 0;
    long long curr = x;
    long long ansor = 0;
    vector<long long> freq(32, 0);

    for (long long i = 0; i < k; i++)
    {
        if (i > 0)
        {
            curr = (1LL * curr * a + b) % c;
        }

        vec[i] = curr;
        ansor |= curr;

        for (long long j = 0; j < 31; j++)
            freq[j] += (curr >> j) & 1;
    }
    ansxor = ansxor ^ ansor;

    long long pos = 0;
    for (long long i = k; i < n; i++)
    {
        long long oldele = vec[pos];
        curr = (1LL * curr * a + b) % c;
        long long newele = curr;
        vec[pos] = newele;
        ansor = 0;
        for (long long j = 0; j < 31; j++)
        {
            freq[j] -= ((oldele >> j) & 1);
            freq[j] += ((newele >> j) & 1);
            if (freq[j] >= 1)
            {
                ansor = ansor | (1LL << j);
            }
        }
        ansxor = ansxor ^ ansor;
        pos++;
        if (pos == k)
            pos = 0;
    }
    cout << ansxor << endl;
}