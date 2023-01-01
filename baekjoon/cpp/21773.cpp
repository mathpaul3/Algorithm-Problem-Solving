#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct moo
{
    int a,b,c;
};
//id, time, prio
typedef struct moo moo;
struct compare
{
    bool operator()(moo &I, moo &C)
    {
        if(C.c != I.c)
            return C.c > I.c;
        return C.a < I.a;
    }
};
priority_queue <moo, vector <moo>, compare> pq;
moo p[100000];
int main(int argc, char **argv)
{
    int T, n; scanf("%d %d\n",&T, &n);
    for(int i=0; i<n;i++)
    {
        scanf("%d %d %d\n",&(p[i].a), &(p[i].b), &(p[i].c));
        pq.push(p[i]);
    }
    for(int i=0; i<T; i++)
    {
        moo I = pq.top(); pq.pop();
        printf("%d\n",I.a);
        I.b -= 1; I.c -= 1;
        if(I.b > 0)
            pq.push(I);
    }
}