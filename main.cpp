//#include "IterableDenseMatrix.hpp"
#include "FunctionsOfGraf.hpp"
/*
0 1 0 0 0 0 4 1 0 1 1 0 0 2 0 1 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 4 2 0 0 0 0 0 - для матрицы 7 на 7(есть конечные вершины, несвязных нет)

0 1 0 0 0 0 0 1 0 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 4 2 0 0 0 0 0 - для матрицы 7 на 7(есть и конечные вершины и вершины без исходящих связей)

*/



int main()
{
    IterableSparseMatrix s(7, 7);

    
    //IteratorRow
    std::cout << "IteratorRow t:" << std::endl;
    IteratorRow t = s.iter_rows(0);
    std::cout << "t.row_cur = " << t.row_cur << std::endl;
    std::cout << "t.column_cur = " << t.column_cur << std::endl;
    std::cout << "t.row_num = " << t.row_num << std::endl;
    if (t.iter != NULL)
    {
        std::cout << "(*t).value = " << (*t).value << std::endl; //проверка *
    }
    else
    {
        std::cout << "t.iter = " << "NULL" << std::endl;
    }
    
    ++t; //проверка ++
    std::cout << std::endl;
    std::cout << "After++ //IteratorRow" << std::endl;
    std::cout << "t.row_cur = " << t.row_cur << std::endl;
    std::cout << "t.column_cur = " << t.column_cur << std::endl;
    std::cout << "t.row_num = " << t.row_num << std::endl;
    if (t.iter != NULL)
    {
        std::cout << "(*t).value = " << (t.iter)->value << std::endl; //проверка *
    }
    else
    {
        std::cout << "t.iter = " << "NULL" << std::endl; //проверка *
    }

    ////////////////
    std::cout << std::endl;
    std::cout << "IteratorRow t_1:" << std::endl;
    IteratorRow t_1 = s.iter_rows(0);
    std::cout << "t_1.row_cur = " << t_1.row_cur << std::endl;
    std::cout << "t_1.column_cur = " << t_1.column_cur << std::endl;
    std::cout << "t_1.row_num = " << t_1.row_num << std::endl;
    if (t_1.iter != NULL)
    {
        std::cout << "(*t_1).value = " << (*t_1).value << std::endl; //проверка *
    }
    else
    {
        std::cout << "t_1.iter = " << "NULL" << std::endl;
    }

    if (t_1 == t) {std::cout << "TRUE" <<std::endl;} //проверка ==
    else {std::cout << "FALSE" <<std::endl;}

    std::cout << std::endl;

    //IteratorColumn
    std::cout << "IteratorColumn ti:" << std::endl;
    IteratorColumn ti = s.iter_columns(1);
    std::cout << "ti.row_cur = " << ti.row_cur << std::endl;
    std::cout << "ti.column_cur = " << ti.column_cur << std::endl;
    std::cout << "ti.column_num = " << ti.column_num << std::endl;
    if (ti.iter != NULL)
    {
        std::cout << "(*ti).value = " << (*ti).value << std::endl; //проверка *
    }
    else
    {
        std::cout << "ti.iter = " << "NULL" << std::endl;
    }

    std::cout << std::endl;
    ++ti;
    std::cout << std::endl;
    std::cout << "After++ //IteratorColumn" << std::endl;
    std::cout << "ti.row_cur = " << ti.row_cur << std::endl;
    std::cout << "ti.column_cur = " << ti.column_cur << std::endl;
    std::cout << "ti.column_num = " << ti.column_num << std::endl;
    if (ti.iter != NULL)
    {
        std::cout << "(*ti).value = " << (*ti).value << std::endl; //проверка *
    }
    else
    {
        std::cout << "ti.iter = " << "NULL" << std::endl;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////
    IterableDenseMatrix d(7, 7);
    //IteratorRow
    std::cout << std::endl;
    std::cout << "DenseMatrix" << std::endl;

    std::cout << "IteratorRow t_:" << std::endl;
    IteratorRow t_ = d.iter_rows(0);
    std::cout << "t_.row_cur = " << t_.row_cur << std::endl;
    std::cout << "t_.column_cur = " << t_.column_cur << std::endl;
    std::cout << "t_.row_num = " << t_.row_num << std::endl;
    if (t_.iter != NULL)
    {
        std::cout << "(*t_).value = " << (*t_).value << std::endl; //проверка *
    }
    else
    {
        std::cout << "t_.iter = " << "NULL" << std::endl;
    }
    std::cout << std::endl;
    //row_size;
    ++t_; //проверка ++
    std::cout << std::endl;
    std::cout << "After++" << std::endl;
    std::cout << "t_.row_cur = " << t_.row_cur << std::endl;
    std::cout << "t_.column_cur = " << t_.column_cur << std::endl;
    std::cout << "t_.row_num = " << t_.row_num << std::endl;
    if (t_.iter != NULL)
    {
        std::cout << "(*t_).value = " << (*t_).value << std::endl; //проверка *
    }
    else
    {
        std::cout << "t_.iter = " << "NULL" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "IteratorRow t_2:" << std::endl;
    IteratorRow t_2 = d.iter_rows(0);
    std::cout << "t_2.row_cur = " << t_2.row_cur << std::endl;
    std::cout << "t_2.column_cur = " << t_2.column_cur << std::endl;
    std::cout << "t_2.row_num = " << t_2.row_num << std::endl;
    if (t_2.iter != NULL)
    {
        std::cout << "(*t_2).value = " << (*t_2).value << std::endl; //проверка *
    }
    else
    {
        std::cout << "t_2.iter = " << "NULL" << std::endl;
    }
    std::cout << std::endl;
    if (t_2 == t_) {std::cout << "TRUE" <<std::endl;} //проверка ==
    else {std::cout << "FALSE" <<std::endl;}
    std::cout << std::endl;
    IteratorRow t_3 = d.end_rows(0);
    std::cout << "t_3.row_cur = " << t_3.row_cur << std::endl;
    std::cout << "t_3.column_cur = " << t_3.column_cur << std::endl;
    std::cout << "t_3.row_num = " << t_3.row_num << std::endl;
    if (t_3.iter != NULL)
    {
        std::cout << "(*t_3).value = " << (*t_3).value << std::endl; //проверка *
    }
    else
    {
        std::cout << "t_3.iter = " << "NULL" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Diameter Sparse = " << Diameter(s) << std::endl;
    std::cout << "Diameter Dense = " << Diameter(d) << std::endl;
    int* f_s = BestNodes(s);
    int* f_d = BestNodes(d);
    std::cout << "SpaseMatrix BestNodes: " << std::endl;
    for (size_t i = 0; i < s.row_size; ++i) 
    {
        std::cout << "f_s[" << i << "] = " <<  f_s[i] << std::endl;
    }

    std::cout << "DenseMatrix BestNodes: " << std::endl;
    for (size_t i = 0; i < s.row_size; ++i) 
    {
        std::cout << "f_d[" << i << "] = " <<  f_d[i] << std::endl;
    }

    free(f_s);
    free(f_d);
}