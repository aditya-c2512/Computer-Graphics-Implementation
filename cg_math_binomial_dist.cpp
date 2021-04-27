#include <iostream>
#include <cmath>
using namespace std;

float fact(int x)
{
    float f = 1;
    for(int i = 1; i <= x; i++)
    {
        f = f*i;
    }
    return f;
}

int main()
{
    int N = 0;
    cout << "Enter N :" << endl;
    cin >> N;
    for(int n = 0; n <= N; n++)
    {
        float NCn = fact(N)/(fact(n) * fact(N-n));
        float prob = NCn * powf(0.5,n) * powf(1 - 0.5, N-n);
        cout << n << " " << prob << endl;
    }
}