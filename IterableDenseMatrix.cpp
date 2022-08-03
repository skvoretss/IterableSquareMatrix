//#include "IterableDenseMatrix.hpp"
#include "FunctionsOfGraf.hpp"
IterableDenseMatrix::IterableDenseMatrix (size_t a, size_t b)
{
    row_size = a; // кол-во строк в матрице
    column_size = b; //  кол-во стобцов в матрице
    cnt = 0; // кол-во ненулевых элементов
    std::cout << "Please, input the values of matrix elements" << std::endl;
    double t = 0.0;
    for (int i = 0; i < (int)row_size; ++i)
    {
        for (int j = 0; j < (int)column_size; ++j)
        {
            std::cin >> t;
            ///выделить под этот элемент память и проинициализировать
            cnt++;
            if (cnt == 1)
            {
                el = (Element*)malloc(sizeof(Element));
            }
            else
            {
                el = (Element*)realloc(el, cnt * sizeof(Element));
            }
            el[cnt-1].row_indx = i;
            el[cnt-1].column_indx = j;
            el[cnt-1].value = t;
            std::cout << el[cnt-1].row_indx << " " << el[cnt-1].column_indx << " " << el[cnt-1].value <<std::endl;
        }
    }
};

IterableDenseMatrix::~IterableDenseMatrix ()
{
    if (el != NULL)
    {
        free(el);
    }   
}


int IterableDenseMatrix::get(size_t isk_1, size_t isk_2) const
{
    for (int i = 0; i < cnt; ++i)
    {
        if ((el[i].row_indx == isk_1) && (el[i].column_indx == isk_2))
        {
            return el[i].value;
        }
    }
    return 0;
};
//////////////////////////////////////////////////////////////////////////////////
IteratorRow IterableDenseMatrix::iter_rows(size_t r_n)
{
    //(Element* elem, size_t r_cur, size_t c_cur, size_t r_num, size_t r_size): 
    size_t r_cur = r_n, r_num = r_n, r_size = row_size;
    int j = -1;
    //std::cout << "r_cur = " << r_cur << std::endl;
    for (int i = 0; i < cnt; ++i)
    {
        //std::cout << "el[i].row_indx = " << el[i].row_indx << std::endl;
        if ((el[i].value != 0) && (el[i].row_indx == r_cur))
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        //std::cout << "*" << std::endl;
        IteratorRow itr(NULL, r_size + 1, r_size + 1, r_num, r_size, r_size + 1, r_size + 1);
        return itr;
    }
    IteratorRow itr(el + j, (el+j)->row_indx, (el+j)->column_indx, r_num, r_size, el[cnt-1].row_indx, el[cnt-1].column_indx);
    return itr;
};
//////////////////////////////////////////////////////////////////////////////
IteratorColumn IterableDenseMatrix::iter_columns(size_t c_n)
{
    //(Element* elem, size_t r_cur, size_t c_cur, size_t r_num, size_t r_size): 
    size_t c_cur = c_n, c_num = c_n, c_size = column_size;
    int j = -1;
    for (int i = 0; i < cnt; i++)
    {
        if ((el[i].value != 0) && (el[i].column_indx == c_cur))
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        //std::cout << "*" << std::endl;
        IteratorColumn itr(NULL, c_size + 1, c_size + 1, c_num, c_size, c_size + 1, c_size + 1);
        return itr;
    }
    //return 
    IteratorColumn itr(el + j, (el+j)->row_indx, (el+j)->column_indx, c_num, c_size, el[cnt-1].row_indx, el[cnt-1].column_indx);
    return itr;
};

IteratorRow IterableDenseMatrix::end_rows(size_t r_num)
{
    IteratorRow itr(NULL, row_size + 1, row_size + 1, r_num, row_size, row_size + 1, row_size + 1);
    return itr;
};

IteratorColumn IterableDenseMatrix::end_columns(size_t c_num)
{
    IteratorColumn itr(NULL, column_size + 1, column_size + 1, c_num, column_size, column_size + 1, column_size + 1);
    return itr;
};

size_t IterableDenseMatrix::size()
{
    return column_size;
}

//IterableSquareMatrix::~IterableSquareMatrix () { }