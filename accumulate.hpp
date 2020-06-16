#pragma once

namespace itertools
{
    template<typename T, typename F>
    class accumulate
    {
        private:
            T temp;
            F filter;
        
        public:
            class Iterator
            {
            private:
                Iterator iBegin;
                Iterator iEnd;
                
            public:
                Iterator(Iterator begin, Iterator end, F filter) : iBegin(begin), iEnd(end), filter(filter) {}

                T operator*() const
                {
                    return index;
                }

                Iterator& operator++()
                {
                    ++index;
                    return (*this);
                }

                Iterator operator++(int) 
                {
                    Iterator copy(*this);
                    ++index;
                    return copy;
                }

                bool operator==(const Iterator &other) const 
                {
                    return index == other.index; 
                }

                bool operator!=(const Iterator &other) const
                {
                    return index != other.index;
                }
            };

            accumulate(T a) :  { } // range/vector
            
            accumulate(T a, F lambda) :  { } // range/vector, lambda

            Iterator begin() const
            {
                return Iterator(temp.begin(), temp.end(), filter);
            }

            Iterator end() const
            {
                return Iterator(temp.end(), temp.end(), filter);
            }
    };
};