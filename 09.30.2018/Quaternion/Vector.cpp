#include "Vector.h"
#include <math.h>

Vector::Vector (float px, float py, float pz): x(px), y(py), z(pz) {
    Lenght = sqrt(x*x + y*y + z*z);
};

Vector Vector::operator* (Vector pV) {
    Vector* oVec = new Vector(z*pV.y - y*pV.z, x*pV.z - z*pV.x, y*pV.x - x*pV.y);
    return *oVec;
};

Vector Vector::operator* (float n) {
    Vector* oVec = new Vector(x*n, y*n, z*n);
    return *oVec;
};

Vector Vector::operator+ (Vector pV) {
    Vector* oVec = new Vector(x+pV.x, y+pV.y, z+pV.z);
    return *oVec;
}

float Vector::ScalarMult(Vector pV) {
    float oS = x*pV.x + y*pV.y + z*pV.z;
    return oS;
};
