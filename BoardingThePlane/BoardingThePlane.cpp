// BoardingThePlane.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int number_of_rows = 0;
    cin >> number_of_rows;
    string *rows = new string[number_of_rows];

    for (int x = 0; x < number_of_rows; x++)
    {
        cin >> rows[x];
    }

    int number_of_groups = 0;
    cin >> number_of_groups;
    int number_of_persons = 0;
    string side;
    string position;

    for (int y = 1; y <= number_of_groups; y++)
    {
        cin >> number_of_persons;
        cin >> side;
        cin >> position;
        bool status_of_placing = true;

        for (int z = 0; z < number_of_rows; z++)
        {
            status_of_placing = true;
            int temp_start_position = 0;
            int temp_end_position = 6;

            if (side == "left" && position == "window")
            {
                temp_end_position = temp_start_position + number_of_persons - 1;
            }

            if (side == "left" && position == "aisle")
            {
                temp_start_position = 2 - number_of_persons + 1;
                temp_end_position = 2;
            }

            if (side == "right" && position == "window")
            {
                temp_start_position = temp_end_position - number_of_persons + 1;
            }

            if (side == "right" && position == "aisle")
            {
                temp_start_position = 4;
                temp_end_position = 4 + number_of_persons - 1;
            }

            for (int t = temp_start_position; t <= temp_end_position; t++)
            {
                if (rows[z][t] != '.')
                {
                    status_of_placing = false;
                    break;
                }
            }

            if (status_of_placing == true)
            {
                cout << "Passengers can take seats:";
                char place;
                string temp_row = rows[z];
                for (int t = temp_start_position; t <= temp_end_position; t++)
                {
                    switch (t)
                    {
                    case 0:
                        place = 'A';
                        break;
                    case 1:
                        place = 'B';
                        break;
                    case 2:
                        place = 'C';
                        break;
                    case 4:
                        place = 'D';
                        break;
                    case 5:
                        place = 'E';
                        break;
                    default:
                        place = 'F';
                        break;
                    }

                    cout << " " << z + 1 << place;
                    temp_row[t] = 'X';
                    rows[z][t] = '#';
                }

                cout << "\n";

                for (int i = 0; i < number_of_rows; i++)
                {
                    if (i == z)
                    {
                        cout << temp_row;
                        cout << "\n";
                    }
                    else
                    {
                        cout << rows[i];
                        cout << "\n";
                    }
                }

                break;
            }
        }
            if (status_of_placing == false)
            {
            cout << "Cannot fulfill passengers requirements";
            cout << "\n";
            }
    }
}
