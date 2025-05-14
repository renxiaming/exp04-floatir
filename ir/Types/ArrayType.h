///
/// @file ArrayType.h
/// @brief 数组类型描述类
/// @author zenglj (zenglj@live.com)
/// @version 1.0
/// @date 2024-11-23
///
/// @copyright Copyright (c) 2024
///
/// @par 修改日志:
/// <table>
/// <tr><th>Date       <th>Version <th>Author  <th>Description
/// <tr><td>2024-11-23 <td>1.0     <td>zenglj  <td>新建
/// </table>
///
#pragma once

#include "Type.h"
#include "StorageSet.h"

///
/// @brief 数组类型
///
class ArrayType : public Type {

    ///
    /// @brief Hash用结构体，提供Hash函数
    ///
    struct ArrayTypeHasher final {

        /// @brief 给定一个ArrayType，返回用于std::unordered_map的hash值
        ///
        /// @param[in] type 要hash的ArrayType
        ///
        /// @returns 类型的hash值
        size_t operator()(const ArrayType & type) const noexcept
        {
            return std::hash<const Type *>{}(type.getElementType()) ^ std::hash<uint32_t>{}(type.getNumElements());
        }
    };

    ///
    /// @brief 判断两者相等的结构体，提供等于函数
    ///
    struct ArrayTypeEqual final {
        /// @brief 检查两个ArrayType对象是否相等
        ///
        /// @param[in] lhs 第一个要比较的ArrayType
        /// @param[in] rhs 第二个要比较的ArrayType
        ///
        /// @returns 如果两个ArrayType相等返回true，否则返回false
        ///
        size_t operator()(const ArrayType & lhs, const ArrayType & rhs) const noexcept
        {
            return lhs.getElementType() == rhs.getElementType() && lhs.getNumElements() == rhs.getNumElements();
        }
    };

public:
    /// @brief ArrayType的构造函数
    /// @param[in] elementType 数组元素的类型
    /// @param[in] numElements 数组元素的数量
    ///
    /// 该构造函数将Type的ID设置为ArrayTyID，并且
    /// 保存elementType的指针和元素数量到成员变量
    explicit ArrayType(const Type * elementType, uint32_t numElements)
        : Type(ArrayTyID), elementType(elementType), numElements(numElements)
    {}

    ///
    /// @brief 返回数组元素的类型
    /// @return const Type*
    ///
    [[nodiscard]] const Type * getElementType() const
    {
        return elementType;
    }

    ///
    /// @brief 返回数组元素的数量
    /// @return uint32_t
    ///
    [[nodiscard]] uint32_t getNumElements() const
    {
        return numElements;
    }

    ///
    /// @brief 获取数组所占内存空间大小
    /// @return int32_t
    ///
    [[nodiscard]] int32_t getSize() const override
    {
        return elementType->getSize() * numElements;
    }

    ///
    /// @brief 获取数组类型
    /// @param elementType 元素类型
    /// @param numElements 元素数量
    /// @return const ArrayType*
    ///
    static const ArrayType * get(Type * elementType, uint32_t numElements)
    {
        static StorageSet<ArrayType, ArrayTypeHasher, ArrayTypeEqual> storageSet;
        return storageSet.get(elementType, numElements);
    }

    ///
    /// @brief 获取数组类型（非const版本）
    /// @param elementType 元素类型
    /// @param numElements 元素数量
    /// @return ArrayType* 非const指针
    ///
    static ArrayType * getNonConst(Type * elementType, uint32_t numElements)
    {
        // 创建一个新的ArrayType实例
        return new ArrayType(elementType, numElements);
    }

    ///
    /// @brief 获取类型的IR标识符
    /// @return std::string IR标识符
    ///
    [[nodiscard]] std::string toString() const override
    {
        return "[" + std::to_string(numElements) + " x " + elementType->toString() + "]";
    }

private:
    ///
    /// @brief 数组元素的类型
    ///
    const Type * elementType = nullptr;

    ///
    /// @brief 数组元素的数量
    ///
    uint32_t numElements = 0;
};