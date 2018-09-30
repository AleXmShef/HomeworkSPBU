#include "Quaternion.h"

Quaternion::Quaternion (Vector* pVec, float pAngle): mpVec(pVec), mAngle(pAngle) {};

float Quaternion::GetAngle() {
    return mAngle;
}

Vector Quaternion::GetVector() {
    return *mpVec;
}

Quaternion Quaternion::operator* (Quaternion& pQ) {
    Vector tVec1 = pQ.GetVector() * mAngle;
    Vector tVec2 = *mpVec * pQ.GetAngle();
    Vector tVec3 = pQ.GetVector() * (*mpVec);
    Vector* tVec4 = new Vector(0, 0, 0);
    *tVec4 = tVec1 + tVec2 + tVec3;
    float tFloat = pQ.GetVector().ScalarMult(*mpVec);
    Quaternion* oQ = new Quaternion(tVec4, mAngle*pQ.GetAngle() - tFloat);
    return *oQ;
}

Quaternion Quaternion::operator+ (Quaternion& pQ) {
    Vector* tVec = new Vector(0, 0, 0);
    *tVec = pQ.GetVector() + (*mpVec);
    Quaternion* oQ = new Quaternion(tVec, mAngle + pQ.GetAngle());
    return *oQ;
}

void Quaternion::PrinQuaternion(){
    std::cout << "((" << mpVec->x << ", " << mpVec->y << ", " << mpVec->z << "), " << mAngle << ")" << std::endl;
}
