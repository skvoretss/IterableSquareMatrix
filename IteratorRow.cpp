//#include "IterableDenseMatrix.hpp"
#include "FunctionsOfGraf.hpp"
Element& IteratorRow::operator*() const
{
    return *iter;
};

IteratorRow& IteratorRow::operator++()
{
    if (column_cur == row_size - 1)
    {
        column_cur = row_size + 1;
        row_cur = row_size + 1;
        iter = NULL;
        return *this;
    }
    if (column_cur < row_size - 1)
    {
        if (((iter->row_indx != row_last) || (iter->column_indx != column_last)) && (row_num == (iter+1)->row_indx))
        {
            iter++;
            column_cur = iter->column_indx;
        }
        else //if ((iter->row_indx == row_last) && (iter->column_indx == column_last))
        {
            column_cur = row_size + 1;
            row_cur = row_size + 1;
            iter = NULL;
            return *this;
        }
    }
    while ((column_cur < row_size - 1) && (iter->value == 0))
    {
        //std::cout <<"%" << std::endl;
        iter++;
        column_cur++;
    }
    if ((iter != NULL) && (iter->value == 0))
    {
        column_cur = row_size + 1;
        row_cur = row_size + 1;
        iter = NULL;
    }    
    return *this;
};

bool IteratorRow::operator==(IteratorRow it_)//bool IteratorRow::operator==(IteratorRow& it_)
{
    if ((row_cur == it_.row_cur) && (column_cur == it_.column_cur)) {return true;};
    return false;
};
