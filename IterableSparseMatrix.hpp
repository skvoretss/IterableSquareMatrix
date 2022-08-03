#include "IterableSquareMatrix.hpp"
class IterableSparseMatrix: public IterableSquareMatrix
{
public:
    Element* el; 
    size_t row_size; 
    size_t column_size;
    int cnt;

    IterableSparseMatrix (size_t a, size_t b);
    ~IterableSparseMatrix ();

    int get(size_t i, size_t j) const;

    IteratorRow iter_rows(size_t) override;
    IteratorColumn iter_columns(size_t) override;
    IteratorRow end_rows(size_t) override;
    IteratorColumn end_columns(size_t) override;
    size_t size() override;

    //~IterableSquareMatrix ();
};
