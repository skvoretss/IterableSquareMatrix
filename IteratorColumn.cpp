//#include "IterableDenseMatrix.hpp"
#include "FunctionsOfGraf.hpp"
Element& IteratorColumn::operator*() const
{
    return *iter;
};

IteratorColumn& IteratorColumn::operator++()
{
   if (row_cur == col_size - 1)
    {
        column_cur = col_size + 1;
        row_cur = col_size + 1;
        iter = NULL;
        //std::cout << "sss 1" << std::endl;
        return *this;
    }
    /*
    size_t check_1 = iter->column_indx;
    size_t check_2 = iter->row_indx;
    size_t check_3 = last_elem->column_indx;
    size_t check_4 = last_elem->row_indx;
    */
    //if ((iter->column_indx == last_elem->column_indx) && (iter->row_indx == last_elem->row_indx))
    if ((column_cur == column_last) && (row_cur == row_last))
    {
        column_cur = col_size + 1;
        row_cur = col_size + 1;
        iter = NULL;
        //std::cout << "sss 2" << std::endl;
        return *this;
    }

    if (row_cur < col_size - 1)
    {
        //std::cout << "sss 3" << std::endl;
        while  (((iter+1)->value == 0) || (column_num != (iter+1)->column_indx))
        {
            if (((iter+1)->column_indx == column_last) && ((iter+1)->row_indx == row_last))
            {
                break;
            }
            iter++;
            //row_cur++;
        }
    }
    iter++;
    if ((column_num != iter->column_indx) || (iter->value == 0))
    {
        column_cur = col_size + 1;
        row_cur = col_size + 1;
        iter = NULL;
        //std::cout << "sss 4" << std::endl;
        return *this;
    }
    else
    {
        column_cur = iter->column_indx;
        row_cur = iter->row_indx;
        //std::cout << "column_cur = " <<  column_cur << std::endl;
        //std::cout << "row_cur = " <<  row_cur << std::endl;
        //std::cout << "sss 5" << std::endl;
    }
    /*
    if (row_cur < col_size - 1)
    {
        while (column_num != (iter+1)->column_indx)  
        {
            
            iter++;
            //row_cur++;
        }
        iter++;
        column_cur = iter->column_indx;
        row_cur = iter->row_indx;
        std::cout << "column_cur = " <<  column_cur << std::endl;
        std::cout << "row_cur = " <<  row_cur << std::endl;
        if (row_num == (iter+1)->row_indx)
        {
            iter++;
            column_cur = iter->column_indx;
        }
        else
        {
            column_cur = row_size + 1;
            row_cur = row_size + 1;
            iter = NULL;
        }
    }
    

    while ((row_cur < col_size - 1) && (iter->value == 0))
    {
        std::cout <<"%" << std::endl;
        iter++;
        column_cur++;
    }

    if ((iter != NULL) && (iter->value == 0))
    {
        column_cur = col_size + 1;
        row_cur = col_size + 1;
        iter = NULL;
    }    
    */
    return *this;
};

bool IteratorColumn::operator==(IteratorColumn it_)//bool IteratorColumn::operator==(IteratorColumn& it_)
{
    if ((row_cur == it_.row_cur) && (column_cur == it_.column_cur)) {return true;};
    return false;
};