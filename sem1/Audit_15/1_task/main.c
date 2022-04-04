#include <stdio.h> 
#include "figures.h"
int main (void) {
    char symb = 'o';
    printf("Welcome to figures calculator\n");
    while (symb != '0') {
        printf("Which figure's size you wanna calculate:\n1.Parallelepiped\n2.Cilindr\n3.Sphere\n4.Triangle prisme\n5.Square pyramid\n0.Exit\n");
        do {
            scanf("%c", &symb);
        } while (symb == '\n');        
        if (symb == '1') {
            printf("Enter two sides and height\n");
            struct parall p;
            scanf("%lf", &p.a);
            scanf("%lf", &p.b);
            scanf("%lf", &p.h);
            double volume = volume_parall(p);
            printf("Volume of parall is %g\n", volume);

        }
        if (symb == '2') {
            printf("Enter radius and height\n");
            struct cilindr c;
            scanf("%lf", &c.r);
            scanf("%lf", &c.h);
            double volume = volume_cilindr(c);
            printf("Volume of cilindr is %g\n", volume);
        }
        if (symb == '3') {
            printf("Enter radius\n");
            struct sphere s;
            scanf("%lf", &s.r);
            double volume = volume_sphere(s);
            printf("Volume of sphere is %g\n", volume);
        }
        if (symb == '4') {
            printf("Enter side and height\n");
            struct tr_prisme t;
            scanf("%lf", &t.a);
            scanf("%lf", &t.h);
            double volume = volume_tr_prisme(t);
            printf("Volume of triangle prisme is %g\n", volume);
        }
        if (symb == '5') {
            printf("Enter side and height\n");
            struct kv_pir k;
            scanf("%lf", &k.a);
            scanf("%lf", &k.h);
            double volume = volume_kv_pir(k);
            printf("Volume of square pyramid is %g\n", volume); 
        }
    }
    
    return 0;

}
