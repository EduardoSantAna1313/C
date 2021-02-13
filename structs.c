#include <stdio.h>
#include <math.h>

typedef void (* dist) (struct Point *, struct Point *);

typedef struct {
	
	double x;
	double y;

	dist d;

} Point;

void distance(Point *p1, Point *p2)
{

	double d1 = pow (p2-> x - p1 -> x, 2);
	double d2 = pow (p2-> y - p1 -> y, 2);

	double dist = sqrt (d1 + d2);
    printf("Distance: %.2f\n", dist );
}


void d2(Point *p1, Point *p2)
{

	double d1 = sqrt (p2-> x - p1 -> x);
	double d2 = sqrt (p2-> y - p1 -> y);

	double dist = pow (d1, d2);
    printf("Distance: %.2f\n", dist );
}

int main () {
	

	Point p1;
	p1.x = 0;
	p1.y = 0;

	Point p2;
	p2.x = 10;
	p2.y = 0;

	
    p1.d = &distance;
    p1.d(&p1, &p2);

    p2.d = &d2;
    p2.d(&p1, &p2);

	return 0;
}