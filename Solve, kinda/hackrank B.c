#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {    
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    
    long long v[3] = {a, b, c};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (v[j] < v[i]) {
                long long tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
    
    long long L = v[0], M = v [1], H = v[2];
    
    long long rounds;
    if (L == M || M == H) {
        
        rounds = 0;
    } else {
        long long t1 = M - L; 
        long long t2 = H - M; 
        rounds = (t1 < t2) ? t1 : t2;
    }
 
    printf("%lld\n", rounds);
    return 0;
}
