#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007LL

int cmp(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = (long long *)malloc(sizeof(long long) * (size_t)n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, n, sizeof(long long), cmp);

    long long total = (long long)n * (n - 1) / 2;

    long long sameSum = 0;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && arr[j] == arr[i]) j++;
        long long cnt = j - i;
        sameSum += cnt * (cnt - 1) / 2;
        i = j;
    }

    long long answer = (total - sameSum) % MOD;
    if (answer < 0) answer += MOD;

    printf("%lld\n", answer);

    free(arr);
    return 0;
}
