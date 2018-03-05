#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

//3D vector class
class Vector3D
{
    int i, j, k;
public:
    Vector3D(int i, int j, int k)
    {
        this->i = i;
        this->j = j;
        this->k = k;
    }

    static string display (Vector3D vec)
    {
        stringstream vectorString;
        vectorString << vec.i << "i + " << vec.j << "j+ " << vec.k << "k\n";

        return vectorString.str();
    }

    static float magnitude (Vector3D one) {
        float ans = one.i * one.i + one.j * one.j + one.k * one.k;
        return sqrt(ans);
    }

     //Angle between Vectors in cosine
    static  float costheta(Vector3D one, Vector3D two) {
        float value = one ^ two;
        value /= (magnitude(one)*magnitude(two));
        return value;
    }

    Vector3D operator +(Vector3D second);
    Vector3D operator -(Vector3D second);

    //Cross product
    Vector3D operator *(Vector3D second);
    //Dot product
    int operator ^(Vector3D second);
};

Vector3D Vector3D::operator+(Vector3D second)
{
    Vector3D temp(0,0,0);
    temp.i = this->i + second.i;
    temp.j = this->j + second.j;
    temp.k = this->k + second.k;
    return temp;
}

Vector3D Vector3D::operator-(Vector3D second)
{
    Vector3D temp(0,0,0);
    temp.i = this->i - second.i;
    temp.j = this->j - second.j;
    temp.k = this->k - second.k;
    return temp;
}

//DOT PRODUCT STYLE ^
int Vector3D::operator ^(Vector3D second) {
    int temp;
    temp = this->i * second.i + this->j * second.j + this->k * second.k;
    return temp;
}

//CROSS PRODUCT STYLE *
Vector3D Vector3D::operator *(Vector3D second) {
    Vector3D temp(0,0,0);
    temp.i = (this->j * second.k) - (this->k * second.j);
    temp.j = (this->k * second.i) - (this->i * second.k);
    temp.k = (this->i * second.j) - (this->j * second.i);
    return temp;
}

int main()
{

    Vector3D obj(2,1,2);
    Vector3D obj2(0,1,0);
    cout<< Vector3D::magnitude(obj)<<endl;
    cout << Vector3D::display(obj);
    cout << Vector3D::display(obj2);

    //Cross Product
    Vector3D vTemp = obj * obj2;

    //Dot Product
    int vTemp2 = obj ^ obj2;
    cout << Vector3D::display(vTemp);
    cout << vTemp2;


    return 0;
}
