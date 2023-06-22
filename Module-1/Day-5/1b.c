#include <stdio.h>
#include <stdlib.h>

struct Box {
    double length;
    double width;
    double height;
};

void calculateVolumeAndSurfaceArea(struct Box* box) {
    double volume = box->length * box->width * box->height;
    double surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
    
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box* boxPtr = (struct Box*)malloc(sizeof(struct Box));
    printf("Enter length: ");
    scanf("%lf", &(boxPtr->length));
    
    printf("Enter width: ");
    scanf("%lf", &(boxPtr->width));
    
    printf("Enter height: ");
    scanf("%lf", &(boxPtr->height));
    calculateVolumeAndSurfaceArea(boxPtr);
    double length = (*boxPtr).length;
    double width = (*boxPtr).width;
    double height = (*boxPtr).height;
    printf("Length: %.2f\n", length);
    printf("Width: %.2f\n", width);
    printf("Height: %.2f\n", height);
    free(boxPtr);
    
    return 0;
}
