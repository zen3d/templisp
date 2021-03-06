#pragma once

namespace {

struct nil
{
	typedef nil car;
	typedef nil cdr;
};
typedef nil NIL;

template <typename CAR, typename CDR>
struct cons
{
	typedef CAR car;
	typedef CDR cdr;

    constexpr cons() = default;
    constexpr cons(CAR, CDR) {}
};

template <typename T, T val>
struct value_type
{
    using type = T;
    static constexpr T value = val;
};

#define INT(_i) value_type<int, _i>

template<char... sym> struct symbol {};
template<typename C, C... SYM> constexpr auto operator"" _sym() { return symbol<SYM...>(); }

template<char... s> struct string {};
template<typename C, C... SYM> constexpr auto operator"" _str() { return string<SYM...>(); }

template <typename ARGS, typename BODY, typename SP>
struct lambda
{
	typedef ARGS args;
	typedef BODY body;
	typedef SP sp;
};

template <int p> struct ptr;

}
