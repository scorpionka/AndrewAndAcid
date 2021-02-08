// AndrewAndAcid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int number_of_containers = 0;
	int64_t volume = 1;
	int64_t result = 0;
	int64_t temp = 1;
	cin >> number_of_containers;
	cin >> volume;

	if (number_of_containers == 1)
	{
		cout << 0;
		return 0;
	}

	for (int x = 2; x <= number_of_containers; x++)
	{
		cin >> temp;

		if (temp < volume)
		{
			cout << -1;
			return 0;
		}

		if (temp > volume)
		{
			result = result + temp - volume;
		}

		volume = temp;
	}

	cout << result;
	return 0;
}

