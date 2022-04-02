#include <iostream> 
#include <chrono>

using namespace std;

int iteration = 1000;
static bool isfilled = false;
int cl = -1;
static int total_size = 1100;  

struct Node {
    int deger;
    Node* sonraki;
};
struct Linkedlist {
    Node* bas;
    void olustur();
    void ekle(int, int);
    void sil(int);
    void guncelle(int, int);
    void yazdir();
    void bosalt();
    int sayac;
};

struct ArrayList {
    int* bas = NULL; //dizinin baþlangýç adresini tutar
    void olustur(); //baþlangýç için gereken tanýmlarý içerir
    void ekle(int, int); //deðer ve sýra numarasý alarak ekleme yapar
    void guncelle(int, int);//deðer ve sýra numarasý alarak günceller
    void sil(int); //sýra numarasý alarak silme yapar
    void yazdir(); //liste içeriðini ekrana yazar
    void bosalt(); //listenin bellek alanlarýný iade eder
    int sayac = 0; //liste kaç eleman olduðunu tutar
};

int main()
{
    Linkedlist* ll = new Linkedlist();
    ArrayList* al = new ArrayList();

    al->olustur();
    ll->olustur();
    for (int i = 0;i < iteration;i++)
    {
        ll->ekle(i, i);
        al->ekle(i, i);
    }
    //cout << iteration << " item added" << endl;
    //cout << "linkedlist eleman sayisi > " << ll->sayac << endl;
    //cout << "dizi eleman sayisi > " << al->sayac << endl;
    cout << endl;
    cout << "\t"<<iteration << " elemanli listede" << endl;
    cout << endl;
    auto begin1 = std::chrono::high_resolution_clock::now();
    ll->ekle(666, 0);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto begin2 = std::chrono::high_resolution_clock::now();
    al->ekle(666, 0);
    auto end2 = std::chrono::high_resolution_clock::now();

    auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    cout << "\tDizi ile gerceklemede basa ekleme suresi => " << elapsed2.count() << " <= nano-saniye" << endl;
    cout << endl;
    cout << "\tBaglantili liste ile gerceklemede basa ekleme suresi => " << elapsed1.count() << " <= nano-saniye" << endl;
    cout << endl;
   
    //al->yazdir();
    cout << endl;
    //ll->yazdir();
    ll->bosalt();
    cout<<endl;
    /*ll->guncelle(666,500);
      al->guncelle(666,500);
      ll->sil(500);
      al->sil(500);*/
    return 0;

}


void Linkedlist::olustur() {
    bas = NULL;
}
void Linkedlist::yazdir() {
    Node* tara;
    tara = bas;
    if (!tara) {
        cout << "Liste bos!!!" << endl;
        return;
    }
    while (tara) {
        cout << tara->deger << " ";
        tara = tara->sonraki;
    }
    cout << endl;
}
void Linkedlist::ekle(int sayi, int pos) {
    if (pos > sayac) {
        pos = sayac;
    }
    Node* n = new Node();
    n->deger = sayi;
    n->sonraki = NULL;
    if (n == NULL) {
        cout << "hata" << endl;
    }
    if (pos < 0) {
        cout << "\neklenmesi gereken pozisyon 0dan büyük olmalý";
    }
    else if (pos == 0) {
        sayac++;
        n->sonraki = bas;
        bas = n;
    }
    else {
        sayac++;
        Node* temp = bas;
        for (int i = 1; i < pos; i++) {
            if (temp != NULL) {
                temp = temp->sonraki;
            }
        }
        if (temp != NULL) {
            n->sonraki = temp->sonraki;
            temp->sonraki = n;
        }
        else {
            cout << "hata" << endl;
        }
    }
}
void Linkedlist::sil(int yer) {
    if (yer < 0) {
        cout << "\n0'dan kucuk olamaz!";
    }
    else if (yer == 0 && bas != NULL) {
        Node* silinecek = bas;
        bas = bas->sonraki;
        free(silinecek);
    }
    else {
        Node* temp = bas;
        for (int i = 1; i < yer; i++) {
            if (temp != NULL) {
                temp = temp->sonraki;
            }
        }
        if (temp != NULL && temp->sonraki != NULL) {
            Node* silinecek = temp->sonraki;
            temp->sonraki = temp->sonraki->sonraki;
            free(silinecek);
        }
        else {
            cout << "\naralikta degil!!";
        }
    }
}
void Linkedlist::guncelle(int val, int hm) {
    Node* n = new Node();
    n->deger = val;
    Node* tara = new Node();
    int ab = 1;
    tara = bas;
    while (tara && (ab < hm)) {
        ab++;
        tara = tara->sonraki;
    }
    if (tara) {
        n->sonraki = tara->sonraki;
        *tara = *n;
    }
    else
        cout << "exception" << endl;
}
void Linkedlist::bosalt() {
    Node* p;
    while (bas) {
        p = bas;
        bas = bas->sonraki;
        delete p;
    }
}

void ArrayList::olustur() {
    bas = new int[total_size];
    cl = 1;
}
void ArrayList::ekle(int sayi, int pos) {
    if (total_size>pos) {
        isfilled = true;
        sayac++;
        for (int i = total_size;i > pos;i--)
            bas[i] = bas[i - 1];

        bas[pos] = sayi;
    }
    else
        cout << "hata" << endl;
}
void ArrayList::yazdir()
{
    if (isfilled==false)
        cout <<endl<< "list not filled" << endl;    
    else
        if (cl == -1)
            cout << "list is not created\n";
        else
            for (int i = 0;i < sayac;i++)
                cout << bas[i] << " ";
    
}
void ArrayList::guncelle(int yen, int pos) {
    if (total_size > pos) 
        bas[pos] = yen;
    
}
void ArrayList::sil(int sil) {
    for (int i = sil;i <= sayac - 1;i++)
    {
        bas[i] = bas[i + 1];
    }
    bas[sayac - 1] = {};
    sayac--;
}
void ArrayList::bosalt() {
    //free(bas);
}