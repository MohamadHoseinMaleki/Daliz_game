#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>


using namespace std;

char arr[17][17] = {
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{'A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','B'} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} ,
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} };

int a[3] = { 8,0,0 }, b[3] = { 8,16,0 };

void print()
{
    cout << "0     1   2   3   4   5   6   7   8   9" << endl;
    cout << "  * * * * * * * * * * * * * * * * * * *" << endl;
    for (int i = 0; i < 17; i++)
    {
        if (i % 2 == 1)
        {
            int q = i / 2 + 1;
            cout << q;
        }
        else
        {
            cout << " ";
        }
        cout << " * ";
        for (int j = 0; j < 17; j++)
        {
            cout << arr[i][j];
            if (arr[i][j] == '_' && arr[i][j + 1] == '_')
            {
                cout << "_";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "*" << endl;
    }
    cout << "9 * * * * * * * * * * * * * * * * * * *" << endl;
}

int move(char p, char q)
{
    int t = 0;
    switch (p)
    {
    case 'a':
        if (q == 'r')
        {
            if ((a[1] == 16 || (arr[a[0]][a[1] + 1] == ' ' && arr[a[0]][a[1] + 2] == ' ')))
            {
                if (a[1] != 16)
                {
                    swap(arr[a[0]][a[1]], arr[a[0]][a[1] + 2]);
                }
                a[1] += 2;
            }
            else if (a[1] <= 12 && arr[a[0]][a[1] + 1] == ' ' && arr[a[0]][a[1] + 2] >= 'A' && arr[a[0]][a[1] + 2] <= 'B' && arr[a[0]][a[1] + 3] == ' ' && arr[a[0]][a[1] + 4] == ' ')
            {
                if (a[1] != 12)
                {
                    swap(arr[a[0]][a[1]], arr[a[0]][a[1] + 4]);
                }
                a[1] += 4;
            }
            else
            {
                t = 1;
            }
        }
        else if (q == 'l')
        {
            if (a[1] == 0)
            {
                t = 1;
            }
            else if (arr[a[0]][a[1] - 1] == ' ' && arr[a[0]][a[1] - 2] == ' ')
            {
                swap(arr[a[0]][a[1]], arr[a[0]][a[1] - 2]);
                a[1] -= 2;
            }
            else if (a[1] >= 4 && arr[a[0]][a[1] - 1] == ' ' && arr[a[0]][a[1] - 2] >= 'A' && arr[a[0]][a[1] - 2] <= 'B' && arr[a[0]][a[1] - 3] == ' ' && arr[a[0]][a[1] - 4] == ' ')
            {
                swap(arr[a[0]][a[1]], arr[a[0]][a[1] - 4]);
                a[1] -= 4;
            }
            else
            {
                t = 1;
            }
        }
        else if (q == 'u')
        {
            if (a[0] == 0)
            {
                t = 1;
            }
            else if (arr[a[0] - 1][a[1]] == ' ' && arr[a[0] - 2][a[1]] == ' ')
            {
                swap(arr[a[0]][a[1]], arr[a[0] - 2][a[1]]);
                a[0] -= 2;
            }
            else if (a[0] >= 4 && arr[a[0] - 1][a[1]] == ' ' && arr[a[0] - 2][a[1]] >= 'A' && arr[a[0] - 2][a[1]] <= 'B' && arr[a[0] - 3][a[1]] == ' ' && arr[a[0] - 4][a[1]] == ' ')
            {
                swap(arr[a[0]][a[1]], arr[a[0] - 4][a[1]]);
                a[0] -= 4;
            }
            else
            {
                t = 1;
            }
        }
        else
        {
            if (a[0] == 16)
            {
                t = 1;
            }
            else if (arr[a[0] + 1][a[1]] == ' ' && arr[a[0] + 2][a[1]] == ' ')
            {
                swap(arr[a[0]][a[1]], arr[a[0] + 2][a[1]]);
                a[0] += 2;
            }
            else if (a[0] >= 4 && arr[a[0] + 1][a[1]] == ' ' && arr[a[0] + 2][a[1]] >= 'A' && arr[a[0] + 2][a[1]] <= 'B' && arr[a[0] + 3][a[1]] == ' ' && arr[a[0] + 4][a[1]] == ' ')
            {
                swap(arr[a[0]][a[1]], arr[a[0] + 4][a[1]]);
                a[0] += 4;
            }
            else
            {
                t = 1;
            }
        }
        break;
    case 'b':
        if (q == 'l')
        {
            if ((b[1] == 0 || (arr[b[0]][b[1] - 1] == ' ' && arr[b[0]][b[1] - 2] == ' ')))
            {
                if (b[1] != 0)
                {
                    swap(arr[b[0]][b[1]], arr[b[0]][b[1] - 2]);
                }
                b[1] -= 2;
            }
            else if (b[1] >= 4 && arr[b[0]][b[1] - 1] == ' ' && arr[b[0]][b[1] - 2] >= 'A' && arr[b[0]][b[1] - 2] <= 'B' && arr[b[0]][b[1] - 3] == ' ' && arr[b[0]][b[1] - 4] == ' ')
            {
                if (b[1] != 4)
                {
                    swap(arr[b[0]][b[1]], arr[b[0]][b[1] - 4]);
                }
                b[1] -= 4;
            }
            else
            {
                t = 1;
            }
        }
        else if (q == 'r')
        {
            if (b[1] == 16)
            {
                t = 1;
            }
            else if (arr[b[0]][b[1] + 1] == ' ' && arr[b[0]][b[1] + 2] == ' ')
            {
                swap(arr[b[0]][b[1]], arr[b[0]][b[1] + 2]);
                b[1] += 2;
            }
            else if (b[1] <= 12 && arr[b[0]][b[1] + 1] == ' ' && arr[b[0]][b[1] + 2] >= 'A' && arr[b[0]][b[1] + 2] <= 'B' && arr[b[0]][b[1] + 3] == ' ' && arr[b[0]][b[1] + 4] == ' ')
            {
                swap(arr[b[0]][b[1]], arr[b[0]][b[1] + 4]);
                b[1] += 4;
            }
            else
            {
                t = 1;
            }
        }
        else if (q == 'u')
        {
            if (b[0] == 0)
            {
                t = 1;
            }
            else if (arr[b[0] - 1][b[1]] == ' ' && arr[b[0] - 2][b[1]] == ' ')
            {
                swap(arr[b[0]][b[1]], arr[b[0] - 2][b[1]]);
                b[0] -= 2;
            }
            else if (b[0] >= 4 && arr[b[0] - 1][b[1]] == ' ' && arr[b[0] - 2][b[1]] >= 'A' && arr[b[0] - 2][b[1]] <= 'B' && arr[b[0] - 3][b[1]] == ' ' && arr[b[0] - 4][b[1]] == ' ')
            {
                swap(arr[b[0]][b[1]], arr[b[0] - 4][b[1]]);
                b[0] -= 4;
            }
            else
            {
                t = 1;
            }
        }
        else    // d
        {
            if (b[0] == 16)
            {
                t = 1;
            }
            else if (arr[b[0] + 1][b[1]] == ' ' && arr[b[0] + 2][b[1]] == ' ')
            {
                swap(arr[b[0]][b[1]], arr[b[0] + 2][b[1]]);
                b[0] += 2;
            }
            else if (b[0] >= 4 && arr[b[0] + 1][b[1]] == ' ' && arr[b[0] + 2][b[1]] >= 'A' && arr[b[0] + 2][b[1]] <= 'B' && arr[b[0] + 3][b[1]] == ' ' && arr[b[0] + 4][b[1]] == ' ')
            {
                swap(arr[b[0]][b[1]], arr[b[0] + 4][b[1]]);
                b[0] += 4;
            }
            else
            {
                t = 1;
            }
        }
        break;
    default:
        t = 1;
        break;
    }
    return t;
}

char check_win()
{
    if (a[1] >= 16 )
    {
        return 'A';
    }
    else if (b[1] <= 0 )
    {
        return 'B';
    }
    return ' ';
}

int set_wall(int x, int y, int p, int q)
{
    int t = 0;
    if (sqrt(pow(x - p, 2) + pow(y - q, 2)) == 2)
    {
        if (arr[x][y] == ' ' && arr[p][q] == ' ')
        {
            if (x - p == 0)
            {
                arr[x][y] = '_';
                arr[x][(y + q) / 2] = '_';
                arr[p][q] = '_';
            }
            else
            {
                arr[x][y] = '|';
                arr[(x + p) / 2][y] = '|';
                arr[p][q] = '|';
            }
        }
        else
        {
            t = 1;
        }
    }
    else
    {
        t = 1;
    }
    return t;
}

void save()
{
    remove("file.txt");
    ofstream File("file.txt", ios::out);
    File << "t" << endl;
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (arr[i][j] == ' ')
            {
                File << "0 ";
            }
            else
            {
                File << arr[i][j] << " ";
            }
        }
        File << endl;
    }
    File << a[0] << " " << a[1] << " " << a[2] << " " << b[0] << " " << b[1] << " " << " " << b[2];
}

