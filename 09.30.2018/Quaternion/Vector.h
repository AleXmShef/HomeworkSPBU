class Vector{
public:
    Vector(float, float, float);
    float x;
    float y;
    float z;
    float Lenght;
    Vector operator* (Vector&);
    Vector operator* (float);
    Vector operator+ (Vector&);
    float ScalarMult (Vector&);
    void PrintVec();

};
