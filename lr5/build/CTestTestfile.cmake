# CMake generated Testfile for 
# Source directory: C:/Users/Миша/Desktop/LROOP/lr5
# Build directory: C:/Users/Миша/Desktop/LROOP/lr5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Lab05_Tests "C:/Users/Миша/Desktop/LROOP/lr5/build/Debug/tests.exe")
  set_tests_properties(Lab05_Tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Миша/Desktop/LROOP/lr5/CMakeLists.txt;28;add_test;C:/Users/Миша/Desktop/LROOP/lr5/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Lab05_Tests "C:/Users/Миша/Desktop/LROOP/lr5/build/Release/tests.exe")
  set_tests_properties(Lab05_Tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Миша/Desktop/LROOP/lr5/CMakeLists.txt;28;add_test;C:/Users/Миша/Desktop/LROOP/lr5/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Lab05_Tests "C:/Users/Миша/Desktop/LROOP/lr5/build/MinSizeRel/tests.exe")
  set_tests_properties(Lab05_Tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Миша/Desktop/LROOP/lr5/CMakeLists.txt;28;add_test;C:/Users/Миша/Desktop/LROOP/lr5/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Lab05_Tests "C:/Users/Миша/Desktop/LROOP/lr5/build/RelWithDebInfo/tests.exe")
  set_tests_properties(Lab05_Tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Миша/Desktop/LROOP/lr5/CMakeLists.txt;28;add_test;C:/Users/Миша/Desktop/LROOP/lr5/CMakeLists.txt;0;")
else()
  add_test(Lab05_Tests NOT_AVAILABLE)
endif()
