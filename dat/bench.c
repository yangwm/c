#include <stdio.h>
#include <time.h>
#include "ipip.h"

int main() {
    int times = 50000;
    clock_t start = clock();
    init("17monipdb.dat");
    for (int i = 0; i < times; i++) {
        char *ip = "8.8.8.8";
        char result[128];
        find(ip, result);
        //printf("%s -> %s", ip, result);
    }
    destroy();
    clock_t finish = clock();
    printf("find ip %d times, consumeTime %f seconds\n\r\n", times, (double)(finish - start) / CLOCKS_PER_SEC);
    return 0;
}

/*
1. for {init; + destroy;}
find ip 50000 times, consumeTime 15.300000 seconds

2. init; for {} destroy;
find ip 50000 times, consumeTime 0.020000 seconds
*/

