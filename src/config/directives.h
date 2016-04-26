#ifndef STANDARDDIRECTIVES_H
#define STANDARDDIRECTIVES_H

#include <iostream>

class App {
public:
    static constexpr const char* Version = "v0.1.0";
#if defined(_WIN32) || defined(_WIN64)
    static constexpr const char* DefaultPath = "C:\\";
#elif __unix || __unix__ || __linux__  || __FreeBSD__ || __APPLE__ || __MACH__
    static constexpr const char* DefaultPath = "/home/";
#endif

};



#endif // STANDARDDIRECTIVES_H
