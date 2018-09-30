#include "Quaternion.h"

Quaternion::Quaternion (Vector* pVec, float pAngle): mpVec(pVec), mAngle(pAngle) {};

float Quaternion::GetAngle() {
    return mAngle;
}

Vector* Quaternion::GetVector() {
    return mpVec;
}

Quaternion Quaternion::operator* (Quaternion& pQ) {
    Vector&& tVec = (*pQ.GetVector() * mAngle + (*mpVec) * pQ.GetAngle() + (*mpVec) * (*pQ.GetVector()));
    Quaternion* oQ = new Quaternion(&tVec, mAngle*pQ.GetAngle() - mpVec->ScalarMult(*pQ.GetVector()));
    return *oQ;
}
