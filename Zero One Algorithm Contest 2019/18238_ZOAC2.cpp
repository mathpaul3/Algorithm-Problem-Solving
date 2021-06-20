#include <iostream>

int main()
{
	char str[110] = {
		0,
	};
	int sum = 0, i = 0, num1, num2, temp;
	fgets(str, 105, stdin);
	temp = (str[i] + 26 - 65) % 26;
	sum += temp < 26 - temp ? temp : 26 - temp;
	while (str[i])
	{
		num1 = (int)str[i++];
		if ((int)str[i] == 10)
			break;
		num2 = (int)str[i];
		temp = (num1 + 26 - num2) % 26;
		sum += temp < 26 - temp ? temp : 26 - temp;
	}
	printf("%d", sum);
}
