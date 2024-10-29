// test.cpp
#include "pch.h"
#include "gtest/gtest.h"

extern "C" {
#include "hello.h"
}

// Standart çýktýyý yakalamak için gerekli
#include <string>

// Test 1: Çýktýnýn "Hello, World!" olduðunu kontrol et
TEST(HelloTest, PrintHelloExact) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello, World!\n");
}

// Test 2: Çýktýnýn boþ olmadýðýný kontrol et
TEST(HelloTest, PrintHelloNotEmpty) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Test 3: Çýktýnýn "Hello" kelimesini içerdiðini kontrol et
TEST(HelloTest, PrintHelloContainsHello) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Hello"), std::string::npos);
}

// Test 4: Çýktýnýn "World" kelimesini içerdiðini kontrol et
TEST(HelloTest, PrintHelloContainsWorld) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("World"), std::string::npos);
}

// Test 5: Çýktýnýn beklenenden uzun olmadýðýný kontrol et
TEST(HelloTest, PrintHelloLength) {
    testing::internal::CaptureStdout();
    print_hello();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_LE(output.length(), 20); // Çýktýnýn en fazla 20 karakter olmasý bekleniyor
}

//int main(int argc, char** argv) { // burayý silebilirsiniz
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
