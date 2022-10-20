#include <bits/stdc++.h>
using namespace std;
long long int sizeN = 0;

void binary(int x, vector<int>&arr)
{
    int i, p = x, temp;
    int carry = 1;
    vector<int>one, two;

    for (i = 0; i < sizeN; i++)
        arr.push_back(0);

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
                one.push_back(0);
            }
            else if (arr[i] == 0)
            {
                one.push_back(1);
            }
        }

        for (int i = sizeN - 1; i >= 0; i--)
        {
            if (one[i] == 1 && carry == 1)
            {
                two.push_back(0);
            }
            else if (one[i] == 0 && carry == 1)
            {
                two.push_back(1);
                carry = 0;
            }
            else
            {
                two.push_back(one[i]);
            }
        }
        reverse(two.begin(), two.end());
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

void addOne(vector<int>&arr, int N)
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

void add(vector<int>&a, vector<int>&b)
{
    int x, i, c = 0, y;   
    for (i = sizeN - 1; i >= 0; i--)
    {
        x = a[i];
        y = b[i];
        a[i] = (c ^ x ^ y);
        if (((c == 1) && (x == 1)) || ((x == 1) && (b[i] == 1)) || ((b[i] == 1) && (c == 1)))
            c = 1;
        else
            c = 0;
    }
}

void rshift(int x, vector<int>&array)
{
    int i;
    for (i = sizeN; i > 0; i--)
        array[i] = array[i - 1];

    array[0] = x;
}

int main()
{
    int i, j, a, b;
    vector<int> BR, QR, temp1, ans, AC;
    int q = 0, y, SC;

    cout << "\n----------------------------------------------------\n";
    cout << "\nEnter the value of Multiplicand i.e.BR : ";
    cin >> a;
    cout << "\nEnter the value of Multiplier i.e.QR : ";
    cin >> b;

    cout << "\n---------------------------------------------------\n";
    
    int aBits = (int)log2(abs(a)) + 1;
    int bBits = (int)log2(abs(b)) + 1;
    sizeN = max(aBits,bBits) + 1;

    for (i = 0; i < sizeN; i++)
        AC.push_back(0);

    binary(a, BR);
    binary(b, QR);
    SC = sizeN;

    cout << "\n\n\nComment\t\t\tAC\t\tQR\t\tQ(n+1)\t\tSC\t" << endl;
    cout << "-------------------------------------------------------------------------------------------";
    cout << "\nInitial\t\t\t";
    for (int i = 0; i < sizeN; i++)
        cout << AC[i];

    cout << "\t\t";
    for (int i = 0; i < sizeN; i++)
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
            for (int i = 0; i < sizeN; i++)
                cout << AC[i];

            cout << "\t\t";
            for (int i = 0; i < sizeN; i++)
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
        else if ((QR[sizeN - 1] == 1) && (q == 0))
        {
            temp1.clear();
            cout << "\nAC=AC+(~BR+1)\t\t";
            for (int i = 0; i < sizeN; i++)
                temp1.push_back(1 - BR[i]);

            addOne(temp1, sizeN);
            add(AC, temp1);

            for (int i = 0; i < sizeN; i++)
                cout << AC[i];

            cout << "\t\t";
            for (int i = 0; i < sizeN; i++)
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
        ans.push_back(AC[i]);

    for (int i = 0; i < sizeN; i++)
        ans.push_back(QR[i]);

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
