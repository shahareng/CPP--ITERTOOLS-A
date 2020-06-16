#pragma once

namespace itertools
{
    class range
    {
        public:
            class Iterator
            {
                friend class range;
                public:
                    Iterator(int i) { index = i; }

                    int operator*() const
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
                private:
                    int index;
            };

            range(int a, int b) : iBegin(a), iEnd(b) {  }

            Iterator begin() const
            {
                return iBegin;
            }

            Iterator end() const
            {
                return iEnd;
            }
        private:
            Iterator iBegin;
            Iterator iEnd;
    };
};