/* Computes the dimensional weight of a 12"x10"x8" box */
#include <stdio.h>
int main(void) {
int height, length, width, volume;
height = 8;
length = 1;
width = 10;

volume = height * length * width;
// weight = (volume + 165) / 166;
printf("Dimensions: %dx%dx%d\n", length, width, height);
printf("Volume (cubic inches): %d\n", volume);
printf("Dimensional weight (pounds): %d\n", ((volume + 165)/166));
return 0;
}