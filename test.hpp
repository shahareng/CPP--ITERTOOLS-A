#pragma once

namespace itertools
{

    typedef struct 
    {
        template <typename P>
        P operator()(P a, P b) const
        {
            return a+b;
        }
    }plus;


    template<typename T, typename F= plus>
    class accumulate
    {        
        T temp;
        F func;

        public:
            class iterator
            {
            private:
                decltype(*(temp.begin())) index; //for pass over the template
                typename T::iterator iBegin;
                typename T::iterator iEnd;
                F func;

            public:
                iterator(typename T::iterator begin, typename T::iterator end, F fun) : iBegin(begin), iEnd(end), func(fun), index(*iBegin) { }

                auto operator*() const
                {
                    return index;
                }

                //++iBegin
                const iterator &operator++()
                {
                    ++iBegin;
                    if(iBegin != iEnd)
                        index = func(index,*iBegin);
                    return *this;
                }

                //iBegin++
                iterator operator++(int) 
                {
                    iterator copy = (*this);
                    ++iBegin;
                    if(iBegin != iEnd)
                        index = func(index,*iBegin);
                    return copy;
                }

                bool operator==(const iterator &other) const 
                {
                    return iBegin == other.iBegin;
                }

                bool operator!=(const iterator &other) const
                {
                    return iBegin != other.iBegin;
                }
            };
            
            accumulate(T a, F lambda = plus()) : temp(a), func(lambda) { }

            iterator begin() const
            {
                return iterator(temp.begin(), temp.end(), func);
            }

            iterator end() const
            {
                return iterator(temp.end(), temp.end(), func);
            }
    };
};