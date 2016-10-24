#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

float normao(float *v);
float calcvet(float *ve1, float *ve2);

int main(void){
    float vet1[5],E1[5];
    float vet2[5],proj1[5],U2[5],E2[5];
    float vet3[5],proj2[5],proj3[5],totproj[5],U3[2],E3[5];
    float vet4[5],proj4[5],proj5[5],proj6[5],totproj1[5],U4[2],E4[5];
    float vet5[5],proj7[5],proj8[5],proj9[5],proj10[5],totproj2[5],U5[2],E5[5];
    float u1=0,nm2=0,nm3=0,nm4=0,nm5=0,t=0,t1=0,t2=0,t3=0,t4=0,t5=0;
    float t6=0,t7=0,t8=0,t9=0;
    int i,j,e;

    vet1[0] = 1.000000; vet1[1] = 2.000000; vet1[2] = 3.000000; vet1[3] = 4.000000; vet1[4] = 5.000000;
    vet2[0] = 1.000000; vet2[1] = 2.000000; vet2[2] = 3.000000; vet2[3] = 4.000000; vet2[4] = 4.000000;
    vet3[0] = 1.000000; vet3[1] = 1.000000; vet3[2] = 3.000000; vet3[3] = 9.000000; vet3[4] = 3.000000;
    vet4[0] = 1.000000; vet4[1] = 1.000000; vet4[2] = 2.000000; vet4[3] = 4.000000; vet4[4] = 2.000000;
    vet5[0] = 1.000000; vet5[1] = 1.000000; vet5[2] = 1.000000; vet5[3] = 1.000000; vet5[4] = 1.000000;
//----------------------------------------------------------
    //U1
    u1 = normao(vet1);
    for(i=0; i<=4; i++){
        E1[i] = (vet1[i] / (sqrt(u1)));
    }
//----------------------------------------------------------
    //U2
    t = calcvet(vet1,vet2);
    for(i=0;i<=4;i++){
        proj1[i] = (t/u1)*(vet1[i]);
    }

    for(i=0;i<=4;i++){
        U2[i] = vet2[i] - proj1[i];
    }
    nm2 = normao(U2);
    for(i=0;i<=4;i++){
        E2[i] = (U2[i]/(sqrt(nm2)));
    }
//----------------------------------------------------------
    //U3
    //projeção U3 parte 1
    t1 = calcvet(vet1,vet3);
    for(i=0;i<=4;i++){
        proj2[i] = (t1/u1)*(vet1[i]);
    }
    //projeção U3 parte 2
    t2 = calcvet(U2,vet3);
    for(i=0;i<=4;i++){
        proj3[i] = (t2/nm2)*(U2[i]);
    }
    //Projeção parte 1 menos parte 2
    for(i=0;i<=4;i++){
        totproj[i] = proj2[i] - proj3[i];
    }
    for(i=0;i<=4;i++){
        U3[i] = vet3[i] - totproj[i];
    }
    nm3 = normao(U3);
    for(i=0;i<=4;i++){
        E3[i] = (U3[i]/(sqrt(nm3)));
    }
//-----------------------------------------------------------
    //U4
    //projeção U4 parte 1
    t3 = calcvet(vet1,vet4);
    for(i=0;i<=4;i++){
        proj4[i] = (t3/u1)*(vet1[i]);
    }
    //projeção U4 parte 2
    t4 = calcvet(U2,vet4);
    for(i=0;i<=4;i++){
        proj5[i] = (t4/nm2)*(U2[i]);
    }
    //projeção U4 parte 3
    t5 = calcvet(U3,vet4);
    for(i=0;i<=4;i++){
        proj6[i] = (t5/nm3)*(U3[i]);
    }
    //Projeção parte 1 menos parte 2 menos parte 3
    for(i=0;i<=4;i++){
        totproj1[i] = (proj4[i] - proj5[i] - proj6[i]);
    }
    for(i=0;i<=4;i++){
        U4[i] = vet4[i] - totproj1[i];
    }
    nm4 = normao(U4);
    for(i=0;i<=4;i++){
        E4[i] = (U4[i]/(sqrt(nm4)));
    }
//-----------------------------------------------------------
    //U5
    //projeção U5 parte 1
    t6 = calcvet(vet1,vet5);
    for(i=0;i<=4;i++){
        proj7[i] = (t6/u1)*(vet1[i]);
    }
    //projeção U5 parte 2
    t7 = calcvet(U2,vet5);
    for(i=0;i<=4;i++){
        proj8[i] = (t7/nm2)*(U2[i]);
    }
    //projeção U5 parte 3
    t8 = calcvet(U3,vet5);
    for(i=0;i<=4;i++){
        proj9[i] = (t8/nm3)*(U3[i]);
    }
    //projeção U5 parte 4
    t9 = calcvet(U4,vet5);
    for(i=0;i<=4;i++){
        proj10[i] = (t9/nm4)*(U4[i]);
    }
    //Projeção parte 1 menos parte 2 menos parte 3
    for(i=0;i<=4;i++){
        totproj2[i] = (proj7[i] - proj8[i] - proj9[i] - proj10[i]);
    }
    for(i=0;i<=4;i++){
        U5[i] = vet5[i] - totproj2[i];
    }
    nm5 = normao(U5);
    for(i=0;i<=4;i++){
        E5[i] = (U5[i]/ (sqrt(nm5)));
    }
//-----------------------------------------------------------
    //Exibe resultados
    printf("--------------\n");
    for(i=0; i<=4; i++){
        printf("%f\n",E1[i]);
    }
    printf("--------------\n");
    for(i=0; i<=4; i++){
        printf("%f\n",E2[i]);
    }
    printf("--------------\n");
    for(i=0; i<=4; i++){
        printf("%f\n",E3[i]);
    }
    printf("--------------\n");
    for(i=0; i<=4; i++){
        printf("%f\n",E4[i]);
    }
    printf("--------------\n");
    for(i=0; i<=4; i++){
        printf("%f\n",E5[i]);
    }
  }

float normao(float *v){
    float nm[5];
    float ant = 0;
    int ni = 0;
    for(ni=0; ni<=4; ni++){
        nm[ni] = v[ni]*v[ni];
    }
    for(ni=0; ni<=4; ni++){
        ant = ant + nm[ni];
    }
    return ant;
}

float calcvet(float *ve1, float *ve2){
    float aux[5];
    float t = 0;
    int i;
    for(i=0;i<=4;i++){
        aux[i] = ve2[i] * ve1[i];
    }
    for(i=0;i<=4;i++){
        t = t + aux[i];
    }
    return t;
}
