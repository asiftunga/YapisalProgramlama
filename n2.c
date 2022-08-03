#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

void sirala(int dizi[],int,int);
int parcalama(int dizi[],int,int);
int dizielemansayisi;
int main()
{
   int a,y,t;

    printf("Lutfen dizinin boyutunu giriniz : ");
    scanf("%d",&dizielemansayisi);
    int dizi[dizielemansayisi];
    for(a=0;a<dizielemansayisi;a++)
    {
        printf("Lutfen dizinin %d. elemanini giriniz : ",a+1);
        scanf("%d",&dizi[a]);
    }
    printf("Algoritma calismadan once : ");
    for(y=0;y<dizielemansayisi;y++)
    {
        printf(" %d",dizi[y]);
    }
    sirala(dizi,0,dizielemansayisi-1);
    printf("\nAlgoritma calistiktan sonra dizi : ");
    for(t=0;t<dizielemansayisi;t++)
    {   
        printf(" %d",dizi[t]);
    }
    getch(); 

void sirala(int dizi[],int basindex,int sonindex)
{
    if (basindex<sonindex)
    {
        int parcalamaindex = parcalama(dizi,basindex,sonindex);
        sirala(dizi,basindex,parcalamaindex-1);
        sirala(dizi,parcalamaindex+1,sonindex);
    }
}

int parcalama(int dizi[],int basindex,int sonindex)
{
    int pivot,parcalamaindex,i;
    parcalamaindex=basindex;
    pivot=dizi[sonindex];
    for (i = basindex; i < sonindex; i++)
    {
        if (dizi[i]<=pivot)
        {
            int temp1 = dizi[i];
            dizi[i] = dizi[parcalamaindex];
            dizi[parcalamaindex] = temp1;
            parcalamaindex=parcalamaindex+1;
        }
    }
    int temp = dizi[parcalamaindex];
    dizi[parcalamaindex] = dizi[sonindex];
    dizi[sonindex] = temp;
    return parcalamaindex;
}