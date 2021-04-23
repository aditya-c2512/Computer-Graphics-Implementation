#include <cmath>
#include "cg_math_Vec3.cpp"

template<typename T>
class Matrix44
{
    Matrix44() {}

    const T* operator [](uint8_t i) const
    { return m[i]; }
    T* operator [](uint8_t i) const
    { return m[i]; }

    Matrix44 operator *(const Matrix44& rhs) const
    {
        Matrix44 mult;
        for(uint8_t i = 0; i < 4; i++)
        {
            for(uint8_t j = 0; j < 4; j++)
            {
                mult[i][j] = m[i][0]*rhs[0][j] + 
                             m[i][1]*rhs[1][j] + 
                             m[i][2]*rhs[2][j] + 
                             m[i][3]*rhs[3][j];
            }
        }
        return mult;
    }

    template<typename S> 
    void multVecMatrix(const Vec3<S> &src, Vec3<S> &dst) const 
    { 
        dst.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0] + m[3][0]; 
        dst.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] + m[3][1]; 
        dst.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] + m[3][2]; 
        T w = src.x * m[0][3] + src.y * m[1][3] + src.z * m[2][3] + m[3][3]; 

        if (w != 1 && w != 0) 
        { 
            dst.x = x / w; 
            dst.y = y / w; 
            dst.z = z / w; 
        } 
    } 

    T m[4][4] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
};

/*
GENERIC MATRIX MULTIPLICATION
for(uint8_t i = 0; i < 4; i++)
{
    for(uint8_t j = 0; j < 4; j++)
    {
        for(uint8_t k = 0; k < 4; k++)
        {
            mult[i][j] += m[i][k]*rhs[k][j];
        }
    }
}
*/