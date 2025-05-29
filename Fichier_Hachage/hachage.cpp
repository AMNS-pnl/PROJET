
#include"hachage.h"
Tablehachage::Tablehachage(int n){
    nmax=n;
    nb_courant=0;
    tab=new bucket*[nmax];
    for(int i=0;i<nmax;i++){
        tab[i]=nullptr;
    }
}
Tablehachage::~Tablehachage(){
    for(int i=0;i<nmax;i++){
        bucket *courant=tab[i];
        while(courant!=nullptr){
                bucket *suiv=courant->suiv;
            delete courant->m;
            delete courant;
            courant=suiv;

        }
    }

}
void Tablehachage::insertion(string &cl,Maison*mais){
   unsigned int i=f1(cl) ;
   bucket*M=new bucket;
   M->m=new Maison;
   M->m->cle=mais->cle;
   M->m->description=mais->description;
   M->m->nb_chambres=mais->nb_chambres;
   M->m->nb_toilettes=mais->nb_toilettes;
   M->m->photo=mais->photo;
   M->m->standing=mais->standing;
   M->m->type =mais->type;
   M->suiv=nullptr;
   M->suiv=tab[i];
   tab[i]=M;
   nb_courant++;
}
Maison*Tablehachage::get(string&cl){
    unsigned int i=f1(cl);
    if(tab[i]==nullptr){
        return nullptr;
    }
    bucket *temp=tab[i];
    while((temp!=nullptr )&&(temp->m->cle!=cl)){
        temp=temp->suiv;
    }
    if(!temp){
        return temp->m;

    }
    return nullptr;
    
}
void Tablehachage:: suppression(string& cl){
     unsigned int i=f1(cl);
    if(tab[i]==nullptr){
        cerr<<"Erreur:suppression impossible";
        exit(1);
    }
    bucket *p,*temp=tab[i];
    while((temp!=nullptr )&&(temp->m->cle!=cl)){
       p=temp;
        temp=temp->suiv;
    }
    if(!temp){
        p->suiv=temp->suiv;
        delete temp->m; 
        delete temp;
    }
    
}
