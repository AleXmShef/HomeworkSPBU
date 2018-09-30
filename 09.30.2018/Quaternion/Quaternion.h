#include <iostream>
#include "Vector.h"

class Quaternion{
public:
    Quaternion(Vector*, float);
    
    float GetAngle();
    Vector* GetVector();

    Quaternion operator* (Quaternion&);
    Quaternion operator+ (Quaternion&);


protected:
    Vector* mpVec = nullptr;
    float mAngle = 0;
};
