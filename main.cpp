#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_LEN_NUM = 16;

void test_auto_ptr();
void test_unique_ptr();

//int main() {
//
////    typedef struct {
////        short Sunday = 0;
////        short Monday = 1;
////        short Tuesday = 2;
////        short Wednesday = 3;
////        short Thursday = 4;
////        short Friday = 5;
////        short Saturday = 6;
////    } weekday;
////
////    cout << sizeof(weekday) << endl;
////
////    vector<int> vec = {1, 2, 3, 4};
////    vec.push_back(5);
////    for (int i = 0; i < vec.size(); i++) {
////        cout << vec[i] << endl;
////    }
////    cout << vec.size() << endl;
//
////    char strHelloWorld[11] = {"helloworld"};
////    cout << strlen(strHelloWorld) << endl;
//
//
////    char strHelloWorld1[] = {"hello"};
////    char strHelloWorld2[] = {"world1"};
////    char strHelloWorld3[MAX_LEN_NUM] = {0};
////
////    strcpy(strHelloWorld3, strHelloWorld1);                //  把strHelloWorld1赋值给strHelloWorld3，此时strHelloWorld3为hello
////
//////    strcpy_s(strHelloWorld3, sizeof(strHelloWorld3), strHelloWorld1);                     //  更安全的拷贝，防止字符串内存被冲爆影响后续内存中的逻辑，需要c11支持
////
////    strlcpy(strHelloWorld3, strHelloWorld1, sizeof(strHelloWorld3));        //  使用strlcpy一样可以达到上面strcpy_s的效果
////
////    strncpy(strHelloWorld3, strHelloWorld2, 2);         //  赋值前两个字符，此时strHelloWorld3为wollo
////
////    strcat(strHelloWorld3, strHelloWorld2);                 //  字符串拼接，wolloworld1     
////
////    unsigned int len = sizeof(strHelloWorld3) / sizeof(strHelloWorld3[0]);
////
////    for (unsigned int i = 0; i < len; ++i) {
////        cout << strHelloWorld3[i] << "";
////    }
////    cout << endl;
//
//
//
////    int a = 112;
////    float c = 3.14f;
////    int* d = &a;
////    float* e = &c;
////
////
////    cout << "d = " << d << endl;
////    cout << "e = " << e << endl;
////    cout << "(*d) = " << (*d) << endl;
////    cout << "(*e) = " << (*e) << endl;
////    cout << "(&d) = " << (&d) << endl;
////    cout << "(&e) = " << (&e) << endl;
//
////    ---------------------------------------------------------------------
///**
// * 原始指针 1   array of pointers / a pointer to an array
// * */
////
//////    指针的数组，array of pointers，指一个数组，其内部元素皆为指针，T* t[]
////    int* (a[4]);
////
//////    数组的指针，a pointer to an array，指指向一个数组的指针，T(*t) []
////    int(*b)[4];
////
////    unsigned int c[4] = {0x80000000, 0xFFFFFFFF, 0x00000000, 0x7FFFFFFF};
////    unsigned int* arrPointers[4];
////    unsigned int(*pointerToArray)[4];
////    pointerToArray = &c;
////
////    for (unsigned int i = 0; i < 4; i++) {
////        arrPointers[i] = &(c[i]);
////    }
////
////    cout << "*(arrPointers[0]) = " << *(arrPointers[0]) << endl;            //  *(arrPointers[0]) = 2147483648
////    cout << "(*pointerToArray)[0] = " << (*pointerToArray)[0] << endl;      //  (*pointerToArray)[0] = 2147483648
//
////    ---------------------------------------------------------------------
///**
// * 原始指针 2   const pointer / pointer to const
// * */
//
//    char strHelloWorld[] = {"helloworld"};
//    char const *pStr1 = "helloworld";                   //  看const左侧，修饰的是char，说明pStr1指向的是一个常量，等同于 const char *pStr1 = "helloworld";
//    char* const pStr2 = strHelloWorld;                  //  看const左侧，修饰的是char*，说明pStr2这个指针是常量，不可修改，等同于 const char* pStr2 = "helloworld";
//    char const* const pStr3 = "helloworld";             //  pStr3本身和pStr3指向的都是常量，不可更改
//
//    pStr1 = strHelloWorld;
////    pStr2 = strHelloWorld;        //  pStr2不可改
////    pStr3 = strHelloWorld;        //  pStr3不可改
//
////    关于const修饰的部分：
////    1.看左侧最近的部分；
////    2.如果左侧没有，则看右侧
////    ---------------------------------------------------------------------
///**
// * 原始指针 3   二级指针，指向指针的指针
// * */
//
//    int a = 123;
//    int* b = &a;
//    int** c = &b;
//
//    cout << "*b = " << *b << endl;          //  *b = 123
//    cout << "**c = " << **c << endl;        //  **c = 123
////    ---------------------------------------------------------------------
//
///**
// * 关于野指针
// * */
//
////  未初始化和非法的指针
////    int *aInvalid;
////    *aInvalid = 12;
//
////  NULL指针，表示不指向任何内存地址
////  对于一个指针，如果实现不知道其指向的地址，需将其赋值为pNULL
////  在对一个指针进行间接引用之前，需要先判断这个指针的值是否为NULL：if(pNULL != NULL)
//    int *pNULL = NULL;
//    pNULL = &a;
//    if(pNULL != NULL) {
//        cout << *pNULL << endl;
//    }
//    pNULL = NULL;           //  在指针用完之后将其置为NULL
//
////  野指针出现的情况：
////  1.指针变量没有初始化
////  2.已经释放不用的指针没有置为NULL，如delete和free之后的指针；
////  3.指针操作超越了变量的作用范围，即超越了指针指向的作用域的生命周期
////    ---------------------------------------------------------------------
//
///**
// *  原始指针的基本运算
// * */
//    char ch = 'a';
//    char* cP = &ch;
////    *cp的左右值```
////    *cP为左值，如下表示*cP可以指向内存中'b'的内存地址，单独的'b'无法直接引用，需要赋值给左值才能找到
//    *cP = 'b';
////    *cP为右值，如下*cP表示内存中一块变量的地址，可以这个变量的地址赋值给新的变量ch2
//    char ch2 = *cP;
//    cout << "ch = " << ch << endl;              //  ch = b
//    cout << "ch2 = " << ch2 << endl;            //  ch2 = b
//
////  *cp + 1的左右值
////  *cp + 1为左值，非法
////  *cp + 1为右值，表示取到cP指向的值再加1
//    char ch3 = *cP + 1;
//    cout << "ch3 = " << ch3 << endl;            //  ch3 = c
//
////  *(cP + 1)的左右值
////  *(cP + 1)为左值，表示将cP指向的内存块的下一个byte赋值为'c'，虽然语言上合法，但是是危险操作
//    *(cP + 1) = 'c';
////  *(cP + 1)为右值，表示将cP指向的值加1
//    char ch4 = *(cP + 1);
//    cout << "ch4 = " << ch4 << endl;            //  ch4 = c
//
//    cout << "测试auto_ptr" << endl;
//    test_auto_ptr();
//
//    cout << "测试unique_ptr" << endl;
//    test_unique_ptr();
//
//    return 0;
//}

void test_auto_ptr() {
    auto_ptr<int> pl(new int(10));
    cout << *pl << endl;

    auto_ptr<string> languages[5] = {
            auto_ptr<string>(new string("C")),
            auto_ptr<string>(new string("Java")),
            auto_ptr<string>(new string("C++")),
            auto_ptr<string>(new string("Python")),
                auto_ptr<string>(new string("Rust")),
    };

    auto_ptr<string> pC;
    pC = languages[2];          //  此时cP会剥夺languages[2]对字符串"C++"的指向，language[2]变成一个nullptr
    for (int i = 0; i < 2; ++i) {
        cout << *languages[i] << endl;
    }
}

void test_unique_ptr() {
    auto w = std::make_unique<int>(10);     //  使用auto修饰可以自动判断变量类型
    cout << *(w.get()) << endl;
//    auto w2 = w;          //  被unique_ptr修饰的指针是不能被其他指针夺取的
    auto w2 = std::move(w);     //  使用std::move函数可以实现夺取

    cout << ((nullptr != (w.get())) ? (*(w.get())) : -1) << endl;
    cout << ((nullptr != (w2.get())) ? (*(w2.get())) : -1) << endl;
}
