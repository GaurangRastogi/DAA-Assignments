#include <bits/stdc++.h>
using namespace std;

int nextPowerOf2(int num)
{
   return pow(2, int(ceil(log2(num))));
}

void display(vector<vector<int>> &matrix, int m, int n)
{

    cout << "\n---------Result of multiplication---------\n\n";
    for (int i = 0; i < m; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    return;
}

void func(vector<vector<int>> &one, vector<vector<int>> &two, vector<vector<int>> &three, int size, int flag)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            three[i][j] = (one[i][j] + ((flag)*two[i][j]));
        }
    }
    return;
}
void utility(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{

    // Base Case
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // If not the base Case
    int newSize = size / 2;

    vector<int> temp(newSize);
    vector<vector<int>> a(newSize, temp), b(newSize, temp), c(newSize, temp), d(newSize, temp), e(newSize, temp), f(newSize, temp), g(newSize, temp), h(newSize, temp), c11(newSize, temp), c12(newSize, temp), c21(newSize, temp), c22(newSize, temp), p1(newSize, temp), p2(newSize, temp), p3(newSize, temp), p4(newSize, temp), p5(newSize, temp), p6(newSize, temp), p7(newSize, temp), result1(newSize, temp), result2(newSize, temp);

    // Initializing a,b,c,d,e,f,g,h
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            a[i][j] = A[i][j];
            b[i][j] = A[i][j + newSize];
            c[i][j] = A[i + newSize][j];
            d[i][j] = A[i + newSize][j + newSize];
            e[i][j] = B[i][j];
            f[i][j] = B[i][j + newSize];
            g[i][j] = B[i + newSize][j];
            h[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Finding out values of p1,p2,p3,p4,p5,p6,p7

    // p1=a*(f-h)
    func(f, h, result2, newSize, -1);
    utility(a, result2, p1, newSize);

    // p2=(a+b)*h
    func(a, b, result1, newSize, 1);
    utility(result1, h, p2, newSize);

    // p3=(c+d)*e
    func(c, d, result1, newSize, 1);
    utility(result1, e, p3, newSize);

    // p4=d*(g-e)
    func(g, e, result2, newSize, -1);
    utility(d, result2, p4, newSize);

    // p5=(a+d)*(e+h)
    func(a, d, result1, newSize, 1); // a+d
    func(e, h, result2, newSize, 1); // e+h
    utility(result1, result2, p5, newSize);

    // p6=(b-d)*(g+h)
    func(b, d, result1, newSize, -1);
    func(g, h, result2, newSize, 1);
    utility(result1, result2, p6, newSize);

    // p7=(a-c)*(e+f)
    func(a, c, result1, newSize, -1);
    func(e, f, result2, newSize, 1);
    utility(result1, result2, p7, newSize);

    // Calculating c11,c12,c21,c22

    // c11=(p4+p5)+(p6-p2)
    func(p4, p5, result1, newSize, 1);
    func(p6, p2, result2, newSize, -1);
    func(result1, result2, c11, newSize, 1);

    // c12=p1+p2
    func(p1, p2, c12, newSize, 1);

    // c21=p3+p4
    func(p3, p4, c21, newSize, 1);

    // c22=(p1-p3)+(p5-p7)
    func(p1, p3, result1, newSize, -1);
    func(p5, p7, result2, newSize, -1);
    func(result1, result2, c22, newSize, 1);

    // Assigning c11,c12,c21,c22 to C
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = c11[i][j];
            C[i][j+ newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }

    return;
}

void strassen_algorithm(vector<vector<int>> &A, int m, int n, vector<vector<int>> &B, int x, int y)
{

    int mx = max({m, n, x, y});

    int dim = nextPowerOf2(mx);

    vector<int> temp(dim);

    vector<vector<int>> Aa(dim, temp), Bb(dim, temp), Cc(dim, temp);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }

    utility(Aa, Bb, Cc, dim);

    vector<vector<int>> C(m, vector<int>(y));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < y; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }

    display(C, m, y);
    return;
}

int main()
{

    cout << "\n\n------------Matrix Chain Multiplication------------\n\n";

    int m, n, x, y;
    cout << "Enter the first matrix A(m,n) dimension: ";
    cin >> m >> n;

    cout << "\nEnter the second matrix B(x,y) dimension: ";
    cin >> x >> y;

    vector<vector<int>> A(m, vector<int>(n)), B(x, vector<int>(y));

    cout << "\n\nEnter the value of matrix A:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "\n\nEnter the value of matrix B:\n";
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> B[i][j];
        }
    }

    if (n == x)
    {
        strassen_algorithm(A, m, n, B, x, y);
    }
    else
    {
        cout << "\nThe given matrices can not be multiplied\n\n";
    }

    return 0;
}