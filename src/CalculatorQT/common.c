/* 
    Программа Smart_Calc_1.0 


    1. Функция infix_to_postfix(char* infix_input_str) конвертирует входную строку в строку
       записанную в обратной польской записи (из инфиксного вида в постфиксный).
        1.1 Функция create_lexem(char* infix_input_str) отделяет часть входной строки,
            как только встречает в ней символ-разделитель. Использовать в цикле.
        1.2 Функция sorting_station(char *lexem, CharStack *ops, char *output) частично реализует
            алгоритм Дейкстры "сортировочна станция" (подробное описание в файле README.md).

    3. Вычисление постфиксной записи функцией postfix_to_result(char* input_postfix_str),
    которая возвращает результат всего выражения типа double. 
 */

#include "smartcalc.h"


// int main(void) {
//     char *input_str = "2.0+2";
// /* ---------------- // INFIX TO POSTFIX // ------------ */
//     char *postfix_str = infix_to_postfix(input_str);
//     printf("postfix: %s\n", postfix_str);
// /* ---------------- // CALCULATION // ----------------- */
//     double result = postfix_to_result(postfix_str);
//     printf(" result: %f\n", result);

//     return 0;
// }


char* create_lexem(char* infix_input_str) {
/*
  По условию задачи надо учесть такие операции:
    
    сложение                    +
    вычитание                   -
    умножение                   *
    деление                     /
    возведение в степень        ^
    остаток от деления          m
    унарный минус               ~
    унарный плюс                TODO: выяснить про унарный плюс
    скобка открывающая          (
    скобка закрывающая          )

    косинус                     c           cos()
    синус                       s           sin()
    тангенс                     t           tg()
    арккосинус                  k           acos()
    арксинус                    i           asin()
    арктангенс                  a           atan()
    квадратный корень           q           sqrt()
    натуральный логарифм        n           ln()
    десятичный логарифм         o           log()

  Символ пробела нужен для разделения лексем в обратной польской записи 
*/     
    char* delimeters = "+-*/^m~()cstkiaqno ";
/*
  Функция strcspn(const char * string1, const char * string2) возвращает: 
     1. Количество символов до найденного первого вхождения.
     2. Длину строки string1, если ни один из символов строки string2 не входит в состав string1.
*/
    int next_lexem_start_index = strcspn(infix_input_str, delimeters);
/*
  Фунция void* malloc( size_t size ) выделяется куск непроинициализированной памяти
    // char* lexem = calloc(255, sizeof(char));
*/
    char* lexem = malloc(next_lexem_start_index * sizeof(char));

    if (lexem == NULL) {
        fputs("mem failure, exiting \n", stderr);
        exit(EXIT_FAILURE);
    }
/* 
  Алгоритм работы функции create_lexem():
    если индекс равен нулю (когда лексема состоит из одного символа)
        присвоить массиву чаров lexem символ из infix_input_str по такому же индексу
    иначе (если лексема из нескольких символов, например вещественное число)
        присвоить каждый символ от нуля до полученного индекса
*/
    if (!next_lexem_start_index) {
        lexem[next_lexem_start_index] = infix_input_str[next_lexem_start_index];

    } else {
        for (int i = 0; i < next_lexem_start_index; i++) {
            lexem[i] = infix_input_str[i];
        }
    }

    return lexem;
}


