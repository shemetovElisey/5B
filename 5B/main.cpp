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
#define printf_s printf
#define scanf_s scanf
#endif

struct list
{
    double value;
    list *prev, *next;

    list(double value, list *prev, list *next)
        : value(value), prev(prev), next(next)
    {}
};

list *input(const char *fileName)
{
    double inputVar;
    
	FILE *fIn = fopen(fileName, "r");
	fscanf( fIn, "%lf", &inputVar );

    list *p, *b = new list(inputVar, NULL, NULL);
    p = b;
    
    while(fscanf( fIn, "%lf", &inputVar ))
    {
        b = new list(inputVar, b, NULL);
        b->prev->next = b;
    }

	fclose(fIn);

    return p;
}

void output( const char *fileName, double result )
{
	freopen(fileName, "w", stdout);
	printf("%lf", result);
}

list* list_end(list* l)
{
	for(;l->next; l = l->next){}
    //while(l->next != NULL){ l = l->next; }
    return l;
}

double list_mult(list *expr)
{
    list *end = list_end(expr);

    double mult = 1;
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
    list* in = input("input.txt");
	double result = list_mult(in);
	output( "output.txt", result );

    return 0;
}
