#include <stdio.h>
#include<math.h>

void main()
{
    int p=500000,t=10,r=2;
    float SI,CI,CIHY,CIQ,CIM,CID,a,b,c,d,e;
    SI = (p*t*r)/100;
    a = 1+(r/100);
    CI = p*pow(a,t);
    b = 1+ (r/200);
    CIHY = p*pow(b,2*t);
    c = 1 + (r/400);
    CIQ = p* pow(c,4*t);
    d = 1 + (r/1200);
    CIM = p * pow(d, 12*t);
    e = 1+ (r/36500);
    CID = p * pow(e, 365 * t);
    printf("Simple interest = %f\n", SI);
    printf("Compound interest annually= %f\n", CI);
    printf("Compound interest half yearly= %f\n", CIHY);
    printf("Compound interest quarterly= %f\n", CIQ);
    printf("Compound interest monthly= %f\n", CIM);
    printf("Compound interest daily= %f\n", CID);
}