void sorting_station(char* lexem, CharStack* operations, char* output_str) {
/* 
  Подразумевается, что функция используется, пока следующая лексема существует.
  Задача сортировочной функции в том, что бы сформироваь обратную польскую запись.
  По окончанию работы функции все числа будут записаны в выходную строку, однако в стеке
  еще может оставаться какое-то количество операций.
  ____________________________________________________________
  TODO: разобраться, как обрабатывать это условие алгоритма
  Разделитель аргументов функции (например, запятая):
    1. Перекладываем операторы из стека в выходную очередь пока 
       лексемой на вершине стека не станет открывающая скобка. 
    2. Если в стеке не окажется открывающей скобки - в выражении 
       допущена ошибка.
*/
    char top = 0; // символ верхнего элемента стека

/* Если лексема - число, то добавляем в строку вывода */
    if (isdigit(*lexem)) {
        strcat(lexem, " ");
        strcat(output_str, lexem);
    }

/* Функция или открывающая скобка - помещаем в стек */
    if (*lexem == '(' || is_function(*lexem))
        char_stack_push(operations, *lexem);
/* 
  Закрывающая скобка:
    1. Пока лексема на вершине стека не станет открывающей скобкой, перекладываем 
       лексемы-операторы из стека в выходную очередь.
    2. Удаляем из стека открывающую скобку.
    3. Если лексема на вершине стека — функция, перекладываем её в выходную очередь.
*/
    if (*lexem == ')') {
        top = char_stack_peek(operations);
        while (top != '(') {
            char tmp[2] = {top, '\0'};
            strcat(output_str, tmp);
            char_stack_pop(operations);
            top = char_stack_peek(operations);
        }
        char_stack_pop(operations);

        top = char_stack_peek(operations);
        if (is_function(top)) {
            char tmp[3] = {top, ' ', '\0'};
            strcat(output_str, tmp);
            char_stack_pop(operations);
        }
    }
/* 
  Оператор (O1):
    1. Пока присутствует на вершине стека лексема-оператор (O2) чей приоритет 
       выше приоритета O1, либо при равенстве приоритетов O1 является левоассоциативным:
    2. Перекладываем O2 из стека в выходную очередь.
    3. Помещаем O1 в стек.
*/
    if (is_operator(*lexem)) {

        if (!char_stack_is_empty(operations))
            top = char_stack_peek(operations);

        while ((precendence(top) >= precendence(*lexem)) && (is_left_associative(*lexem))) {
            char tmp[3] = {top, ' ', '\0'};
            strcat(output_str, tmp);
            char_stack_pop(operations);
            if (operations->top == -1)
                break;
            top = char_stack_peek(operations);
        }
        char_stack_push(operations, *lexem);
    }
}

/* Проверяет является ли операция левоассоциативной */
int is_left_associative(char op) {
    if (op == '+' || op == '-' || op== '*' || op == '/' )
        return 1; 
    return 0;
}

/* Проверка символа на оператор */
int is_operator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == 'm')
        return 1;
    return 0;
}

/* Является ли текущий символ символом функции */
int is_function(char op) {
    if (op == 'c' || op == 's' || op == 't' || op == 'q' || op == 'n' ||
        op == 'o' || op == 'i' || op == 'a' || op == 'k')
        return 1;
    return 0;
}

/* Функция установки приоритета операции */
int precendence(char op) {
    // TODO: переписать под if else?
    int prec = 0;
    int int_val_op_prec = (int) op;
    switch (int_val_op_prec) {
        case '+':
            prec = 1;
            break;
        case '-':
            prec = 1;
            break;
        case '*':
            prec = 2;
            break;
        case '/':
            prec = 2;
            break;
        case '^':
            prec = 3;
            break;
        default:
            printf("No cases matched, no precendence applied to %d\n", prec);
    }

    return prec;
}


void calculation(char* lexem, DoubleStack* digits) {
/* 
  Это функция вычисления.
    TODO: доработаь ее с учитыванием всех недоработок, унарного минуса и функций
*/
    double lexem_atof = 0;
    double tmp_res = 0;
    double num1 = 0;
    double num2 = 0;

    if (isdigit(*lexem)) {
        lexem_atof = atof(lexem);
        double_stack_push(digits, lexem_atof);
    }
    
    if (is_operator(*lexem)) {
        num1 = double_stack_pop(digits);
        num2 = double_stack_pop(digits);
        tmp_res = binary_arithmetics(num1, num2, *lexem);
        double_stack_push(digits, tmp_res);
    }

    // if (is_function(*lexem)) {
    //     num1 = double_stack_pop(digits);
    //     tmp_res = unary_arithmetics(num1, *lexem);
    //     double_stack_push(digits, tmp_res);
    // }
}

