#include <stdio.h>
#include <math.h>

int main()
{
    int r, g, b;
    double w, c, m, y, k;
    char flag = 'y';

    while (flag == 'y')
    {
        printf("\nEnter value of color in r g b format: ");
        scanf("%d %d %d", &r, &g, &b);

        if (r == 0 && g == 0 && b == 0)
        {
            printf("colour in RGB: (%d,%d,%d)\n", r, g, b);
            printf("Colour in CMYK: (0,0,0,1)\n");
            printf("Want to convert another colour (y/n): ");
            scanf(" %c", &flag);
        }

        else if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
        {
            printf("Limit of rgb scale is 0 to 255\n");
            printf("Want to retry (y/n): ");
            scanf(" %c", &flag);
        }

        else
        {
            w = fmax(r / 255.0, fmax(g / 255.0, b / 255.0));
            c = (w - r / 255.0) / w;
            m = (w - g / 255.0) / w;
            y = (w - b / 255.0) / w;
            k = 1 - w;

            printf("colour in RGB: (%d,%d,%d)\n", r, g, b);
            printf("Colour in CMYK: (%.2lf,%.2lf,%.2lf,%.2lf)\n", c, m, y, k);
            printf("Want to convert another colour (y/n): ");
            scanf(" %c", &flag);
        }
    }
    return 0;
}
