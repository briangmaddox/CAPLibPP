cmake_minimum_required(VERSION 3.10)

if(${CMAKE_VERSION} VERSION_LESS 3.10)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(CAPLibpp VERSION 0.9
                 DESCRIPTION "C++ Library to parse NOAA CAP Alerts and ATOM RSS Feed"
                 LANGUAGES CXX)

find_package(Boost REQUIRED)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
ELSE(Boost_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the Boost library and header files.")
endif(Boost_FOUND)

find_package(CURL REQUIRED)
IF (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
ELSE(CURL_FOUND)
      MESSAGE(FATAL_ERROR "Could not find the CURL library and header files.")
ENDIF(CURL_FOUND)

include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)
IF (CURLPP_FOUND)
    include_directories(${CURLPP_INCLUDE_DIR})
ELSE(CURLPP_FOUND)
      MESSAGE(FATAL_ERROR "Could not find the CURLPP library and header files.")
ENDIF(CURLPP_FOUND)

find_package(OpenSSL REQUIRED)
IF (OPENSSL_FOUND)
    include_directories(${OPENSSL_INCLUDE_DIR})
ELSE(OPENSSL_FOUND)
      MESSAGE(FATAL_ERROR "Could not find the OpenSSL library and header files.")
ENDIF(OPENSSL_FOUND)


add_library(CAPLibpp STATIC src/CAPAreaObject.cpp        include/CAPLibpp/CAPAreaObject.h
                            src/CAPEventCodeObject.cpp   include/CAPLibpp/CAPEventCodeObject.h
                            src/CAPGeocodeObject.cpp     include/CAPLibpp/CAPGeocodeObject.h
                            src/CAPInfoObject.cpp        include/CAPLibpp/CAPInfoObject.h
                            src/CAPLibEnums.cpp          include/CAPLibpp/CAPLibEnums.h
                            src/CAPParameterObject.cpp   include/CAPLibpp/CAPParameterObject.h
                            src/CAPResourceObject.cpp    include/CAPLibpp/CAPResourceObject.h
                            src/NOAAAtomEventObject.cpp  include/CAPLibpp/NOAAAtomEventObject.h
                            src/NOAACAPAlertObject.cpp   include/CAPLibpp/NOAACAPAlertObject.h)
target_include_directories(CAPLibpp PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(CAPLibpp PUBLIC cxx_std_11)

add_executable(CAPLibpp_test src/main.cpp)
target_compile_features(CAPLibpp_test PUBLIC cxx_std_11)
target_link_libraries( CAPLibpp_test PRIVATE CAPLibpp)
target_link_libraries(CAPLibpp_test PUBLIC ${CURL_LIBRARIES})
target_link_libraries(CAPLibpp_test PUBLIC ${BOOST_LIBRARIES})
target_link_libraries(CAPLibpp_test PUBLIC ${CURLPP_LIBRARIES})
target_link_libraries(CAPLibpp_test PUBLIC ${OPENSSL_LIBRARIES})

