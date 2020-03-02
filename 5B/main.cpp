//
//  main.cpp
//  5B
//
//  Created by Елисей on 14.02.2020.
//  Copyright © 2020 Longjects. All rights reserved.
//

#include <stdio.h>
#include <locale.h>

#ifdef _WINDOWS
#define fprintf fprintf_s
#define fscanf fscanf_s
#endif

struct list
{
    double value;
    list *prev, *next;

    list(double value = 0, list *prev = NULL, list *next = NULL)
        : value(value), prev(prev), next(next)
    {}
};

list *input(const char *fileName)
{
    double inputVar;
    
    FILE *fIn = fopen(fileName, "r");
    fscanf(fIn, "%lf", &inputVar);

    list *p, *b = new list(inputVar);
    p = b;
    
    while(!feof(fIn))
    {
        fscanf(fIn, "%lf", &inputVar);
        b = new list(inputVar, b, p);
        b->prev->next = b;
    }

	p->prev = b;

    fclose(fIn);

    return p;
}

void output(const char *fileName, double result)
{
    freopen(fileName, "w", stdout);
    printf("%lf", result);
}

double list_mult(list *head)
{
	list *l = head;
    list *r = l->prev;

    double mult = 1;
    while(l->next->next != head)
    {
        mult = mult * (l->value + l->next->value + 2 * r->value);
        l = l->next;
        r = r->prev;
    }

    return mult;
}

int main()
{
    list* in = input("in.txt");
    double result = list_mult(in);
    output("out.txt", result);

    return 0;
}
