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
    double value;
    list *prev, *next;

    list(double value, list *prev, list *next)
        : value(value), prev(prev), next(next)
    {}
};

list *input()
{
    int numberOfElements;
    double inputVar;
    
    printf_s("Введите количество элементов: ");
    scanf_s("%d", &numberOfElements);
    
    printf_s("Введите действительные числа: \n");
    scanf_s("%lf", &inputVar);
    
    list *p, *b = new list(inputVar, NULL, NULL);
    p = b;
    
    while(numberOfElements > 1)
    {
        scanf_s("%lf", &inputVar);
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

int main()
{
    setlocale(LC_ALL, "Rus");
    list* expression = input();                        // ввод значений
    printf_s("Ответ: %d\n", list_mult(expression));    // вывод ответа
    
    return 0;
}
