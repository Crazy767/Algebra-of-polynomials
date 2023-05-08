# Install script for directory: C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Algebra-of-Polynomials")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/app/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Core/avl_tree/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Core/clist/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Core/linear_array/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Core/monomial/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Core/polynomial/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Core/postfix_polinoms/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Tables/avl_tree_table/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Tables/hash_chain_table/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Tables/interface_table/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Tables/linear_list_table/cmake_install.cmake")
  include("C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/libs/Tables/sorted_array_table/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/sasch/OneDrive/Рабочий стол/Programs/Learning/Прога/Algebra-of-polynomials/Algebra-of-Polynomials/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
