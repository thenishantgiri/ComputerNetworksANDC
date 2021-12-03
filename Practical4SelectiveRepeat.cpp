#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TOT_FRAMES 500
#define FRAMES_SEND 10
using namespace std;

class sel_repeat
{
private:
    int fr_send_at_instance;
    int arr[TOT_FRAMES];
    int send[FRAMES_SEND];
    int rcvd[FRAMES_SEND];
    char rcvd_ack[FRAMES_SEND];
    int sw;
    int rw;

public:
    void input();
    void sender(int);
    void receiver(int);
};

void sel_repeat::input()
{
    int n;
    int m;
    int i;
    cout << "\nEnter the no. of bits for the sequence no. : ";
    cin >> n;
    m = pow(2, n);
    int t = 0;
    fr_send_at_instance = (m / 2);

    for (i = 0; i < TOT_FRAMES; i++)
    {
        arr[i] = t;
        t = (t + 1) % m;
    }

    for (i = 0; i < fr_send_at_instance; i++)
    {
        send[i] = arr[i];
        rcvd[i] = arr[i];
        rcvd_ack[i] = 'n';
    }

    rw = sw = fr_send_at_instance;
    sender(m);
}

void sel_repeat::sender(int m)
{
    for (int i = 0; i < fr_send_at_instance; i++)
    {
        if (rcvd_ack[i] == 'n')
            cout << "SENDER: Frame " << send[i] << " is sent.\n";
    }
    receiver(m);
}

void sel_repeat::receiver(int m)
{
    time_t t;
    int f, j, f1, a1;
    char ch;
    srand((unsigned)time(&t));
    for (int i = 0; i < fr_send_at_instance; i++)
    {
        if (rcvd_ack[i] == 'n')
        {
            f = rand() % 10;

            if (f != 5)
            {
                for (int j = 0; j < fr_send_at_instance; j++)
                    if (rcvd[j] == send[i])
                    {
                        cout << "\nRECIEVER: Frame " << rcvd[j] << " Recieved correctly.\n";
                        rcvd[j] = arr[rw];
                        rw = (rw + 1) % m;
                        break;
                    }
                int j;
                if (j == fr_send_at_instance)
                    cout << "\nRECIEVER: Duplicate Frame " << send[i] << "discarded.\n";

                a1 = rand() % 5;

                if (a1 == 3)
                {
                    cout << "(Acknowledgement " << send[i] << " lost!)\n";
                    cout << "(Sender Timeouts-->Resend the frame...)\n";
                    rcvd_ack[i] = 'n';
                }
                else
                {
                    cout << "(Acknowledgement " << send[i] << " Recieved!!)\n";
                    rcvd_ack[i] = 'p';
                }
            }
            else
            {
                int ld = rand() % 2;

                if (ld == 0)
                {
                    cout << "\n Receiver Side: Frame " << send[i] << " is damaged!!\n";
                    cout << "\n Receiver Side: Negative Acknowledgement " << send[i] << " sent.\n";
                }
                else
                {
                    cout << "\n@Frame Receiver Side: " << send[i] << " is lost!\n";
                    cout << "\n(Sender Timeout-------->Please Resend the Frame...)\n";
                }
                rcvd_ack[i] = 'n';
            }
        }
    }

    for (int j = 0; j < fr_send_at_instance; j++)
    {
        if (rcvd_ack[j] == 'n')
            break;
    }

    int i = 0;
    for (int k = j; k < fr_send_at_instance; k++)
    {
        send[i] = send[k];
        if (rcvd_ack[k] == 'n')
            rcvd_ack[i] = 'n';
        else
            rcvd_ack[i] = 'p';
        i++;
    }

    if (i != fr_send_at_instance)
    {
        for (int k = i; k < fr_send_at_instance; k++)
        {
            send[k] = arr[sw];
            sw = (sw + 1) % m;
            rcvd_ack[k] = 'n';
        }
    }

    cout << "\nDo You Want to Continue? Enter Y/N: ";
    cin >> ch;
    cout << "\n";

    if (ch == 'y' || ch == 'Y')
        sender(m);
    else
        exit(0);
}

int main()
{
    sel_repeat sr;
    sr.input();
}