void load()
{
    ifstream File("file.txt", ios::in);
    char t;
    File >> t;
    if (t == 't')
    {
        for (int i = 0; i < 17; i++)
        {
            for (int j = 0; j < 17; j++)
            {
                File >> t;
                if (t == '0')
                {
                    arr[i][j] = ' ';
                }
                else
                {
                    arr[i][j] = t;
                }
            }
        }
        File >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
    }
}

int main()
{
	system("color f0");
    int n, x, y, p, q;
    char t;
    //remove("file.txt");
    while (true)
    {
        system("cls");
        //load();
        print();
        cout << "Player A" << endl;
    jump1:
        cout << "[1] Move" << endl;
        cout << "[2] Wall" << endl;
        cout << "Enter a number: ";
        cin >> n;
        if (n == 1)
        {
            cout << "[r] Right" << endl;
            cout << "[l] Left" << endl;
            cout << "[u] Up" << endl;
            cout << "[d] Down" << endl;
        jump2:
            cout << "Enter a character: ";
            cin >> t;
            if (move('a', t))
            {
                goto jump2;
            }
            else
            {
                system("cls");
                print();
            }
        }
        else if (n == 2)
        {
            if (a[2] == 10)
            {
                goto jump1;
            }
        jump3:
            cout << "i1: ";
            cin >> x;
            cout << "j1: ";
            cin >> y;
            cout << "i2: ";
            cin >> p;
            cout << "j2: ";
            cin >> q;
            if (set_wall(x * 2 - 1, y * 2 - 1, p * 2 - 1, q * 2 - 1))
            {
                goto jump3;
            }
            else
            {
                a[2]++;
            }
        }
        else
        {
            goto jump1;
        }
        system("cls");
        print();


        cout << "Player B" << endl;
    jump4:
        cout << "[1] Move" << endl;
        cout << "[2] Wall" << endl;
        cout << "Enter a number: ";
        cin >> n;
        if (n == 1)
        {
            cout << "[r] Right" << endl;
            cout << "[l] Left" << endl;
            cout << "[u] Up" << endl;
            cout << "[d] Down" << endl;
        jump5:
            cout << "Enter a character: ";
            cin >> t;
            if (move('b', t))
            {
                goto jump5;
            }
            else
            {
                system("cls");
                print();
            }
        }
        else if (n == 2)
        {
            if (b[2] == 10)
            {
                goto jump4;
            }
        jump6:
            cout << "i1: ";
            cin >> x;
            cout << "j1: ";
            cin >> y;
            cout << "i2: ";
            cin >> p;
            cout << "j2: ";
            cin >> q;
            if (set_wall(x * 2 - 1, y * 2 - 1, p * 2 - 1, q * 2 - 1))
            {
                goto jump6;
            }
            else
            {
                b[2]++;
            }
        }
        else
        {
            goto jump4;
        }
        save();
        if (check_win() != ' ')
        {
            cout << "Player " << check_win() << " win!" << endl;
            break;
        }
    }
    remove("file.txt");
}

