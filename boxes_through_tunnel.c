
  /*
Boxes through a Tunnel HackerRank
You are transporting some boxes through a tunnel, where each box is a parallelepiped, and is characterized by its length, width and height.

The height of the tunnel 41 feet and the width can be assumed to be infinite. A box can be carried through the tunnel only if its height is strictly less than the tunnel’s height. Find the volume of each box that can be successfully transported to the other end of the tunnel. Note: Boxes cannot be rotated.

Input Format
The first line contains a single integer n, denoting the number of boxes.

n lines follow with three integers on each separated by single spaces – length i, width i and height i which are length, width and height in feet of the i-th box.

Constraints
1 <= n <= 100

1 <= length i ,width i , height i <= 100

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
    int length;
    int width;
    int height;
};

typedef struct box box;

int get_volume(box b) {
	/**
	* Return the volume of the box
	*/
    return b.length * b.width * b.height;
}

int is_lower_than_max_height(box b) {
	/**
	* Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
	*/
    if (b.height < MAX_HEIGHT) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes =(struct box*) malloc(n * sizeof(struct box));
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}