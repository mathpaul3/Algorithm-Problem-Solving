#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<tuple<double,int,string>> items;
    string itemName;
    int numberOfSales;
    double profitEachSale;
    
    while (cin >> itemName >> numberOfSales >> profitEachSale)
        items.push_back(make_tuple(numberOfSales*profitEachSale, numberOfSales, itemName));
    sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        if (get<0>(a)==get<0>(b)) {
            if (get<1>(a)==get<1>(b))
                return get<2>(a) < get<2>(b);
            return get<1>(a) > get<1>(b);
        }
        return get<0>(a) > get<0>(b);
    });
    cout << fixed;
    cout.precision(2);
    for (int i=0; i<items.size(); i++) {
        double totalProfit;
        tie(totalProfit, numberOfSales, itemName) = items[i];
        cout << '$' << totalProfit << " - " << itemName << '/' << numberOfSales << '\n';
    }
    return 0;
}