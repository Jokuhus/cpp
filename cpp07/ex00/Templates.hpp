#ifndef _TEMPLATES_HPP_
# define _TEMPLATES_HPP_

template <class T>
void    swap(T& a, T& b)
{
    T   temp;

    temp = a;
    a = b;
    b = temp;
}

template <class T>
T   min(T& a, T& b)
{
    return (a < b) ? a : b;
}

template <class T>
T   max(T& a, T& b)
{
    return (a > b) ? a : b;
}

#endif