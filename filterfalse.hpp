#pragma once

namespace itertools
{
    template<typename F, typename T>
    class filterfalse
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

                const T &operator*() const
                {
                    
                }

                Iterator& operator++()
                {
                    
                }

                bool operator!=(const Iterator &other) const
                {
                    
                }
            };

            filterfalse(F lambda, T a) :  { } // struct, vector

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