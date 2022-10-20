#include <bits/stdc++.h>
using namespace std;
int sizeN = 0;

int get(int a)
{
    if (a == 1)
    {
        do
        {
            cout << "\nEnter the value of Multiplicand i.e.BR : ";
            cin >> a;
        } while (abs(a) > 256);
    }
    else
    {
        do
        {
            cout << "\nEnter the value of Multiplier i.e.QR : ";
            cin >> a;
        } while (abs(a) > 256);
    }
    return (a);
}
void arrayCreation(int a, int b, int *BR, int *QR)
{
    a = abs(a);
    b = abs(b);

    if (a <= 3 && b <= 3)
    {
        sizeN = 3;
        BR = new int[sizeN];
        QR = new int[sizeN];
    }
    else if (a <= 7 && b <= 7)
    {
        sizeN = 4;
        BR = new int[sizeN];
        QR = new int[sizeN];
    }
    else if (a <= 15 && b <= 15)
    {
        sizeN = 5;
        BR = new int[sizeN];
        QR = new int[sizeN];
    }
    else if (a <= 31 && b <= 31)
    {
        sizeN = 6;
        BR = new int[sizeN];
        QR = new int[sizeN];
    }
    else if (a <= 63 && b <= 63)
    {
        sizeN = 7;
        BR = new int[sizeN];
        QR = new int[sizeN];
    }
    else if (a <= 127 && b <= 127)
    {
        sizeN = 8;
        BR = new int[sizeN];
        QR = new int[sizeN];
    }
    else if (a <= 255 && b <= 255)
    {
        sizeN = 9;
        BR = new int[sizeN];
        QR = new int[sizeN];
    }
}

void binary(int x, int *arr)
{
    int i, p = x, temp;
    int one[50], two[50], carry = 1;
    for (i = 0; i < sizeN; i++)
        arr[i] = 0;

    if (x < 0)
        x = x * -1;

    i = sizeN - 1;
    do
    {
        arr[i] = x % 2;
        x = x / 2;
        i--;
    } while (x != 0);

    if (p < 0)
    {
        for (int i = 0; i < sizeN; i++)
        {
            if (arr[i] == 1)
            {
                one[i] = 0;
            }
            else if (arr[i] == 0)
            {
                one[i] = 1;
            }
        }

        for (int i = sizeN - 1; i >= 0; i--)
        {
            if (one[i] == 1 && carry == 1)
            {
                two[i] = 0;
            }
            else if (one[i] == 0 && carry == 1)
            {
                two[i] = 1;
                carry = 0;
            }
            else
            {
                two[i] = one[i];
            }
        }
        for (int i = 0; i < sizeN; i++)
        {
            temp = arr[i];
            arr[i] = two[i];
            two[i] = temp;
        }
    }
    cout << "\nThe Binary Equvalent of " << p << " is : ";
    for (i = 0; i < sizeN; i++)
        cout << arr[i];
}

void addOne(int *arr, int N)
{
    int carry = 1;
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i] == 1 && carry == 1)
        {
            arr[i] = 0;
        }
        else if (arr[i] == 0 && carry == 1)
        {
            arr[i] = 1;
            carry = 0;
        }
        else if (arr[i] == 1 && carry == 0)
        {
            arr[i] = 1;
        }
        else if (arr[i] == 0 && carry == 0)
        {
            arr[i] = 0;
        }
    }
}

void add(int *a, int *b)
{
    int x, i, c = 0, y;
    for (i = sizeN - 1; i >= 0; i--)
    {
        x = a[i];
        y = b[i];
        a[i] = c ^ x ^ y;
        if (((c == 1) && (x == 1)) || ((x == 1) && (b[i] == 1)) || ((b[i] == 1) && (c == 1)))
            c = 1;
        else
            c = 0;
    }
}

void rshift(int x, int *array)
{
    int i;
    for (i = sizeN; i > 0; i--)
        array[i] = array[i - 1];

    array[0] = x;
}



