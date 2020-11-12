# containers
Projet will contain basic containers to use in separate projeects (it will be able to compile it to a static lib and add to projects). It is created to practice C++ and unit test development.

I will build this project using TDD to practice this technique (google test and googel mocks frameworks will be used).

It is needed to clone googletest framework (https://github.com/google/googletest) into googletest directory - is it possible to avoid it?!



Recently added array (both version) implementatnion with interface similar to std::array. To compile cpp20 version of this project you have to have: 

Visual Studio at least v/16.8, C++ language standard: Preview - Features from the Latest C++ Working Draft (/std:c++latest), Runtime Library: Multi-theraded DLL (/MD) and Enable 
C++ Modules for STL(exeperimental): Yes(/experimental:module)
