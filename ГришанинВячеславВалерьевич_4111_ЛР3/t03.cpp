// Лабораторная работа № 3
// Двумерные массивы
// Ввести размер прямоугольной матрицы и значения ее элементов.
// 3. Заполнить матрицу числами Фибоначчи из сегмента [с, d], записанными в порядке возрастания.
// Нечетные столбцы заполнять снизу-вверх,  четные сверху-вниз. Границы сегмента с и d вводятся с клавиатуры.

/*
      Re: Лабораторное занятие. Подгруппа 1
      от Нина Викторовна Комлева - Понедельник, 18 Май 2020, 15:33
      Можно понимать и так. Здесь имелась в виду более простая постановка задачи,
      а общий заголовок ко всем задачам "Ввести размер прямоугольной матрицы и значения ее элементов"
      здесь применим только к размерам матрицы. Можно значения элементов матрицы не вводить, а сразу генерировать ее,
      заполняя числами Фибоначчи. При этом можно даже предположить, что чисел для заполнения хватает.
*/
// Предположим, что в задании в задании подразумевалось, что нужно получить матрицу от пользователя и
// после этого заменить значения ее элементов на числа Фибоначчи из сегмента [с, d], записанными в порядке
// возрастания. Нечетные столбцы перезаписывать снизу-вверх,  четные сверху-вниз. Границы сегмента с и d вводятся
// с клавиатуры. Если чисел Фибоначчи  из сегмента [c, d] меньше числа элементов введенной матрицы, то значения оставшихся
// элементов матрицы остаются неизменными.  Если чисел Фибоначчи  в сегменте [c, d] больше числа элементов введенной матрицы,
// то в матрицу записываются только (числоСтрокМатрицы * числоСтолбцовМатрицы) первых чисел Фибоначчи из сегмента [c, d].

// В тексте задания нет информации о том какие значения вводятся. Предположим, что вводятся
// целые числа в диапазоне [INT_MIN; INT_MAX]. Неопределенно как вводятся значения элементов матрицы,
// предположим что ввод происходит последовательно по строкам.
#include <iostream>
void getInt(int&, std::string);
bool isFibonacci(int);
int main()
{
    int rowCount, columnCount;
    int** matrix;
    int c, d;
    getInt(c, "c");
    getInt(d, "d");
    getInt(rowCount, "rowCount");
    getInt(columnCount, "columnCount");
    std::cout << "matrix values:\n";
    if (c > d)
    {
        int temp = c;
        c = d;
        d = c;
    }
    matrix = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        matrix[i] = new int[columnCount];
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < columnCount; j++)
            std::cin >> matrix[i][j];
    {
        bool numOneInserted = false;
        for (int j = 0, iter = c-1; j < columnCount; j++)
            for (int i = 0; i < rowCount; i++)
            {
                if (iter == 2 and !numOneInserted)
                {
                    numOneInserted = true;
                    iter = 1;
                }
                while (!isFibonacci(++iter));
                if (iter > d)
                    goto BREAK_OUTER_FOR_LABEL;
                matrix[((j + 1) % 2) ? rowCount - 1 - i : i][j] = iter++;
            }
        BREAK_OUTER_FOR_LABEL:;
    }
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}
void getInt(int& varRef, std::string varName)
{
    std::cout << varName << ": ";
    std::cin >> varRef;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool isFibonacci(int num)
{
    int n1 = 1, n2 = 1;
    while (n2 < num)
    {
        int temp = n2;
        n2 += n1;
        n1 = temp;
    }
    return (n2 == num);
}
