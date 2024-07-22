#pragma once

#include <algorithm>

namespace sorting
{
    template<class RAIT, class Pr>
    void insertion_sort(const RAIT first, const RAIT last, Pr pred)
    {
        if(first >= last){
            return;
        }
        auto curr = first+1;
        while(curr < last){
            auto  key = *curr;
            RAIT  p   = curr-1;
            while(p >= first && pred(*p, key)){
                RAIT c = p+1;
                std::iter_swap(c,p);
                if(p == first)
                    break;
                p--;
            }
            if(p == first)
                *(p) = key;
            else
                *(p+1) = key;
            curr++;
        }
    }

    template<class T, class Pr>
    void insertion_sort(T* array, int length, Pr pred)
    {
        if(length <= 1){
            return;
        }
        T* curr = array+1;
        while(curr < array+length){
            T  key = *curr;
            T* p   = curr-1;
            while(p >= array && pred(*p, key)){
                T*  c = p+1;
                T tmp = *(c);
                *c    = *p;
                *p    = tmp;
                p--;
            }
            *(p+1) = key;
            curr++;
        }
    }
}