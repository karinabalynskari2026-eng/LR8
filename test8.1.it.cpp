// test8.1.it.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <string>

#define main program_main   // щоб main() з лабораторної не конфліктував з main() doctest
#include "../lab_08.1.it.cpp"
#undef main

TEST_CASE("Exists")
{
    char s1[] = "no";
    char s2[] = "on";
    char s3[] = "snow";
    char s4[] = "hello";
    char s5[] = "";
    char s6[] = "n";
    char s7[] = "NO";
    char s8[] = "nxo";

    CHECK(Exists(s1) == true);    // "no"
    CHECK(Exists(s2) == true);    // "on"
    CHECK(Exists(s3) == true);    // "no" усередині слова
    CHECK(Exists(s4) == false);   // немає пари
    CHECK(Exists(s5) == false);   // порожній рядок
    CHECK(Exists(s6) == false);   // один символ
    CHECK(Exists(s7) == false);   // інший регістр
    CHECK(Exists(s8) == false);   // букви не сусідні
}

TEST_CASE("Change")
{
    char str[151];

    strcpy(str, "no");
    char* res = Change(str);
    CHECK(std::string(res) == "***");   // результат функції
    CHECK(std::string(str) == "***");   // вихідний параметр

    strcpy(str, "on");
    CHECK(std::string(Change(str)) == "on");            // "on" не замінюється

    strcpy(str, "snow");
    CHECK(std::string(Change(str)) == "s***w");

    strcpy(str, "nonono on");
    CHECK(std::string(Change(str)) == "********* on");

    strcpy(str, "hello");
    CHECK(std::string(Change(str)) == "hello");         // немає пар

    strcpy(str, "");
    CHECK(std::string(Change(str)) == "");              // порожній рядок

    strcpy(str, "n");
    CHECK(std::string(Change(str)) == "n");             // один символ

    strcpy(str, "NO");
    CHECK(std::string(Change(str)) == "NO");            // інший регістр

    strcpy(str, "nnoo");
    CHECK(std::string(Change(str)) == "n***o");

    strcpy(str, "ono");
    CHECK(std::string(Change(str)) == "o***");
}