#include <stdio.h>
#include <string.h>

int i, nlen, mlen, neg=0;
char n[1001], m[1001], d[1001], cnt[1001];

int bigger(char *n, char *m)
{
    if (nlen < mlen) return 0;
    if (nlen > mlen) return 1;
    for (i=0; i<nlen; i++)
    {
        if ((int)n[i] < (int)m[i]) return 0;
        if ((int)n[i] > (int)m[i]) return 1;
    }
    return 1;
}

void minus(char *n, char *m, char *temp)
{
    if (!bigger(n, m)) {
        neg = 1;
        return ;
    }

    int bring=0;
    int ni, mi;
    for (i=nlen-1; i>=0; i--)
    {
        if (i-(nlen-mlen) >= 0) {
            ni = (int)n[i];
            mi = (int)m[i-(nlen-mlen)];
            if (bring) {
                ni--;
                bring = 0;
                if (ni<48) {
                    ni += 10;
                    bring = 1;
                }
            }
            if (ni<mi)
            {
                bring = 1;
                ni += 10;
            }
            temp[i] = (char)ni-mi+48;
        } else {
            ni = (int)n[i];
            if (bring) {
                ni--;
                bring = 0;
                if (ni<48) {
                    ni += 10;
                    bring = 1;
                }
            }
            temp[i] = (char)ni;
        }
    }

    int dec = 0;
    for (i=0; temp[i]=='0'; i++)
    { dec++; }
    if (dec)
    {
        memmove(temp, &temp[i], sizeof(char) * (nlen - dec+1));
        nlen -= dec;
    }

    return ;
}

void plusplus(char *temp)
{
    if ((int)temp[0]>57 || (int)temp[0]<48) {
        temp[0] = '1';
        return;
    }
    temp[0] = (char)((int)temp[0]+1);
    if ((int)temp[0]>57) {
        plusplus(temp+1);
        temp[0] = '0';
    }
    return;
}

void divide(char *n, char *m)
{
    while(1)
    {
        memset(d, 0, sizeof(char)*nlen);
        minus(n, m, d);
        if (neg) break;
        strcpy(n, d);
        plusplus(cnt);
    }
    return ;
}

int main() {
    scanf("%s %s", n, m);
    nlen = strlen(n);
    mlen = strlen(m);
    divide(n, m);

    printf("%s\n", n);
    for (i=strlen(cnt)-1; i>=0; i--)
        printf("%c", cnt[i]);
    return 0;
}