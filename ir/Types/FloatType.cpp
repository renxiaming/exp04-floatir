///
/// @file FloatType.cpp
/// @brief 浮点类型类，描述32位的float类型
///
/// @author zenglj (zenglj@live.com)
/// @version 1.0
/// @date 2024-11-27
///
/// @copyright Copyright (c) 2024
///
/// @par 修改日志:
/// <table>
/// <tr><th>Date       <th>Version <th>Author  <th>Description
/// <tr><td>2024-11-27 <td>1.0     <td>zenglj  <td>新建
/// </table>
///

#include "FloatType.h"

FloatType * FloatType::oneInstance = nullptr;

FloatType * FloatType::getType()
{
    if (oneInstance == nullptr) {
        oneInstance = new FloatType();
    }
    return oneInstance;
}