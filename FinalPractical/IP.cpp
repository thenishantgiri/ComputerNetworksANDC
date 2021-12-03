/*
Write the program IP addressing by taking the
IP address as input and print the corresponding
class, Net –ID and Host-ID.
*/

#include <iostream>

using namespace std;

int main()
{

    int arr[4];
    cout << "Please enter the IP Address\n";
    for (int i = 0; i < 4; i++)
        cin >> arr[i];

    cout << "\nYou Have Entered\n";
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i];
        if (i < 3)
        {
            cout << ".";
        }
    }
    cout << endl;

    cout << "\nDetermining Class\n";

    if ((arr[0] > 0) && (arr[0] <= 127))
    {
        cout << "class A\n";

        cout << "\n\nNet-ID\n";
        for (int i = 0; i < 3; i++)
        {
            cout << arr[i];
            if (i < 2)
                cout << ".";
        }
        cout << "\n\nHost-ID\n";
        cout << arr[3];
    }

    if ((arr[0] > 127) && (arr[0] <= 191))
    {
        cout << "class B\n";

        cout << "\n\nNet-ID\n";
        for (int i = 0; i < 2; i++)
            cout << arr[i] << ".";

        cout << "\n\nHost-ID\n";
        cout << arr[2] << "." << arr[3];

        cout << endl;
    }

    if ((arr[0] > 191) && (arr[0] <= 223))
    {
        cout << "class C\n";

        cout << "\n\nNet-ID\n";
        for (int i = 0; i < 3; i++)
            cout << arr[i] << ".";

        cout << "\n\nHost-ID\n";
        cout << arr[3];

        cout << endl;
    }

    if ((arr[0] > 223) && (arr[0] <= 239))
    {
        cout << "class D\n";
        cout << "No Net-ID And Host-ID\n";
    }

    if ((arr[0] > 239) && (arr[0] <= 255))
    {
        cout << "class E\n";

        cout << "No Net-ID And Host-ID\n";
    }
}