#include "FunctionsOfGraf.hpp"
//#include <limits>
/*
int Diameter(const IterableSparseMatrix& s)
{
    // part 1 - в этой части мы проверяем граф на связность, т.к. если граф несвязный, то его диаметр по определению равен infinity(обозначанется как -1)


    // массивы rows_check и columns_check нужны для определения связность или несвязности графа, 

    int* rows_check; // массив, который хранит встречающиеся строки(если по номеру строки у нас 0, значит у нас есть несвязная компонента)
    int* columns_check; // массив, который хранит встречающиеся столбцы(если по номеру столбца у нас 0, значит у нас есть несвязная компонента)

    rows_check = (int*)malloc(sizeof(int) * s.row_size);
    columns_check = (int*)malloc(sizeof(int) * s.column_size);

    for (size_t i = 0; i < s.row_size; ++i) // матрица квадратная, а значит s.row_size = s.column_size (в строках 9 и 10 используются разные поля просто для наглядности)
    {
        rows_check[i] = 0;
        columns_check[i] = 0;
    }

    //std::cout << "check 1" << std::endl;

    for (int i = 0; i < s.cnt; ++i) // заполняем: el[i].row_indx и el[i].column_indx дают нам номера координат ненулевых элементов 
    {
        rows_check[s.el[i].row_indx] = 1;
        columns_check[s.el[i].column_indx] = 1;
    }

    //std::cout << "check 2" << std::endl;

    for (size_t i = 0; i < s.row_size; ++i) // проверяем на 0
    {
        if ((rows_check[i] == 0) || (columns_check[i] == 0)) 
        {
            return -1; // нашли несвязную компоненту, значит диаметр = бесконечности (в этом случае возвращаем -1)
        }
    }

    //std::cout << "check 3" << std::endl;
    free(rows_check); //очистили
    free(columns_check); //очистили

    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------//

    //part 2 - если мы сюда попали, значит несвязных компонент нет и мы ищем диаметр, используя алгоритм Дейкстры

    int* length_check; 
    int* node_check;

    // массив length_check хранит кратчайшее расстояние от вершины i до всех остальных вершин
    // из него будет выбираться максимум, а потом массив будет очищаться и заполнять для новой вершины 
    // максимум кратчайшего расстояния i-й вершины будет храниться в max_length
    // из max_length будет выбран максимум и он и будет являться ответом
    // node_check нужен для отметки пройденных вершин (очищается для каждой новой i-й вершины)
    length_check = (int*)malloc(sizeof(int) * s.row_size);
    node_check = (int*)malloc(sizeof(int) * s.row_size);
    int max_length = 0; // в этой переменной хранится диаметр 

    for (size_t i = 0; i < s.row_size; ++i)  // инициализируем 
    {
        length_check[i] = std::numeric_limits<int>::max();
        node_check[i] = 0;
    }

    //std::cout << "check 4" << std::endl;

    for (size_t i = 0; i < s.row_size; ++i) // выволним алгоритм для каждой вершины 
    {
        int node_check_flag = 0; // флаг, проверяющий, что мы нашли все расстояния от i-й вершины до остальных

        size_t node_num = i; // переменная, по которой меняются вершины, чтобы пройти по всему графу(изначально равна i-й вершины)

        size_t node_next = node_num; // здесь храним номер следующей вершины - той, у которой вес с нынешней вершной наименьший
        int weight_min = std::numeric_limits<int>::max(); // постепенно найдем минимум с нынешней вершиной

        length_check[i] = 0; // для вершины, для которой происводится алгоритм, ставим значение 0, ей не нужно до себя самой идти
        while(node_check_flag != 1) 
        {
            weight_min = std::numeric_limits<int>::max(); // перед новым шагом вновь сделали значение максимальным 

            int end_point_flag = 1; // флаг, определяющий, дошлили мы до вершины-листа(по определению считаем, что дошли)


            for (int j = 0; j < s.cnt; ++j)
            {
                if (s.el[j].row_indx == node_num) // проверяем, что вы смотрим нужную нам строку
                {
                    if (node_check[s.el[j].column_indx] == 0) // проверяем, что эта вершина не отмечена 
                    {
                        // проверяем, что путь исходный больше предлагаемого (пример: путь 0->3 занимает 5, а путь 0->2->3 занимает 4)
                        if (length_check[s.el[j].column_indx] >  length_check[node_num] + s.el[j].value) // путь от вершины i до текущей вершины + путь от текущей вершины до соседа
                        {
                            length_check[s.el[j].column_indx] = length_check[node_num] + s.el[j].value;
                        }

                        if (s.el[j].value < weight_min) // ищем следующую вершину(ребро от текущей до неё должно быть самым коротким)
                        {
                            node_next = s.el[j].column_indx;
                            weight_min = s.el[j].value;
                        }

                        end_point_flag = 0; // попали сюда, значит эта вершины не лист
                    }
                    
                }
            }
            //std::cout << "check 5" << std::endl;

            node_check[node_num] = 1; //отметили i-ю вершину как пройденную
            //std::cout << "node_check[node_num] = " << node_check[node_num] << std::endl;
            //std::cout <<  "node_num = " << node_num << std::endl;

            node_check_flag = 1; // надеемся, что это был последний шаг алгоритма и подниманем флаг
            for (size_t k = 0; k < s.row_size; ++k) // надежда умирает последней, поэтому проверяем на финал - если не достигли, опускаем флаг обратно
            {
                //std::cout << "node_check[" << k << "] = " << node_check[k] << std::endl;
                if (node_check[k] == 0)
                {
                    node_check_flag = 0;
                    break;
                }
            }
            //std::cout << "check 6" << std::endl;

            if (end_point_flag) //если флаг поднят, значит мы в вершине-листе и нам нужно хитро самим выбрать следующую вершину
            {
                weight_min = std::numeric_limits<int>::max(); // мы будем искать минимум по массиву length_check
                for (size_t k = 0; k < s.row_size; ++k)
                {
                    //выбираем такую вершину, которая еще не пройдена, не изначальную и расстояние у которой минимальное
                    if ((node_check[k] == 0) && (length_check[k] != 0) && (weight_min > length_check[k])) 
                    {
                        node_next = k;
                        weight_min = length_check[k];
                    }
                }

            }

            //если не дошли до последнего шага, значит меняем тукущую вершину
            node_num = node_next;

        }
        //std::cout << "check 7" << std::endl;
        //алгоритм Дейкстры для i-й вершины завершен и массив length_check хранит все кратчайшие расстояния от i-й вершины
        // теперь подготовим всё необходимое, чтобы выполнить алгоритм для вершины i+1
        // и заодно проверим на максимальность max_length

        for (size_t k = 0; k < s.row_size; ++k)
        {
            if (max_length < length_check[k]) //проверяем, что текущий максимум меньше кратчайшего расстояния от вершины i до вершины k
            {
                max_length = length_check[k];
            }
        }

        //std::cout << "check 8" << std::endl;

        for (size_t k = 0; k < s.row_size; ++k)  // чистим 
        {
            length_check[k] = std::numeric_limits<int>::max();
            node_check[k] = 0;
        }
        //std::cout << "check 9" << std::endl;
    }
    //std::cout << "check 10" << std::endl;
    free(length_check); // не забываем освобождать массив
    free(node_check); // не забываем освобождать массив

    return max_length;
    
} 
*/

