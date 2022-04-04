#include <stdio.h>
#include "figures.h"
#include <math.h>

double volume_parall(struct parall p) {
    double v = p.a * p.b * p.h;
    return v;
}

double volume_cilindr(struct cilindr c) {
    double v = 3.14 * (c.r * c.r) * c.h;
    return v;
}

double volume_sphere(struct sphere s) {
    double v = (4/3) * 3.14 * s.r * s.r * s.r;
    return v;
}

double volume_tr_prisme(struct tr_prisme t) {
    double v = (sqrt(3)/4) * t.a * t.a * t.h;
    return v;
}

double volume_kv_pir(struct kv_pir k) {
    double v = k.a * k.a * ((1/3) * k.h);
    return v;
}
