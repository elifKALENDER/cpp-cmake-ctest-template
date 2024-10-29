# app/CMakeLists.txt
set(ROOT src)
set(APPNAME CE207-midterm-app)

message(STATUS "[${ROOT}/${APPNAME}] Module Processing...")

# Uygulama kaynak dosyalarını tanımla
file(GLOB APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/HelloApp.c")

# Dosyaları gruplandır
source_group("Source Files" FILES ${APP_SOURCES})

# Uygulamayı yürütülebilir olarak tanımla
add_executable(${APPNAME} ${APP_SOURCES})

# Include yolunu ayarla
target_include_directories(${APPNAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../CE207-midterm-lib)

# Uygulamanın kütüphaneyi kullanmasını sağla
target_link_libraries(${APPNAME} PRIVATE CE207-midterm-lib)

# Uygulamayı hedef klasörlere kur
install(TARGETS ${APPNAME}
        RUNTIME DESTINATION bin )

message(STATUS "[${ROOT}/${APPNAME}] Added Executable target: ${APPNAME}")
