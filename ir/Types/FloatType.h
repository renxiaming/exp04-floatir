///
/// @file FloatType.h
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

#pragma once

#include <cstdint>

#include "Type.h"

class FloatType final : public Type {

public:
    ///
    /// @brief 获取类型，全局只有一份
    /// @return FloatType*
    ///
    static FloatType * getType();

    ///
    /// @brief 获取类型的IR标识符
    /// @return std::string IR标识符float
    ///
    [[nodiscard]] std::string toString() const override
    {
        return "float";
    }

    ///
    /// @brief 获得类型所占内存空间大小
    /// @return int32_t
    ///
    [[nodiscard]] int32_t getSize() const override
    {
        return 4;
    }

private:
    ///
    /// @brief 构造函数
    ///
    FloatType() : Type(Type::FloatTyID)
    {}

    ///
    /// @brief 唯一的FLOAT类型实例
    ///
    static FloatType * oneInstance;
};