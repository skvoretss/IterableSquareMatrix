#include <cstddef>
#include <iostream>
struct Element 
{
    size_t row_indx; // k 
    size_t column_indx; // m
    int value; // n
};

class IteratorRow
{
public:
    Element* iter;
    size_t row_cur;
    size_t column_cur;
    size_t row_num;
    size_t row_size;
    
    size_t row_last;
    size_t column_last;

    IteratorRow() = delete;
    IteratorRow(Element* elem, size_t r_cur, size_t c_cur, size_t r_num, size_t r_size, size_t r_l, size_t c_l): 
    iter(elem), row_cur(r_cur), column_cur(c_cur), row_num(r_num), row_size(r_size), row_last(r_l), column_last(c_l) {};
    Element &operator*() const;
    IteratorRow& operator++();
    bool operator==(IteratorRow); //bool operator==(IteratorRow&);
};

class IteratorColumn
{
public:
    Element* iter;
    size_t row_cur;
    size_t column_cur;
    size_t column_num;
    size_t col_size;

    size_t row_last;
    size_t column_last;

//public:
    IteratorColumn() = delete;
    IteratorColumn(Element* elem, size_t r_cur, size_t c_cur, size_t c_num, size_t c_size, size_t r_l, size_t c_l):  
    iter(elem), row_cur(r_cur), column_cur(c_cur), column_num(c_num), col_size(c_size), row_last(r_l), column_last(c_l) {};
    Element &operator*() const;
    IteratorColumn& operator++();
    bool operator==(IteratorColumn);//bool operator==(IteratorColumn&);
};

