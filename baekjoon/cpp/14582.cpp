    #include <iostream>
    using namespace std;

    bool tmp_win, res_win;
    int j_score[9], g_score[9], j_sum, g_sum;

    int main() {
        for (int i=0; i<9; i++) cin >> j_score[i];
        for (int i=0; i<9; i++) cin >> g_score[i];
        for (int i=0; i<9; i++) {
            j_sum += j_score[i];
            if (j_sum>g_sum) tmp_win = true;
            g_sum += g_score[i];
        }
        if (j_sum>g_sum) res_win = true;
        cout << (tmp_win && !res_win ? "Yes\n" : "No\n");
        return 0;
    }