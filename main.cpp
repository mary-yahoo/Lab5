#include <iostream>
#include "header.hh"

void ZAD4(element *p) {
    printf("Name\tA\t  Z density \n");
    for (int q = 0; q < 10; q++) {
        printf("%2s\t%4.1f\t%3d\t%.3f\n", p->name, p->A, p->Z, p->density);
        p++;
    }printf("\n");
}
void ZAD5(element *p, element *k){
    int l=0;
    double otn=0;
    printf("Name\tA\t  Z density \n");
    for (int i = 0; i < 10; i++) {
        otn=(p[i].A)/(p[i].Z);
        if (otn>2.2){
            k[l]=p[i];
            printf("%2s\t%4.1f\t%3d\t%.3f\n", k[l].name, k[l].A, k[l].Z, k[l].density);
            l++;
        }
    }
}
void ZAD6(element *p, element *r){
    printf("Sortirovka po zarydu\n");
    for (int i = 0; i < 10; i++) {
        r[i]=p[i];
    }
    element min=r[0];
    int l=0;
    for(int j=0;j<10;j++) {
        for (int k = 0; k < 9; k++) {
            if (r[k].Z > r[k+1].Z) {
                min= r[k+1];
                r[k+1] = r[k];
                r[k] = min;
            }
        };
    }
    printf("Name\tA\t  Z density \n");
    for (int q = 0; q < 10; q++) {
        printf("%2s\t%4.1f\t%3d\t%.3f\n", r[q].name, r[q].A, r[q].Z, r[q].density);
    }printf("\n");

}
//void ZAD9(element *p, element *k, element *r){
  //  free(k);
    //free(r);
    //free(p);
//}
int main() {
    element A[10];
    for (int i = 0; i < 10; i++) {
        A[i].Z = rand()%101;
        //printf("A[%d] = %d\n", i, A[i].Z);
    }
    A[0]={"Ge", 72.6, 32, 5.323};
    A[1]=A[0];
    A[2]={"Xe", 131.3, 54, 0.006};
    A[3]={"Mg", 24.3, 12, 1.738};
    A[4]={"Te", 127.6, 52, 6.24};
    A[5]={"Ba", 137.2, 56, 3.5};
    A[6]={"O", 16.0, 8, 1.141};
    A[7]={"Zn", 65.4, 30, 7.133};
    A[8]={"Ru", 101.1, 44, 12.41};
    A[9]={"Pu", 244, 94, 19.84};

    element *p = &A[0];

    ZAD4(p);
    element *k=(element *)calloc(sizeof(A[0]),7);
    ZAD5(p, k);
    element *r=(element *)calloc(sizeof(A[0]), 10);
    ZAD6(p, r);
    //ZAD9(p, k, r);
    return 0;
}