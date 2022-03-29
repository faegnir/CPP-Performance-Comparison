#include <iostream> 
#include <chrono>

using namespace std;

static int total_size;     
static bool isfilled = false;
// shows total size of list is zero
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
    int* bas = NULL; //dizinin baþlangýç adresini tutar
    void olustur(); //baþlangýç için gereken tanýmlarý içerir
    void ekle(int, int); //deðer ve sýra numarasý alarak ekleme yapar
    void guncelle(int, int);//deðer ve sýra numarasý alarak günceller
    void sil(int); //sýra numarasý alarak silme yapar
    void yazdir(); //liste içeriðini ekrana yazar
    void bosalt(); //listenin bellek alanlarýný iade eder
    void size();
   // int sayac; //liste kaç eleman olduðunu tutar
    int cs = 0;                                                 //shows that current size of list is zero
    int cl = -1;
};
int main()
{
    Linkedlist* ll = new Linkedlist();
    ArrayList* al = new ArrayList();
    int iteration = 100;

    /*ll->olustur();
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
    ll->ekle(31, 10);
    auto end1 = std::chrono::high_resolution_clock::now();
    ll->yazdir();
    auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    cout << endl;
    cout << "Baglantili liste ile gerceklemede araya ekleme suresi => " << elapsed1.count() << " <= mikro-saniye" << endl;
    */

    
    al->olustur();
    //al->yazdir();
    cout << endl;
   
    for (int i = 0;i < al->cs;i++) {
            al->ekle(i, i);
    }
    
    
    
    al->yazdir();
    al->size();
    cout << endl;
    al->ekle(31, 6);
    al->size();
    al->yazdir();

    //auto begin2 = std::chrono::high_resolution_clock::now();
    
   // auto end2 = std::chrono::high_resolution_clock::now();
    //auto elapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(end2-begin2);
    //cout<<"Dizi ile gerçeklemede araya ekleme süresi => "<<elapsed2.count()<<"mikro-saniye"<<endl;
    cout<<endl;
    return 0;

}
void Linkedlist::olustur() {
    bas = NULL;
}
/*void ArrayList::ekle(int x, int y) {
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

void ArrayList::olustur() {
    cout << "enter total size of list:";
    cin >> total_size;
    do
    {
        cout << "enter current size of list:";
        cin >> cs;
    } while (cs < 1 || cs >= total_size);
    bas = new int[total_size];              // dynamically creating array with size ‘0’
    cl = 1;
    
}
void ArrayList::ekle(int sayi, int pos) {
    if (cs > pos) {
        isfilled = true;

        bas[pos] = sayi;

        /*for (int i = cs;i >= pos;i--)
            bas[i] = bas[i-1];
        bas[pos] = sayi;
*/
    }
    /*else if (pos > cs && pos < total_size)
    {
        isfilled = true;

        bas[pos] = sayi;
    }*/
    else
        cout << "hata" << endl;
}
void ArrayList::yazdir()
{
    if (cs == 0)
        cout << "list is empty\n";
    else if (isfilled==false)
        cout <<endl<< "list not filled" << endl;    
    else
        if (cl == -1)
            cout << "list is not created\n";
        else
            for (int i = 0;i < cs;i++)
                cout << bas[i] << endl;
    
}
void ArrayList::size()
{

    cout << "current size of list is:" << cs << endl;
}