// test.cpp
#include "pch.h"
#include "gtest/gtest.h"

extern "C" {
#include "hello.h"
}

// Standart ��kt�y� yakalamak i�in gerekli
#include <string>

// Test 1: ��kt�n�n "Hello, World!" oldu�unu kontrol et
TEST(HelloTest, PrintHelloExact) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, World!\n");
}

// Test 2: ��kt�n�n bo� olmad���n� kontrol et
TEST(HelloTest, PrintHelloNotEmpty) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Test 3: ��kt�n�n "Hello" kelimesini i�erdi�ini kontrol et
TEST(HelloTest, PrintHelloContainsHello) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Hello"), std::string::npos);
}

// Test 4: ��kt�n�n "World" kelimesini i�erdi�ini kontrol et
TEST(HelloTest, PrintHelloContainsWorld) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("World"), std::string::npos);
}

// Test 5: ��kt�n�n beklenenden uzun olmad���n� kontrol et
TEST(HelloTest, PrintHelloLength) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_LE(output.length(), 20); // ��kt�n�n en fazla 20 karakter olmas� bekleniyor
}

//int main(int argc, char** argv) { // buray� silebilirsiniz
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
