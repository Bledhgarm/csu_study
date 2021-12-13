#include <stdio.h>

struct parall {
    double a;
    double b;
    double h;

};

struct cilindr {
    double r;
    double h;

};

struct sphere {
    double r;
};

struct tr_prisme {
    double a;
    double h;
};

struct kv_pir {
    double a;
    double h;
};

double volume_parall(struct parall p);
double volume_cilindr(struct cilindr c);
double volume_sphere(struct sphere s);
double volume_tr_prisme(struct tr_prisme t);
double volume_kv_pir(struct kv_pir k);
