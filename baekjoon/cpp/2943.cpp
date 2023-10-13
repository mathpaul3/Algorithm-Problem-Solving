#include <iostream>
using namespace std;

int N, M, S, A, K=1, matchMod, cupMax;
int cup[1000]={0,}, matchbox[100001]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    while (K*K<=N) K++;
    K--; matchMod = N%K; cupMax = N/K+(bool)(N%K);

    while (M--) {
        int match=0;
        cin >> S >> A;
        if (A%K!=1) {
            int lim = (K-((A-1)%K)<=S ? K-((A-1)%K) : S);
            for (int i=0; i<lim; i++) 
                match += ++matchbox[A+i];
            S -= lim;
            A += lim;
        }
        for (int i=0; i<S/K; i++)
            match += ++cup[A/K+1+i];
        A += S/K*K;
        S %= K;
        if (A/K==cupMax-1 && S==matchMod) {
            if (S) match += ++cup[A/K+1];
        } else {
            for (int i=0; i<S; i++)
                match += ++matchbox[A+i];
        }
        cout << match << '\n';
    }
    return 0;
}