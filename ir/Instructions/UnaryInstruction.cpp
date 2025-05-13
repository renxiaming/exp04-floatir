///
/// @file UnaryInstruction.cpp
/// @brief 一元操作指令
///
/// @author zenglj (zenglj@live.com)
/// @version 1.0
/// @date 2024-09-29
///
/// @copyright Copyright (c) 2024
///
/// @par 修改日志:
/// <table>
/// <tr><th>Date       <th>Version <th>Author  <th>Description
/// <tr><td>2024-09-29 <td>1.0     <td>zenglj  <td>新建
/// </table>
///
#include "UnaryInstruction.h"

/// @brief 构造函数
/// @param _func 所属函数
/// @param _op 操作符
/// @param _srcVal 源操作数
/// @param _type 类型
UnaryInstruction::UnaryInstruction(Function * _func, IRInstOperator _op, Value * _srcVal, Type * _type)
    : Instruction(_func, _op, _type)
{
    addOperand(_srcVal);
}

/// @brief 转换成字符串
/// @param str 转换后的字符串
void UnaryInstruction::toString(std::string & str)
{
    Value * src = getOperand(0);

    // 确保操作数不为nullptr
    if (src == nullptr) {
        str = "Error: Operand is nullptr";
        return;
    }

    switch (op) {
        case IRInstOperator::IRINST_OP_INT2FLOAT:
            // 整数转浮点数指令，一元运算
            str = getIRName() + " = sitofp " + src->getIRName() + " to float";
            break;
        case IRInstOperator::IRINST_OP_FLOAT2INT:
            // 浮点数转整数指令，一元运算
            str = getIRName() + " = fptosi " + src->getIRName() + " to i32";
            break;
        default:
            // 未知指令
            Instruction::toString(str);
            break;
    }
}