#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>



int sayi = 10;
struct node
{
    int veri;
    struct node *solnode; 
    struct node *sagnode;
};

   
struct node *nodeolustur(int veri)
{
    struct node *geciciptr =  (struct node*)malloc(sizeof(struct node));
    geciciptr->veri = veri;
    geciciptr->solnode = geciciptr->sagnode = NULL;
    return geciciptr;
}


struct node* ekleme(struct node* node, int veri)
{
    if (node == NULL)
        return nodeolustur(veri);
    
    if (veri < node->veri) node->solnode  = ekleme(node->solnode, veri);
    else if(veri > node->veri) node->sagnode = ekleme(node->sagnode, veri);   
    return node;
}


void Listeleme(struct node *kok, int bosluk) 
{ 
    if (kok == NULL) return;
    bosluk += sayi; 
    Listeleme(kok->sagnode, bosluk); 
    printf("\n"); 
    for (int i = sayi; i < bosluk; i++) 
        printf(" "); 
    printf("%d\n", kok->veri); 
    Listeleme(kok->solnode, bosluk); 
}

struct node * sirala(struct node* node)
{
    struct node* current = node;
    return current;
}

struct node* Silme(struct node* root, int veri)
{

    if (root == NULL) return root;
  
    if (veri < root->veri)
    {
        root->solnode = Silme(root->solnode, veri);
    }
  
    else if (veri > root->veri)
    {
        if (root->sagnode==NULL)
            return root;
        root->sagnode = Silme(root->sagnode, veri);
    }

    else
    {
        if (root->sagnode == NULL && root->solnode == NULL)
        {
            printf("lutfen gecerli bir sayi giriniz :  ");
        }

        if (root->solnode == NULL)
        {
            struct node *temp = root->sagnode;
            free(root);
            return temp;
        }
        else if (root->sagnode == NULL)
        {
            struct node *temp = root->solnode;
            free(root);
            return temp;
        }

  
        struct node* temp = sirala(root->solnode);
        root->veri = temp->veri;
        if(root->solnode!=NULL)
            root->solnode = Silme(root->solnode, temp->veri);

    }
    return root;
}



int main()
{   
    int kosul=3;
    do
    {
        struct node *kok = NULL;
        srand(time(NULL));
        printf("Siralanacak sayilar: ");
        for (int i = 0; i < 10; i++)
        {
            int n = rand() % 100 + 1;
            kok = ekleme(kok,n);
        }
        Listeleme(kok,0);
        int silinecekdeger;
        printf("agactan hangi elemani silmek istersiniz: ");
        scanf("%d",&silinecekdeger);
        kok = Silme(kok,silinecekdeger);
        printf("yeni liste : \n");
        Listeleme(kok,0);
        printf("devam etmek ister misiniz? evet(1) hayir(2)..");
        scanf("%d",&kosul);
    } while (kosul==1);
    

   
    return 0;
    getch();
}



