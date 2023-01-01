#include <stdio.h>

int main() {
	int sang, jung, ha, coke, cy, hammin, drinkmin;
	scanf("%d %d %d %d %d", &sang, &jung, &ha, &coke, &cy);
	sang > jung ? jung > ha ? hammin=ha : hammin=jung : sang > ha ? hammin=ha : hammin=sang;
	coke > cy ? drinkmin=cy : drinkmin=coke;
	printf("%d", hammin+drinkmin-50);
}