int main()
{
    int i, j, a, b;
    int BR[10], QR[10], AC[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, temp1[10], ans[20];
    int q = 0, y, SC;

    cout << "\nNote : The input must be under 250 only !! " << endl;
    cout << "\n----------------------------------------------------\n";
    a = get(1);
    b = get(0);
    cout << "\n---------------------------------------------------\n";
    arrayCreation(a, b, BR, QR);
    binary(a, BR);
    binary(b, QR);
    SC = sizeN;

    cout << "\n\n\nComment\t\t\tAC\t\tQR\t\tQ(n+1)\t\tSC\t" << endl;
    cout << "-------------------------------------------------------------------------------------------";
    cout << "\nInitial\t\t\t";
    for (i = 0; i < sizeN; i++)
        cout << AC[i];

    cout << "\t\t";
    for (i = 0; i < sizeN; i++)
        cout << QR[i];

    cout << "\t\t";
    cout << q;

    cout << "\t\t";
    cout << SC;

    while (SC > 0)
    {
        if ((QR[sizeN - 1] == 0) && (q == 1))
        {
            cout << "\nAC=AC+BR\t\t";
            add(AC, BR);
            for (i = 0; i < sizeN; i++)
                cout << AC[i];

            cout << "\t\t";
            for (i = 0; i < sizeN; i++)
                cout << QR[i];

            cout << "\t\t" << q;
            cout << "\t\t" << SC;

            cout << "\nShift-Right\t\t";
            y = AC[sizeN - 1];
            q = QR[sizeN - 1];
            rshift(AC[0], AC);
            rshift(y, QR);

            for (i = 0; i < sizeN; i++)
                cout << AC[i];

            cout << "\t\t";
            for (i = 0; i < sizeN; i++)
                cout << QR[i];

            cout << "\t\t" << q;
            SC = SC - 1;
            cout << "\t\t" << SC;
        }
        else if ((QR[sizeN - 1] == 1) && (q == 0))
        {

            cout << "\nAC=AC+(~BR+1)\t\t";
            for (i = 0; i < sizeN; i++)
                temp1[i] = 1 - BR[i];

            addOne(temp1, sizeN);
            add(AC, temp1);

            for (i = 0; i < sizeN; i++)
                cout << AC[i];

            cout << "\t\t";
            for (i = 0; i < sizeN; i++)
                cout << QR[i];

            cout << "\t\t" << q;
            cout << "\t\t" << SC;

            cout << "\nShift-Right\t\t";
            y = AC[sizeN - 1];
            q = QR[sizeN - 1];
            rshift(AC[0], AC);
            rshift(y, QR);

            for (int i = 0; i < sizeN; i++)
                cout << AC[i];

            cout << "\t\t";
            for (int i = 0; i < sizeN; i++)
                cout << QR[i];

            cout << "\t\t" << q;
            SC = SC - 1;
            cout << "\t\t" << SC;
        }
        else if (((QR[sizeN - 1] == 0) && (q == 0)) || ((QR[sizeN - 1] == 1) && (q == 1)))
        {
            cout << "\nShift-Right\t\t";
            y = AC[sizeN - 1];
            q = QR[sizeN - 1];
            rshift(AC[0], AC);
            rshift(y, QR);

            for (i = 0; i < sizeN; i++)
                cout << AC[i];

            cout << "\t\t";
            for (i = 0; i < sizeN; i++)
                cout << QR[i];

            cout << "\t\t" << q;

            SC = SC - 1;
            cout << "\t\t" << SC;
        }
    }
    cout << "\n\n--------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < sizeN; i++)
        ans[i] = AC[i];

    for (int i = 0; i < sizeN; i++)
        ans[i + sizeN] = QR[i];

    if (((a < 0) && (b > 0)) || ((a > 0) && (b < 0)))
    {
        cout << "\nThe answer in 2's Compliment is  : ";
        for (int i = 0; i < sizeN * 2; i++)
            cout << ans[i];

        cout << "\nThe answer in decimal is : " << (a * b) << endl;

        for (i = 0; i < sizeN * 2; i++)
            ans[i] = 1 - ans[i];

        addOne(ans, (sizeN * 2));
    }
    cout << "\nThe answer in binary is  : ";
    for (int i = 0; i < sizeN * 2; i++)
        cout << ans[i];

    cout << "\nThe answer in decimal is : " << abs(a * b) << endl;
    cout << "\n--------------------------------------------------------------------------------------------\n";
    return 0;
}
