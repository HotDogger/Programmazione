#include <iostream>
#include <fstream>

using namespace std;

void hanoi(int disk, int mossa, int &passi, int a, int c, int b, ostream &output) // start-end-free
{
    if(disk == 1)
    {
        passi ++;
        if(mossa == passi)
        {
            cout << "Muovo il disco " << disk << " da " << a << " fino a " << c << endl;
            output << a << " " << c << endl;
        }
    }
    else
    {
        hanoi(disk-1, mossa, passi, a, b, c, output);
        passi++;
        if(mossa == passi)
        {
            cout << "Muovo il disco " << disk << " da " << a << " fino a " << c << endl;
            output << a << " " << c << endl;
        }
        hanoi(disk-1, mossa, passi, b, c, a, output);
    }
}

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int a = 100;
    while(a > 0)
    {
        int numdisk;
        int mossa;
        int passi = 0;
        input >> numdisk;
        input >> mossa;
        hanoi(numdisk, mossa, passi, 1, 3, 2, output);
        cout << "Risolto in: " << passi << endl;
        a--;
    }
    return 0;
}
