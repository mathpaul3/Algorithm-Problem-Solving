#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm* tInfo = localtime(&t);
    printf("%d-%d-%d\n", (tInfo->tm_year)+1900, (tInfo->tm_mon)+1, (tInfo->tm_mday));
    return 0;
}