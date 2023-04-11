// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _HIGHCALCULATOR_HPP
#define _HIGHCALCULATOR_HPP

#include "highnumber.hpp"
#include <iostream>
#include <string>

/** === Region: class HighCalculator ===
 * @param number_1 HighNumber 第一个大数.
 * @param number_2 HighNumber 第二个大数.
 * @param oper char 运算符.
 * @param calculateAnswer HighNumber 计算结果.
 */
class HighCalculator
{
private:
    HighNumber number_1;
    HighNumber number_2;
    HighNumber calculateAnswer;
    char oper;
public:
    HighCalculator(const std::string &num_1, const std::string &num_2, char &theOperator): oper(theOperator)
    {
        number_1 = num_1;
        number_2 = num_2;
    }
    ~HighCalculator();

    /**
     * @brief getAnswer 得到计算结果
     * @details None
     * @return HighNumber
     *     @retval >0 正整数
     *     @retval =0 0
     *     @retval <0 负整数
     * @bug 没有添加非数字字符串的判断
     * @note None
     */
    HighNumber getAnswer()
    {
        if (this->oper == '+')
        {
            this->calculateAnswer = this->addBigData();
        }
        else if (this->oper == '-')
        {
            this->calculateAnswer = this->minusBigData();
        }

        return calculateAnswer;
    }
    
    /**
     * @brief addBigData 两个大数相加
     * @details None
     * @return HighNumber
     *     @retval >0 正整数
     *     @retval =0 0
     * @note None
     */
    HighNumber addBigData()
    {
        return number_1 + number_2;
    }

    /**
     * @brief addBigData 两个大数相减
     * @details None
     * @return HighNumber
     *     @retval >0 正整数
     *     @retval =0 0
     *     @retval <0 负整数
     * @note None
     */
    HighNumber minusBigData()
    {
        return number_1 - number_2;
    }

};

#endif // _HIGHCALCULATOR_HPP
