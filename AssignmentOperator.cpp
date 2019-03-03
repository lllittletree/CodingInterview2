//
// Created by Mr.Zhao on 2019/3/3.
//
#include "string.h"
#include "stdio.h"

class CMyString{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString();
    void Print();
    CMyString& operator=(const CMyString &str);

private:
    char* m_pData;
};

//CMyString &CMyString::operator=(const CMyString &str) {
//    if(this == &str)
//        return *this;
//    delete []m_pData;
//    m_pData = nullptr;
//    m_pData = new char[strlen(str.m_pData)+1];
//    strcpy(m_pData, str.m_pData);
//    return *this;
//
//}

CMyString &CMyString::operator=(const CMyString &str) {
    if(this != &str)
    {
        CMyString strTemp(str);
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = str.m_pData;
        m_pData = pTemp;
    }
    return *this;
}

CMyString::CMyString(char *pData) {
    if(pData == nullptr){
        m_pData = new char[1];
        m_pData = '\0';
    }
    else
    {
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str) {
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString() {
    delete []m_pData;
}


void CMyString::Print()
{
    printf("%s", m_pData);
}



void Test1()
{
    printf("Test1 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    return 0;
}
