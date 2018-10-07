#include <iostream>
#include "String.h"

String::String(const char* ptr) {
    mpStr = ptr;
    size_t i = 0;
    while(mpStr[i] != 0) {
        mLenght++;
        i++;
    }
}

String& String::operator+(String& str) {
    char* tStr = new char[this->mLenght + str.GetLenght()];
    for (int i = 0; i < this->mLenght; i++) {
        tStr[i] = this->GetCharByID(i);
    }
    for (int i = this->mLenght; i < this->mLenght + str.GetLenght(); i++) {
        tStr[i] = str.GetCharByID(i - this->mLenght);
    }
    String* oStr = new String(tStr);
    return *oStr;
}

int String::GetLenght() {
    return this->mLenght;
}

char String::GetCharByID(int i) {
    return this->mpStr[i];
}

void String::PrintString() {
    for (int i = 0; i < this->mLenght; i++) {
        std::cout << this->GetCharByID(i);
    }
}
