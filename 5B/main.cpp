//
//  main.cpp
//  5B
//
//  Created by Елисей on 14.02.2020.
//  Copyright © 2020 Longjects. All rights reserved.
//

#include <stdio.h>
#include <locale.h>

#define printf_s printf
#define scanf_s scanf

struct list
{
    int value;
    list *prev, *next;

    list(int value, list *prev, list *next)
        : value(value), prev(prev), next(next)
    {}
};

list *input()
{
    int numberOfElements;
    int inputVar;
    
    printf_s("Введите количество элементов: ");
    scanf_s("%d", &numberOfElements);
    
    printf_s("Введите действительные числа: \n");
    scanf_s("%d", &inputVar);
    
    list *p, *b = new list(inputVar, NULL, NULL);
    p = b;
    
    while(numberOfElements > 1)
    {
        scanf_s("%d", &inputVar);
        b = new list(inputVar, b, NULL);
        b->prev->next = b;
        numberOfElements--;
    }

    return p;
}

list* list_end(list* l)
{
    while(l->next != NULL){ l = l->next; }
    return l;
}

int list_mult(list *expr)
{
    list *end = list_end(expr);

    int mult = 1;
    while(expr->next)
    {
        mult = mult * (expr->value + expr->next->value + 2 * end->value);
        expr = expr->next;
        end = end->prev;
    }

    return mult;
}

void print_list(list *expr)
{
    printf_s("Элементы списка: ");
    // вывод элементов списка
    while(expr)
    {
        printf_s("%d ", expr->value);
        expr = expr->next;
    }
    
    printf_s("\n");
}

int main()
{
    setlocale(LC_ALL, "Rus");
    list* expression = input();                 // ввод значений
    print_list(expression);                     // печать значений
    printf_s("%d\n", list_mult(expression));    // вывод ответа
    
    return 0;
}