int Diameter(IterableSquareMatrix& s)
{
    // part 1 - в этой части мы проверяем граф на связность, т.к. если граф несвязный, то его диаметр по определению равен infinity(обозначанется как -1)


    // массивы rows_check и columns_check нужны для определения связность или несвязности графа, 

    int* rows_check; // массив, который хранит встречающиеся строки(если по номеру строки у нас 0, значит у нас есть несвязная компонента)
    int* columns_check; // массив, который хранит встречающиеся столбцы(если по номеру столбца у нас 0, значит у нас есть несвязная компонента)

    rows_check = (int*)malloc(sizeof(int) * s.size());
    columns_check = (int*)malloc(sizeof(int) * s.size());

    for (size_t i = 0; i < s.size(); ++i) 
    {
        rows_check[i] = 0;
        columns_check[i] = 0;
    }

    //std::cout << "check 1" << std::endl;
    IteratorRow it_row = s.iter_rows(0);
    IteratorColumn it_column = s.iter_columns(0);
    for (size_t i = 0; i < s.size(); ++i) // заполняем: el[i].row_indx и el[i].column_indx дают нам номера координат ненулевых элементов 
    {
        it_row = s.iter_rows(i);
        it_column = s.iter_columns(i);
        while (!(it_row == s.end_rows(i)))
        {
            rows_check[it_row.row_cur] = 1;
            ++it_row;
        } 
        
        while (!(it_column == s.end_columns(i)))
        {
            columns_check[it_column.column_cur] = 1;
            ++it_column;
        }
        //rows_check[s.el[i].row_indx] = 1;
        //columns_check[s.el[i].column_indx] = 1;
    }

    //std::cout << "check 2" << std::endl;

    for (size_t i = 0; i < s.size(); ++i) // проверяем на 0
    {
        if ((rows_check[i] == 0) || (columns_check[i] == 0)) 
        {
            return -1; // нашли несвязную компоненту, значит диаметр = бесконечности (в этом случае возвращаем -1)
        }
    }

    //std::cout << "check 3" << std::endl;
    free(rows_check); //очистили
    free(columns_check); //очистили

    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------//

    //part 2 - если мы сюда попали, значит несвязных компонент нет и мы ищем диаметр, используя алгоритм Дейкстры

    int* length_check; 
    int* node_check;

    // массив length_check хранит кратчайшее расстояние от вершины i до всех остальных вершин
    // из него будет выбираться максимум, а потом массив будет очищаться и заполнять для новой вершины 
    // максимум кратчайшего расстояния i-й вершины будет храниться в max_length
    // из max_length будет выбран максимум и он и будет являться ответом
    // node_check нужен для отметки пройденных вершин (очищается для каждой новой i-й вершины)
    length_check = (int*)malloc(sizeof(int) * s.size());
    node_check = (int*)malloc(sizeof(int) * s.size());
    int max_length = 0; // в этой переменной хранится диаметр 

    for (size_t i = 0; i < s.size(); ++i)  // инициализируем 
    {
        length_check[i] = std::numeric_limits<int>::max();
        node_check[i] = 0;
    }

    //std::cout << "check 4" << std::endl;

    for (size_t i = 0; i < s.size(); ++i) // выволним алгоритм для каждой вершины 
    {
        int node_check_flag = 0; // флаг, проверяющий, что мы нашли все расстояния от i-й вершины до остальных

        size_t node_num = i; // переменная, по которой меняются вершины, чтобы пройти по всему графу(изначально равна i-й вершины)

        size_t node_next = node_num; // здесь храним номер следующей вершины - той, у которой вес с нынешней вершной наименьший
        int weight_min = std::numeric_limits<int>::max(); // постепенно найдем минимум с нынешней вершиной

        length_check[i] = 0; // для вершины, для которой происводится алгоритм, ставим значение 0, ей не нужно до себя самой идти
        while(node_check_flag != 1) 
        {
            weight_min = std::numeric_limits<int>::max(); // перед новым шагом вновь сделали значение максимальным 

            int end_point_flag = 1; // флаг, определяющий, дошлили мы до вершины-листа(по определению считаем, что дошли)

            /*
            for (int j = 0; j < s.cnt; ++j)
            {
                if (s.el[j].row_indx == node_num) // проверяем, что вы смотрим нужную нам строку
                {
                    if (node_check[s.el[j].column_indx] == 0) // проверяем, что эта вершина не отмечена 
                    {
                        // проверяем, что путь исходный больше предлагаемого (пример: путь 0->3 занимает 5, а путь 0->2->3 занимает 4)
                        if (length_check[s.el[j].column_indx] >  length_check[node_num] + s.el[j].value) // путь от вершины i до текущей вершины + путь от текущей вершины до соседа
                        {
                            length_check[s.el[j].column_indx] = length_check[node_num] + s.el[j].value;
                        }

                        if (s.el[j].value < weight_min) // ищем следующую вершину(ребро от текущей до неё должно быть самым коротким)
                        {
                            node_next = s.el[j].column_indx;
                            weight_min = s.el[j].value;
                        }

                        end_point_flag = 0; // попали сюда, значит эта вершины не лист
                    }
                    
                }
            }
            */
            it_row = s.iter_rows(node_num);
            while (!(it_row == s.end_rows(node_num)))
            {
                //it_row = s.iter_rows(node_num);
                //it_column = s.iter_columns(node_num);

                //if (s.el[j].row_indx == node_num) // проверяем, что мы смотрим нужную нам строку
                //{
                    if (node_check[it_row.column_cur] == 0) // проверяем, что эта вершина не отмечена 
                    {
                        // проверяем, что путь исходный больше предлагаемого (пример: путь 0->3 занимает 5, а путь 0->2->3 занимает 4)
                        if (length_check[it_row.column_cur] >  length_check[node_num] + (it_row.iter)->value) // путь от вершины i до текущей вершины + путь от текущей вершины до соседа
                        {
                            length_check[it_row.column_cur] = length_check[node_num] + (it_row.iter)->value;
                        }

                        if ((it_row.iter)->value < weight_min) // ищем следующую вершину(ребро от текущей до неё должно быть самым коротким)
                        {
                            node_next = it_row.column_cur;
                            weight_min = (it_row.iter)->value;
                        }

                        end_point_flag = 0; // попали сюда, значит эта вершины не лист
                    }
                    
               // }
               ++it_row;
            }
            
            //std::cout << "check 5" << std::endl;

            node_check[node_num] = 1; //отметили i-ю вершину как пройденную
            //std::cout << "node_check[node_num] = " << node_check[node_num] << std::endl;
            //std::cout <<  "node_num = " << node_num << std::endl;

            node_check_flag = 1; // надеемся, что это был последний шаг алгоритма и подниманем флаг
            for (size_t k = 0; k < s.size(); ++k) // надежда умирает последней, поэтому проверяем на финал - если не достигли, опускаем флаг обратно
            {
                //std::cout << "node_check[" << k << "] = " << node_check[k] << std::endl;
                if (node_check[k] == 0)
                {
                    node_check_flag = 0;
                    break;
                }
            }
            //std::cout << "check 6" << std::endl;

            if (end_point_flag) //если флаг поднят, значит мы в вершине-листе и нам нужно хитро самим выбрать следующую вершину
            {
                weight_min = std::numeric_limits<int>::max(); // мы будем искать минимум по массиву length_check
                for (size_t k = 0; k < s.size(); ++k)
                {
                    //выбираем такую вершину, которая еще не пройдена, не изначальную и расстояние у которой минимальное
                    if ((node_check[k] == 0) && (length_check[k] != 0) && (weight_min > length_check[k])) 
                    {
                        node_next = k;
                        weight_min = length_check[k];
                    }
                }

            }

            //если не дошли до последнего шага, значит меняем тукущую вершину
            node_num = node_next;

        }
        //std::cout << "check 7" << std::endl;
        //алгоритм Дейкстры для i-й вершины завершен и массив length_check хранит все кратчайшие расстояния от i-й вершины
        // теперь подготовим всё необходимое, чтобы выполнить алгоритм для вершины i+1
        // и заодно проверим на максимальность max_length

        for (size_t k = 0; k < s.size(); ++k)
        {
            if (max_length < length_check[k]) //проверяем, что текущий максимум меньше кратчайшего расстояния от вершины i до вершины k
            {
                max_length = length_check[k];
            }
        }

        //std::cout << "check 8" << std::endl;

        for (size_t k = 0; k < s.size(); ++k)  // чистим 
        {
            length_check[k] = std::numeric_limits<int>::max();
            node_check[k] = 0;
        }
        //std::cout << "check 9" << std::endl;
    }
    //std::cout << "check 10" << std::endl;
    free(length_check); // не забываем освобождать массив
    free(node_check); // не забываем освобождать массив

    return max_length;
    
} 
