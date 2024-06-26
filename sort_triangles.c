#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double area(triangle tr) {
    double p = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));
}

int compare(const void *a, const void *b) {
    triangle *t1 = (triangle*) a;
    triangle *t2 = (triangle*) b;
    double area1 = area(*t1);
    double area2 = area(*t2);
    if (area1 > area2) {
        return 1;
    } else if (area1 < area2) {
        return -1;
    } else {
        return 0;
    }
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(struct triangle), compare);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = (struct triangle*)malloc(n * sizeof(struct triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
/* input :
5(no of triangles)
1 2 3 (their sides)
4 5 5
You are given n triangles, specifically, their sides ai, bi and ci. Print them in the same style but sorted by their areas from the smallest one to the largest one. It is guaranteed that all the areas are different

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
.*/