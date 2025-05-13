///
/// @file BinaryInstruction.cpp
/// @brief 二元操作指令
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
#include "BinaryInstruction.h"

/// @brief 构造函数
/// @param _op 操作符
/// @param _result 结果操作数
/// @param _srcVal1 源操作数1
/// @param _srcVal2 源操作数2
BinaryInstruction::BinaryInstruction(Function * _func,
                                     IRInstOperator _op,
                                     Value * _srcVal1,
                                     Value * _srcVal2,
                                     Type * _type)
    : Instruction(_func, _op, _type)
{
    addOperand(_srcVal1);
    addOperand(_srcVal2);
}

/// @brief 转换成字符串
/// @param str 转换后的字符串
void BinaryInstruction::toString(std::string & str)
{
    Value *src1 = getOperand(0), *src2 = getOperand(1);

    // 确保src1不为nullptr
    if (src1 == nullptr) {
        str = "Error: First operand is nullptr";
        return;
    }

    switch (op) {
        case IRInstOperator::IRINST_OP_INT2FLOAT:
            // 整数转浮点数指令，一元运算，只需要第一个操作数
            str = getIRName() + " = sitofp " + src1->getIRName() + " to float";
            break;
        case IRInstOperator::IRINST_OP_FLOAT2INT:
            // 浮点数转整数指令，一元运算，只需要第一个操作数
            str = getIRName() + " = fptosi " + src1->getIRName() + " to i32";
            break;
        case IRInstOperator::IRINST_OP_ADD_I:
        case IRInstOperator::IRINST_OP_ADD_F:
        case IRInstOperator::IRINST_OP_SUB_I:
        case IRInstOperator::IRINST_OP_SUB_F:
        case IRInstOperator::IRINST_OP_MUL_I:
        case IRInstOperator::IRINST_OP_MUL_F:
        case IRInstOperator::IRINST_OP_DIV_I:
        case IRInstOperator::IRINST_OP_DIV_F:
            // 确保src2不为nullptr，这些是二元运算，需要两个操作数
            if (src2 == nullptr) {
                str = "Error: Second operand is nullptr for binary operation";
                return;
            }

            // 根据操作码生成对应的指令字符串
            switch (op) {
                case IRInstOperator::IRINST_OP_ADD_I:
                    // 整数加法指令，二元运算
                    str = getIRName() + " = add " + src1->getIRName() + "," + src2->getIRName();
                    break;
                case IRInstOperator::IRINST_OP_ADD_F:
                    // 浮点数加法指令，二元运算
                    str = getIRName() + " = fadd " + src1->getIRName() + "," + src2->getIRName();
                    break;
                case IRInstOperator::IRINST_OP_SUB_I:
                    // 整数减法指令，二元运算
                    str = getIRName() + " = sub " + src1->getIRName() + "," + src2->getIRName();
                    break;
                case IRInstOperator::IRINST_OP_SUB_F:
                    // 浮点数减法指令，二元运算
                    str = getIRName() + " = fsub " + src1->getIRName() + "," + src2->getIRName();
                    break;
                case IRInstOperator::IRINST_OP_MUL_I:
                    // 整数乘法指令，二元运算
                    str = getIRName() + " = mul " + src1->getIRName() + "," + src2->getIRName();
                    break;
                case IRInstOperator::IRINST_OP_MUL_F:
                    // 浮点数乘法指令，二元运算
                    str = getIRName() + " = fmul " + src1->getIRName() + "," + src2->getIRName();
                    break;
                case IRInstOperator::IRINST_OP_DIV_I:
                    // 整数除法指令，二元运算
                    str = getIRName() + " = sdiv " + src1->getIRName() + "," + src2->getIRName();
                    break;
                case IRInstOperator::IRINST_OP_DIV_F:
                    // 浮点数除法指令，二元运算
                    str = getIRName() + " = fdiv " + src1->getIRName() + "," + src2->getIRName();
                    break;
                default:
                    // 未知指令
                    Instruction::toString(str);
                    break;
            }
            break;
        default:
            // 未知指令
            Instruction::toString(str);
            break;
    }
}
