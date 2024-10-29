# src/CE207-midterm-lib/CMakeLists.txt
set(LIBNAME CE207-midterm-lib)

message(STATUS "[${LIBNAME}] Module Processing...")

# Kütüphane başlık ve kaynak dosyalarını tanımla
file(GLOB LIB_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/hello.h")
file(GLOB LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/hello.c")

# Dosyaları gruplandır
source_group("Header Files" FILES ${LIB_HEADERS})
source_group("Source Files" FILES ${LIB_SOURCES})

# Static kütüphane olarak tanımla
add_library(${LIBNAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})

# Include yolunu ayarla
target_include_directories(${LIBNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Kütüphaneyi hedef klasörlere kur
install(TARGETS ${LIBNAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin )

# Başlık dosyasını include klasörüne kopyala
install(FILES ${LIB_HEADERS}
        DESTINATION include)

message(STATUS "[${LIBNAME}] Added library target: ${LIBNAME}")
