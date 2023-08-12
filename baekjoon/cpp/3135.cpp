#include <iostream>
using namespace std;

int main() {
    int A, B, N, freqs[5], button_min;
    cin >> A >> B >> N;
    for (int i=0; i<N; i++)
        cin >> freqs[i];
    
    button_min = (A<B ? B-A : A-B);
    for (int i=0; i<N; i++) {
        if (freqs[i]==B) {
            cout << 1 << '\n';
            return 0;
        } else {
            int diff = (freqs[i]<B ? B-freqs[i] : freqs[i]-B) + 1;
            if (button_min > diff)
                button_min = diff;
        }
    }
    cout << button_min << '\n';
    return 0;
}