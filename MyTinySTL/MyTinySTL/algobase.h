#ifndef MYTINYSTL_ALGOBASE_H_
#define MYTINYSTL_ALGOBASE_H_

// 这个头文件包含了 mystl 的基本算法

#include <cstring>

#include "iterator.h"
#include "util.h"

namespace mystl
{

#ifdef max
#pragma message("#undefing marco max")
#undef max
#endif //max

#ifdef min
#pragma message("#undefing marco min")
#undef min
#endif //min

/*****************************************************************************************/
// max
// 取二者中的较大值，语义相等时保证返回第一个参数
/*****************************************************************************************/
template <class T>
const T& max(const T& lhs,const T& rhs){
    return lhs<rhs?rhs:lhs;
}

//重载版本使用函数对象comp代替比较操作
template <class T,class Compare>
const T& max(const T& lhs,const T& rhs,Compare comp){
    return comp(lhs,rhs)?rhs:lhs;
}

/*****************************************************************************************/
// min 
// 取二者中的较小值，语义相等时保证返回第一个参数
/*****************************************************************************************/
template <class T>
const T& min(const T& lhs,const T& rhs){
    return rhs<lhs?rhs:lhs;
}

//重载版本使用函数对象comp代替比较操作
template <class T,class Compare>
const T& min(const T& lhs,const T& rhs,Compare comp){
    return comp(rhs,lhs)?rhs:lhs;
}

/*****************************************************************************************/
// iter_swap
// 将两个迭代器所指对象对调
/*****************************************************************************************/
template <class FIter1,class FIter2>
void iter_swap(FIter1 lhs,FIter2 rhs){
    mystl::swap(*lhs,*rhs);
}

/*****************************************************************************************/
// copy
// 把 [first, last)区间内的元素拷贝到 [result, result + (last - first))内
/*****************************************************************************************/
//input_iterator_tag 版本
template <class InputIter,class OutputIter>
OutputIter unchecked_copy_cat(InputIter first,InputIter last,OutputIter result,
                                mystl::input_iterator_tag)
{
    for(;first!=last;++first,++result){
        *result=*first;
    }
    return result;
}

//random_access_iterator_tag 版本
template <class RandomIter,class OutputIter>
OutputIter unchecked_copy_cat(RandomIter first,RandomIter last,OutputIter result,
                                mystl::random_access_iterator_tag)
{
    for (auto n=last-first;n>0;--n,++first,++result){
        *result=*first;
    }
    return result;
}

template <class InputIter,class OutputIter>
OutputIter unchecked_copy(InnputIter first,InputIter last,OutputIter result)
{
    return unchecked_copy_cat(first,last,result,iterator_category(first));
}

//为trivially_copy_assignable类型提供特化版本

//C++ STL的std::is_trivially_copy_assignable模板用于检查T是否是普通复制可分配类型。
//如果T是平凡的副本可分配类型，则它返回布尔值true，否则返回false
//C++11中的std::is_same可以判断输入的类型是否是指定的模板类型
//C++ STL的std::remove_const模板用于获取类型T，而无需const限定。如果T没有const限定，则返回布尔值true，否则返回false
//std::remove_const<T>::value
//C++的std::enable_if，只有当第一个模板参数为true时，type才有定义，否则使用type会产生编译错误
template <class Tp,class Up>
typename std::enable_if<
    std::is_same<typename std::remove_const<Tp>::type,Up>::value&&
    std::is_trivially_copy_assignable<Up>::value,
    Up*>::type
unchecked_copy(Tp* first,Tp* last,Up* result)
{
    const auto n=static_cast<size_t>(last-first);
    if(n!=0)
        std::memmove(result,first,n*sizeof(Up));
    return result+n;
}

template <class InputIter,class OutputIter>
OutputIter copy(InputIter first,InputIter last,PutputIter result)
{
    return unchecked_copy(first,last,result);
}


/*****************************************************************************************/
// copy_backward
// 将 [first, last)区间内的元素拷贝到 [result - (last - first), result)内
/*****************************************************************************************/
// unchecked_copy_backward_cat 的 bidirectional_iterator_tag 版本
template <class BidirectionalIter1,class BidirectionalIter2>
BidirectionalIter2



}











#endif //!MYTINYDTL_ALGOBASE_H_