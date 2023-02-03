#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int N, M, village[100001]={0,}, cost=0, max_cost=0;
priority_queue<tuple<int,int,int> > roads;

int find_village(int house) {
    if (village[house] == house) return house;
    return village[house]=find_village(village[house]);
}

bool merge_house(int A, int B) {
    A = find_village(A);
    B = find_village(B);
    if (A == B) return false;
    if (A < B) village[B] = A;
    else village[A] = B;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<N; i++) village[i] = i;
    for (int i=0; i<M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        roads.push(make_tuple(-C, A, B));
    }
    while (!roads.empty()) {
        int C, A, B;
        tie(C, A, B) = roads.top(); roads.pop();
        if (merge_house(A, B)) {
            cost -= C;
            if (max_cost < -C) max_cost = -C;
        }
    }
    cout << cost-max_cost << '\n';

    return 0;
}