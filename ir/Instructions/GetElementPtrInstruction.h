///
/// @file GetElementPtrInstruction.h
/// @brief GetElementPtr指令，用于数组元素访问
/// @author zenglj (zenglj@live.com)
/// @version 1.0
/// @date 2024-11-24
///
/// @copyright Copyright (c) 2024
///
/// @par 修改日志:
/// <table>
/// <tr><th>Date       <th>Version <th>Author  <th>Description
/// <tr><td>2024-11-24 <td>1.0     <td>zenglj  <td>新建
/// </table>
///
#pragma once

#include "Instruction.h"
#include "Value.h"
#include "Function.h"

///
/// @brief GetElementPtr指令，用于数组元素访问
///
class GetElementPtrInstruction : public Instruction {
public:
    /// @brief 构造函数
    /// @param func 所属函数
    /// @param array 数组变量
    /// @param index 索引值
    /// @param elementType 元素类型
    GetElementPtrInstruction(Function * func, Value * array, Value * index, Type * elementType)
        : Instruction(func, IRInstOperator::IRINST_OP_GETELEMENTPTR, elementType)
    {
        addOperand(array);
        addOperand(index);
    }

    /// @brief 析构函数
    ~GetElementPtrInstruction() = default;

    /// @brief 获取数组变量
    Value * getArray()
    {
        return getOperand(0);
    }

    /// @brief 获取索引值
    Value * getIndex()
    {
        return getOperand(1);
    }

    /// @brief 转换为字符串表示
    void toString(std::string & str) override
    {
        Value * array = getArray();
        Value * index = getIndex();

        if (array && index) {
            str = this->getIRName() + " = getelementptr " + array->getType()->toString() + ", " + array->getIRName() +
                  ", " + index->getIRName();
        } else {
            Instruction::toString(str);
        }
    }
};