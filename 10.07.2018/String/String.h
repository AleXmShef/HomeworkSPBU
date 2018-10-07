class String{
    public:
        String(const char* str);
        String& operator+(String& str);
        int GetLenght();
        char GetCharByID(int i);
        void PrintString();
    protected:
        const char* mpStr = nullptr;
        int mLenght = 0;
};
