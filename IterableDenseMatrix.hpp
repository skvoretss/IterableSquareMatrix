#include "IterableSparseMatrix.hpp"
class IterableDenseMatrix: public IterableSquareMatrix
{
public:
    Element* el; 
    size_t row_size; 
    size_t column_size;
    int cnt;

    IterableDenseMatrix (size_t a, size_t b);
    //virtual IterableSparseMatrix (Element*, int, int, int) = 0;
    ~IterableDenseMatrix ();

    int get(size_t i, size_t j) const;

    IteratorRow iter_rows(size_t);
    IteratorColumn iter_columns(size_t);
    IteratorRow end_rows(size_t);
    IteratorColumn end_columns(size_t);
    size_t size();

    //~IterableSquareMatrix ();

};