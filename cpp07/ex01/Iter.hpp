#ifndef _ITER_HPP_
# define _ITER_HPP_

template <class T>
void    iter(T *ptr, long long length, void (*f)(T&))
{
    for (long long i = 0; i < length; i++)
        f(ptr[i]);
}

template <class T>
void    increment(T& element)
{
    element++;
}

#endif