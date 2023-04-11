// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _ABSTRACTUSER_HPP
#define _ABSTRACTUSER_HPP

#include <iostream>
#include <string>

/** === Region: class AbstractUser ===
 * @todo 管理员和读者共有功能
 */
class AbstractUser
{
public:
    virtual AbstractUser find();
};

#endif //_ABSTRACTUSER_HPP