double binary_arithmetics(double d1, double d2, double op) {
    double res = 0;
    int int_val_op_ar = (int) op;
    switch (int_val_op_ar) {
        case '+':
            res = d2 + d1;
            break;
        case '-':
            res = d2 - d1;
            break;
        case '*':
            res = d2 * d1;
            break;
        case '/':
            // TODO: check for division by zero
            res = d2 / d1;
            break;
        case 'm':
            // TODO: check for division by zero
            res = fmod(d2, d1);
            break;
        case '^':
            res = pow(d2, d1);
            break;
        default:
            printf("No cases matched, no arithmetics applied\n");
    }
    return res;
}

// double unary_arithmetics(double d1, double op) {
//     double res = 0;
//     int int_val_op_ar = (int) op;
//     switch (int_val_op_ar) {
//         case 'c':
//             res = cos(d1);
//             break;
//         case 's':
//             res = sin(d1);
//             break;
//         case 't':
//             res = tan(d1);
//             break;
//         case 'q':
//             res = sqrt(d1);
//             break;
//         case 'n':
//             res = log10(d1);
//             break;
//         case 'o':
//             res = log(d1);
//             break;
//         case 'i':
//             res = asin(d1);
//             break;
//         case 'a':
//             res = atan(d1);
//             break;
//         case 'k':
//             res = acos(d1);
//             break;
//         default:
//             printf("No cases matched, no arithmetics applied\n");
//     }
//     return res;
// }

char *infix_to_postfix(char *infix_input_str) {
/*
  Выделение памяти для выходной строки через malloc, проверка на NULL, инициализация памяти
  функцией memset(void *dest, int c, size_t n)
*/
    char *postfix_str = malloc(sizeof(char) * 255);
    if (postfix_str == NULL) {
        fputs("mem failure, exiting \n", stderr);
        exit(EXIT_FAILURE);
    }
    memset(postfix_str, 0, 255);

/*
  Создание стека чаров. Его потом передадим в функцию алгоритма сортировки. Файл satack.c
*/
    CharStack ops = {0};
    char_stack_create_empty(&ops);

/*
  Алгоритм функции infix_to_postfix() представляет собой два цикла:
    1. В первом цикле входная строка разделяется на лексемы, каждая из которых
    обрабатывается функцией sorting_station(), где символы операций кладутся в стек, а
    числа выводятся в выходную строку
*/
    for (int i = strlen(infix_input_str); i >= 0; i--) {
        if (strlen(infix_input_str) == 0) {
            break;
        }
        char *infix_element = create_lexem(infix_input_str);
        infix_input_str += strlen(infix_element);
        sorting_station(infix_element, &ops, postfix_str);
        free(infix_element);
    }
/*
    2. Во втором цикле в выходную строку записываются все оставшиеся в стеке операции
*/
    while(!char_stack_is_empty(&ops)) {
        double top = char_stack_peek(&ops);
        char tmp[2] = {top, '\0'};
        strcat(postfix_str, tmp);        
        char_stack_pop(&ops);
    }

    return postfix_str;
}


double postfix_to_result(char *input_postfix_str) {
/*
  Для вычисления выражения в обратной польской записи создется стек даблов, в который
  будут складываться числа из отделяемых лексем. 
*/
    DoubleStack digits = {0};
    double_stack_create_empty(&digits);
/* 
  Алгоритм копирует поведение функции infix_to_postfix(), но вместо сортировки
  выполняет функцию calculation(), которая выполняет операции над числами из стека.
  По итогу этого цикла в стеке даблов останется только одно число - результат.
*/
    for (int i = strlen(input_postfix_str); i >= 0; i--) {
        if (strlen(input_postfix_str) == 0) {
            break;
        }
        char *lexema = create_lexem(input_postfix_str);
        input_postfix_str += strlen(lexema);
        calculation(lexema, &digits);
        free(lexema);
    }

    return double_stack_pop(&digits);
}