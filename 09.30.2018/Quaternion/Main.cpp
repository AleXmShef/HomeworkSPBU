#include "Quaternion.h"

int main() {
    Vector* Vec1 = new Vector(2, 5, 3);
    Vector* Vec2 = new Vector(3, 2, 9);
    Quaternion* Q1 = new Quaternion(Vec1, 25);
    Quaternion* Q2 = new Quaternion(Vec2, 5);
    Quaternion Q3 = (*Q1)*(*Q2);
    Q1->PrinQuaternion();
    Q2->PrinQuaternion();
    Q3.PrinQuaternion();



    system("pause");
    return 0;
}
