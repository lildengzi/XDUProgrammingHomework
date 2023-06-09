/**
 * @file main.cpp
 * @name 高精度计算器(精度一万位)
 * @author lil_DengZi
 * @version v2.0
 * @date 2023/04/07
 * @todo 完善加减高精度减法
 * @include highcalculator.hpp highnumber.hpp
 * @brief 好难,yee~
 * 
 * @copyright    Copyright (c) 2023 lil_DengZi
 * 
*/

// === Region: Headers ===
// Do not include extra header files
// =======================
#include "highcalculator.hpp"
#include "highnumber.hpp"
#include <iostream>
#include <string>
using namespace std;

// === Region: Main Function ===
/**
 * @warning 不支持输入负数计算
 * 
 */
int main(int argc, char* argv[])
{
    HighCalculator h1(argv[1], argv[3], *argv[2]);
    cout << h1.getAnswer() << endl;
    return 0;
}