// SatelliteImagery.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int number_of_photos = 0;
    cin >> number_of_photos;
    int **photos = new int* [number_of_photos];

    for (int x = 0; x < number_of_photos; x++)
    {
        photos[x] = new int[5];
        cin >> photos[x][0];
        cin >> photos[x][1];
        cin >> photos[x][2];
        cin >> photos[x][3];
        photos[x][4] = (abs(photos[x][0]) + abs(photos[x][2])) * (abs(photos[x][1]) + abs(photos[x][3]));
    }

    for (int x = 0; x < number_of_photos; x++)
    {
        cout << photos[x][4];
        cout << "\n";
    }


    int sum = 0;

    for (int x = number_of_photos - 1; x > 0; x--)
    {
        for (int y = x - 1; y >= 0; y--)
        {
            int temp_x1 = abs(photos[x][0]);
            int temp_y1 = abs(photos[x][1]);
            int temp_x2 = abs(photos[x][2]);
            int temp_y2 = abs(photos[x][3]);

            if (abs(photos[y][0]) < abs(photos[x][0]))
            {
                temp_x1 = abs(photos[y][0]);
            }

            if (abs(photos[y][1]) < abs(photos[x][1]))
            {
                temp_y1 = abs(photos[y][1]);
            }

            if (abs(photos[y][2]) < abs(photos[x][2]))
            {
                temp_x2 = abs(photos[y][2]);
            }

            if (abs(photos[y][3]) < abs(photos[x][3]))
            {
                temp_y2 = abs(photos[y][3]);
            }

            sum = sum + ((temp_x1 + temp_x2) * (temp_y1 + temp_y2));
            photos[y - 1][4] = photos[y - 1][4] - sum;
        }
    }

    for (int x = 0; x < number_of_photos; x++)
    {
        cout << photos[x][4];
        cout << "\n";
    }
}

