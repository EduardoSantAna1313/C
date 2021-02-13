/*
 * gcc strucst.c -o structs
 * ./structs
 */
#include <stdio.h>
#include <math.h>

typedef double (* dist) (struct Point *, struct Point *);

typedef struct {
	
	double x;
	double y;

	dist d;

} Point;

double distance(Point *p1, Point *p2)
{

	double d1 = pow (p2-> x - p1 -> x, 2);
	double d2 = pow (p2-> y - p1 -> y, 2);

	double dist = sqrt (d1 + d2);
    return dist;
}


double d2(Point *p1, Point *p2)
{

	double d1 = sqrt (p2-> x - p1 -> x);
	double d2 = sqrt (p2-> y - p1 -> y);

	double dist = pow (d1, d2);
	return dist;
}

int main () {
	

	Point p1;
	p1.x = 0;
	p1.y = 0;

	Point p2;
	p2.x = 10;
	p2.y = 0;

	
    p1.d = &distance;
	printf("Distance p1: %.2f\n\n", p1.d(&p1, &p2));

    p2.d = &d2;
    printf("DIstance p2: %.2f\n\n", p2.d(&p1, &p2));

	return 0;
}