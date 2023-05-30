#include <iostream>
#include <vector>
using namespace std;

int V, E, a, b;
int link[1001]={0,}, group[1001]={0,};
pair<int,int> g[1001]; // odd, even
int zeros=0, odds=0, evens=0;
int odd_groups=0, even_groups=0;
int cnt=0;

int parent(int node) {
    if (group[node] == node) return node;
    return group[node] = parent(group[node]);
}

void FFT() {
    cnt += even_groups-1;
}

void FTF() {
    cnt += odd_groups-1;
    odds -= (odd_groups-1)*2;
    cnt += (odds>2 ? (odds-2)/2:0);
}

void TFF() {
    cnt += zeros-1;
}

void FTT() {
    if (!even_groups) {
        FTF();
    } else if (even_groups==1) {
        cnt++;
        even_groups--;
        FTF();
    } else if (even_groups>1) {
        cnt += even_groups-1;
        evens -= 2;
        odds += 2;
        odd_groups++;
        FTF();
    }
}

void TFT() {
    if (zeros==1) {
        if (even_groups==1) {
            cnt++;
        } else {
            cnt++;
            odds += 2;
            zeros--; evens--;
            odd_groups++;
            FTT();
        }
    } else {
        if (even_groups==1) {
            cnt += zeros-1;
            odds += 2;
            odd_groups++;
            FTT();
        } else {
            odds += 2;
            odd_groups++;
            FTT();
        }
    }
}

void TTF() {
    if (zeros==1) {
        cnt++;
        FTF();
    } else {
        cnt += zeros-1;
        odds += 2;
        odd_groups++;
        FTF();
    }
}

void TTT() {
    if (zeros==1) {
        cnt++;
        FTT();
    } else {
        cnt += zeros-1;
        odds += 2;
        odd_groups++;
        FTT();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;

    // 그룹 초기화
    for (int i=1; i<=V; i++)
        group[i] = i;

    // 입력 받으며 group union
    while (E--) {
        cin >> a >> b;
        link[a]++;
        link[b]++;
        a = parent(a);
        b = parent(b);
        if (a>b) { a^=b; b^=a; a^=b; }
        group[b] = a;
    }

    // 다른 정점과 연결되지 않은 정점 개수 세기
    // 각 그룹별 간선의 개수가 홀수인 정점 개수와 간선의 개수가 짝수인 정점 개수 세기
    for (int i=1; i<=V; i++) {
        group[i] = parent(i);
        if (!link[i]) zeros++;
        else if (link[i]%2) g[group[i]].first++;
        else g[group[i]].second++;
    }

    // 간선의 개수가 홀수인 정점 개수 && 간선의 개수가 짝수인 정점 개수세기
    // 그룹 내에 간선의 개수가 홀수인 정점이 있는 그룹의 개수 &&
    // 그룹 내에 간선의 개수가 홀수인 정점이 없는 그룹의 개수 세기
    for (int i=1; i<=V; i++) {
        if (g[i].first || g[i].second) {
            odds += g[i].first;
            evens += g[i].second;
            if (g[i].first) {
                odd_groups++;
            } else {
                even_groups++;
            }
        }
    }

    int select = (zeros ? (1<<2):0) + (odds ? (1<<1):0) + (evens ? (1<<0):0);
    switch(select) {
        case 1: FFT(); break;
        case 2: FTF(); break;
        case 3: FTT(); break;
        case 4: TFF(); break;
        case 5: TFT(); break;
        case 6: TTF(); break;
        case 7: TTT(); break;
    }
    cout << cnt << '\n';
    return 0;
}