#include <iostream>
#include <cmath>

using namespace std;

float f(float x)
{
    float val = 2*x*x + x;
    return val;
}

int main()
{
    long long samples = 100000;
    float a = 2.0f, b = 10.0f;
    float S = 0.0f;
    for(long long i = 0; i < samples; i++)
    {
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float x = a + r*(b-a);
        float fx = f(x);
        S += fx * (b-a);
    }
    
    cout << "MC Integration of f(x) from a to b is : " << S/samples << endl;
}