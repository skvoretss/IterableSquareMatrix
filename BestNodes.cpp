#include "FunctionsOfGraf.hpp"

/*
int* BestNodes(const IterableSparseMatrix& s)
{
    int* nodes_result; //массив, в котором буду по итогу храниться искомые нами вершины (их номера будут отмечены 1, остальные будут иметь значение 0)
    nodes_result = (int*)malloc(sizeof(int) * s.row_size);

    std::cout << "check 1" << std::endl;

    for (size_t i = 0; i < s.row_size; ++i) 
    {
        nodes_result[i] = 0;
    }
    std::cout << "check 2" << std::endl;

    int bones_max = 0;
    int i_bones = 0;
    for (size_t i = 0; i < s.row_size; ++i) //найдем значение для каждой вершины 
    {
        i_bones = 0; // ребер i-й вершины
        for (int j = 0; j < s.cnt; ++j)
        {
            if (((s.el[j].row_indx == i) || (s.el[j].column_indx == i)) && (s.el[j].value != 0))
            {
                i_bones++;
            } 
        }

        if (i_bones > bones_max)
        {
            for (size_t j = 0; j < s.row_size; ++j) 
            {
                nodes_result[j] = 0;
            }

            nodes_result[i] = i_bones;

            bones_max = i_bones;
        }
        if (i_bones == bones_max)
        {
            nodes_result[i] = i_bones;
        }

        for (size_t f = 0; f < s.row_size; ++f) 
        {
            std::cout << "nodes_result[" << f << "] = " <<  nodes_result[f] << std::endl;
        }

    }

    return nodes_result;
}*/

int* BestNodes(IterableSquareMatrix& s)
{
    int* nodes_result; //массив, в котором буду по итогу храниться искомые нами вершины (их номера будут отмечены 1, остальные будут иметь значение 0)
    nodes_result = (int*)malloc(sizeof(int) * s.size());

    //std::cout << "check 1" << std::endl;

    for (size_t i = 0; i < s.size(); ++i) 
    {
        nodes_result[i] = 0;
    }
    //std::cout << "check 2" << std::endl;

    int bones_max = 0;
    int i_bones = 0;
    IteratorRow it_row = s.iter_rows(0);
    IteratorColumn it_column = s.iter_columns(0);
    for (size_t i = 0; i < s.size(); ++i) //найдем значение для каждой вершины 
    {
        i_bones = 0; // рёбер i-й вершины
        it_row = s.iter_rows(i);
        it_column = s.iter_columns(i);
        /*
        for (int j = 0; j < s.cnt; ++j)
        {
            if (((s.el[j].row_indx == i) || (s.el[j].column_indx == i)) && (s.el[j].value != 0))
            {
                i_bones++;
            } 
        }
        */
        while (!(it_row == s.end_rows(i)))
        {
            //std::cout << "check 1" << std::endl;
            i_bones++; 
            ++it_row;
        } 
        
        while (!(it_column == s.end_columns(i)))
        {
            //std::cout << "check 2" << std::endl;
            i_bones++;
            ++it_column;
        }
        
        if (i_bones > bones_max)
        {
            for (size_t j = 0; j < s.size(); ++j) 
            {
                nodes_result[j] = 0;
            }

            nodes_result[i] = i_bones;

            bones_max = i_bones;
        }
        if (i_bones == bones_max)
        {
            nodes_result[i] = i_bones;
        }
        /*
        for (size_t f = 0; f < s.size(); ++f) 
        {
            std::cout << "nodes_result[" << f << "] = " <<  nodes_result[f] << std::endl;
        }
        */
    }

    return nodes_result;
}