#include <iostream>
using namespace std;

int main() {
    int ip[4];
    cout << "Enter the IP Address (use spaces in place of dots): ";
    for (int i = 0; i < 4; i++)
        cin >> ip[i];

    cout << "\nThe Entered IP Address is: " << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3];
    cout << "\nClass of the IP Address: ";
    if (ip[0] >= 0 && ip[0] <= 127)
        cout << "Class A\n";
    else if (ip[0] > 127 && ip[0] <= 191)
        cout << "Class B\n";
    else if (ip[0] > 191 && ip[0] <= 223)
        cout << "Class C\n";
    else if (ip[0] > 223 && ip[0] <= 239)
        cout << "Class D\n";
    else if (ip[0] > 239 && ip[0] <= 255)
        cout << "Class E\n";
    else
        cout << "Invalid IP Address!!\n";

    return 0;
}