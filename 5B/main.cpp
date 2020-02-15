//
//  main.cpp
//  5B
//
//  Created by Елисей on 14.02.2020.
//  Copyright © 2020 Longjects. All rights reserved.
//

#include <iostream>
#include <stdio.h>

struct list {
	int v;
	list *p, *n;

	list( int value, list *prev, list *next ) 
		: v(value), p(prev), n(next)
	{}
};

list *input() {
	int in;
	scanf( "%d", &in );
	list *p, *b = new list( in, NULL, NULL );
	p = b;

	scanf( "%d", &in );
	while( in > 0 ) {
		b = new list( in, b, NULL );
		b->p->n = b;

		scanf( "%d", &in );
	}

	return p;
}

list* list_end(list* l) {
	while(l->n != NULL){ l = l->n; }
	return l;
}

int list_mult(list *l) {
	list *end = list_end(l);

	int mult = 1;
	while(l->n) {
		mult = mult * (l->v + l->n->v + end->v);
		l = l->n;
		end = end->p;
	}

	return mult;
}

void print_list(list *l) {
	while(l) {
		printf( "%d ", l->v );
		l = l->n;
	}
	printf("\n");
}

int main() {
    list* l = input();
	print_list(l);
	printf( "%d\n", list_mult(l) );
    return 0;
}
