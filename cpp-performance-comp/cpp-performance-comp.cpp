#include <iostream> 
#include <chrono>

using namespace std;

void sonaEkle();
void basaEkle();
void ortayaEkle();

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
    int* bas; //dizinin baþlangýç adresini tutar
    void olustur(); //baþlangýç için gereken tanýmlarý içerir
    void ekle(int, int); //deðer ve sýra numarasý alarak ekleme yapar
    void guncelle(int, int);//deðer ve sýra numarasý alarak günceller
    void sil(int); //sýra numarasý alarak silme yapar
    void yazdir(); //liste içeriðini ekrana yazar
    void bosalt(); //listenin bellek alanlarýný iade eder
    int sayac; //liste kaç eleman olduðunu tutar
};
int main()
{
    Linkedlist* ll = new Linkedlist();
    int iteration = 20;
    ll->olustur();
    ll->yazdir();
    cout << "eleman sayisi > " << ll->sayac << endl;
    for (int i = 0;i < iteration;i++)
    {
        ll->ekle(i, i);
    }
    cout << iteration << " item added" << endl;
    //cout << "eleman sayisi > " << ll->sayac << endl;
    cout << iteration << " elemanli listede" << endl;
    cout << endl;
    auto begin1 = std::chrono::high_resolution_clock::now();
    ll->guncelle(31, 10);
    auto end1 = std::chrono::high_resolution_clock::now();
    ll->yazdir();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    cout << endl;
    cout << "Baglantili liste ile gerceklemede araya ekleme suresi => " << elapsed1.count() << " <= mikro-saniye" << endl;


    /*ArrayList* al = new ArrayList();
    al->olustur();

    for(int i = 0;i<iteration;i++){
        al->ekle(i,i);
    }
    auto begin2 = std::chrono::high_resolution_clock::now();
    al->ekle(10,9995);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2-begin2);
    cout<<"Dizi ile gerçeklemede araya ekleme süresi => "<<elapsed1.count()<<"mikro-saniye"<<endl;
    cout<<endl;*/
    return 0;

}
void Linkedlist::olustur() {
    bas = NULL;
}
/*void Linkedlist::ekle(int x, int y) {
    const int m = 25;
    int arr[m], i;
    for (i = 0; i < m; i++)
    {
        arr[i] = i;
    }
    for (i = m - 1; i > y; i--)
    {
        arr[i] = arr[i - 1];
    }
    if (m > y) {
        arr[y] = x;
    }
    cout << endl << "Yeni dizi:" << endl;
    for (i = 0; i < m; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
    cout << endl;
}*/
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
        Node* nodeToDelete = bas;
        bas = bas->sonraki;
        free(nodeToDelete);
    }
    else {
        Node* temp = bas;
        for (int i = 1; i < yer; i++) {
            if (temp != NULL) {
                temp = temp->sonraki;
            }
        }
        if (temp != NULL && temp->sonraki != NULL) {
            Node* nodeToDelete = temp->sonraki;
            temp->sonraki = temp->sonraki->sonraki;
            free(nodeToDelete);
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