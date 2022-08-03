#include "IteratorRow_Column.hpp"
class IterableSquareMatrix
{
public:
    virtual ~IterableSquareMatrix () = 0;

    //virtual double get(size_t i, size_t j) const = 0;
    
    virtual IteratorRow iter_rows(size_t) = 0;
    virtual IteratorColumn iter_columns(size_t) = 0;
    virtual IteratorRow end_rows(size_t) = 0;
    virtual IteratorColumn end_columns(size_t) = 0;
    virtual size_t size() = 0;
};