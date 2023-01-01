#include <iostream>
typedef long long ll;
using namespace std;

int N, M, K;
ll P[11];

ll simulate(int day, ll money, ll stock, ll loan) {
    if (day == N) {
        return money + P[day]*stock;
    }

    ll max = 0, tmp;
    ll sim_money, sim_stock, sim_loan;

    // 그대로
    tmp = simulate(day+1, money, stock, loan);
    max = (max < tmp ? tmp : max);

    // 매도
    tmp = simulate(day+1, money+stock*P[day], 0, loan);
    max = (max < tmp ? tmp : max);

    // 매수
    tmp = (money > loan ? loan : money);
    sim_money = money - tmp;
    sim_loan = loan - tmp;
    if (!sim_loan) {
        sim_loan = sim_money*K;
        sim_money += sim_loan;
    }
    if ((sim_money / P[day]) && sim_loan) {
        sim_stock = stock + sim_money / P[day];
        sim_money -= sim_stock * P[day];
        tmp = simulate(day+1, sim_money, sim_stock, sim_loan);
        max = (max < tmp ? tmp : max);
    }

    // 매도 & 매수
    sim_money = money + stock * P[day];
    tmp = (sim_money > loan ? loan : sim_money);
    sim_money = sim_money - tmp;
    sim_loan = loan - tmp;
    if (!sim_loan) {
        sim_loan = sim_money*K;
        sim_money += sim_loan;
    }
    if ((sim_money / P[day]) && sim_loan) {
        sim_stock = sim_money / P[day];
        sim_money -= sim_stock * P[day];
        tmp = simulate(day+1, sim_money, sim_stock, sim_loan);
        max = (max < tmp ? tmp : max);
    }

    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    
    for (int i=1; i<=N; i++) {
        cin >> P[i];
    }

    cout << simulate(1, M, 0, 0) << '\n';
    
    return 0;
}