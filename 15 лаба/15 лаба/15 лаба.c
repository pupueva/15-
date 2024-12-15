//15 лаба
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// 1.1 Создание двумерного массива, заполненного случайными вещественными числами
void create_and_fill_array(double array[100][100], int rows, int cols) {
    srand(time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = (double)rand() / RAND_MAX * (j + 1 - i) + i; // Случайное вещественное число в интервале [i, j+1]
        }
    }
}

// 1.2 Печать двумерного массива с индексами
void print_array(double array[100][100], int rows, int cols) {
    printf("  ");
    for (int j = 0; j < cols; j++) {
        printf("  %5d", j);
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("%2d", i);
        for (int j = 0; j < cols; j++) {
            printf(" %6.2f", array[i][j]);
        }
        printf("\n");
    }
}

// 1.3 Вывод элемента из второй строки
void print_element_in_second_row(double array[100][100]) {
    printf("Элемент из второй строки (первый элемент второй строки): %.2f\n", array[1][0]);
}

// 1.4 Нахождение максимального элемента в указанном столбце
void find_max_in_column(double array[100][100], int rows, int col) {
    double max_value = array[0][col];
    for (int i = 1; i < rows; i++) {
        if (array[i][col] > max_value) {
            max_value = array[i][col];
        }
    }
    printf("Максимальный элемент в столбце %d: %.2f\n", col, max_value);
}




// 2.1 Создание и заполнение двумерного массива целых чисел от -10 до 10
void create_and_fill_int_array(int array[7][7]) {
    srand(time(0));
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            array[i][j] = rand() % 21 - 10;
        }
    }
}

// 2.2 Печать целого массива
void print_int_array(int array[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}

// 2.3 Транспонирование двумерного массива
void transpose_array(int array[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
}

// 2.4 Подсчёт ненулевых элементов первой строки
void count_non_zero_elements_in_first_row(int array[7][7]) {
    int count = 0;
    for (int j = 0; j < 7; j++) {
        if (array[0][j] != 0) {
            count++;
        }
    }
    printf("Количество ненулевых элементов в первой строке: %d\n", count);
}

// 2.5 Поиск одинаковых соседних элементов
void count_adjacent_pairs(int array[7][7]) {
    int count = 0;
    // В строках
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if (array[i][j] == array[i][j + 1]) {
                count++;
            }
        }
    }
    // В столбцах
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (array[i][j] == array[i + 1][j]) {
                count++;
            }
        }
    }
    printf("Количество пар одинаковых соседних элементов: %d\n", count);
}

// 2.6 Нахождение максимального элемента и его координат
void find_max_coordinates(int array[7][7]) {
    int max_value = array[0][0];
    int max_i = 0, max_j = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (array[i][j] > max_value) {
                max_value = array[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    printf("Максимальный элемент: %d с координатами [%d][%d]\n", max_value, max_i, max_j);
}



// 3.1 Подсчёт среднего количества учеников по параллелям
void calculate_average_students(int students[12][4]) {
    for (int i = 0; i < 12; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += students[i][j];
        }
        double average = sum / 4.0;
        printf("Среднее количество учеников в %d-й параллели: %.2f\n", i + 1, average);
    }
}

int main() {

    setlocale(LC_CTYPE, "RUS");
    // Задание 1
    double array[100][100];
    int rows, cols, column_to_find_max;
    printf("Введите количество строк и столбцов: ");
    scanf("%d %d",&rows, &cols);
    create_and_fill_array(array, rows, cols);
    print_array(array, rows, cols);
    print_element_in_second_row(array);
    printf("Введите номер столбца для поиска максимума: ");
    scanf("%d",&column_to_find_max);
    find_max_in_column(array, rows, column_to_find_max);

    // Задание 2
    int int_array[7][7];
    create_and_fill_int_array(int_array);
    printf("\nИсходный массив:\n");
    print_int_array(int_array);
    count_non_zero_elements_in_first_row(int_array);
    count_adjacent_pairs(int_array);
    find_max_coordinates(int_array);
    transpose_array(int_array);
    printf("\nТранспонированный массив:\n");
    print_int_array(int_array);

    // Задание 3
    int students[12][4];
    printf("\nВведите количество учеников в 12 параллелях по 4 класса в каждой:\n");
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Ученики в %d-м классе %d-й параллели: ", j + 1, i + 1);
            scanf("%d",&students[i][j]);
        }
    }
    calculate_average_students(students);

    return 0;
}
