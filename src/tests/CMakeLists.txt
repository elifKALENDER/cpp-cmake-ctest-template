# src/tests/CE207-midterm-tests/CMakeLists.txt
set(TESTNAME CE207-midterm-tests)

message(STATUS "[${TESTNAME}] Module Processing...")

# Test kaynak dosyalarını tanımla
file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/HelloTest.cpp")

# GoogleTest'i bul veya ekle (GoogleTest CMake modülünün bulunduğunu varsayıyoruz)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test yürütülebilir dosyasını oluştur
add_executable(${TESTNAME} ${TEST_SOURCES})

# CE207-midterm-lib ve GoogleTest ile bağlantı kur
target_link_libraries(${TESTNAME} PRIVATE CE207-midterm-lib GTest::GTest GTest::Main)

# Test hedefini çalıştırılabilir hale getir
enable_testing()
add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})

message(STATUS "[${TESTNAME}] Added Test target: ${TESTNAME}")
