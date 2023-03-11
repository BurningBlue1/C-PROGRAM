#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

//这个头文件用于提取类型信息

//use standard header for type_traits
#include <type_traits>

namespace mystl{  //https://blog.csdn.net/fl2011sx/article/details/119353653
    //helper struct

    template <class T,T v>
    struct m_integral_constant{
        static constexpr T value = v; //静态constexpr变量
        //声明为constexpr的变量一定是const，而且必须用const表达式初始化
    };

    template <bool b>
    using m_bool_constant = m_integral_constant<bool,b>;
    // static constexpr bool value = true

    typedef m_bool_constant<true>  m_true_type;
    typedef m_bool_constant<false> m_false_type;

    /*****************************************************************************************/
    //type traits

    //is pair

    // --- forward declaration begin
    template <class T1,class T2>
    struct pair; //pair是定义在<mystl>中的生成特定类型的模板，作用是把一组数据合为一体，实际是一个拥有两个成员变量的struct
    // --- forward declaration end

    template <class T>
    struct is_pair : mystl::my_false_type{};  //mystl::my_false_type    namespace(命名空间)mystl中的my_false_type
    //此处的::是命名空间作用域符号，用来注明所使用的类、函数属于哪一个命名空间

    template <class T1,class T2>
    struct is_pair<mystl::pair<T1,T2>>::mystl::m_true_type {};
    /*
    template <typename>
    struct is_void : false_type {};

    template <>
    struct is_void<void> : true_type {};


    void test1();
    int test2();

    int main(int argc, const char *argv[]) {
        std::cout << is_void<decltype(test1())>::value << std::endl; // 1  //decltype在C++中，作为操作符，用于查询表达式的数据类型
        std::cout << is_void<decltype(test2())>::value << std::endl; // 0
        return 0;
    }
    */


} // namespace mystl

#endif // !MYTINYSTL_TYPE_TRAITS_H_

