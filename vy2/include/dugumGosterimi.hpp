/**       
* G231210081-ağaç ödevi  
* programım çalıştırıldığında ekrana 3 satırlık 15 adet düğüm gelir. Düğümlerin ilk satırında kendi adresleri, ikinci satırında tuttukları veri 
ve son satırında kendisinden sonraki düğümün adresi yer alır. Her bir düğümün tuttuğu veri, agaclar.txt dosyasındaki her bir satırın, satırı
oluşturan terimlerin ASCII değerleri baz alınarak oluşturulmuş bir ikili arama ağacına göre, parentından sola doğru dallanmış terimlerin ASCII 
değerlerinin 2 katlarını ve sağa dallanmış terimlerin ise direkt ASCII değerlerini alarak oluşan toplamdır. 15 adet düğüm vardır. n. düğüm 
txt dosyasındaki n. satırın ağacının verisini barındırır. D tuşuna basıldığında düğümler  arasında sağa doğru gezinebiliriz. A tuşuna 
bastığımızdaysa  düğümler arasında sola doğru gezebiliriz. S tuşu bir düğümü siler ve silinen düğümün barındırdığı adresler kendisinden sonraki 
düğüme geçer. Her geçiş veya siliniş sırasında ağaç çizimleri tekrar ekrana gelir ve her seferinde tüm ağaç çizimleri gösterilir.
 
* 1. öğretim C grubu
* 2. ödev  
* kodu yazmayı bitirdiğim tarih: 24/12/2024  
* Zeynep Bayraktar  zeynep.bayraktar5@ogr.sakarya.edu.tr    
*/

#ifndef dugumGosterimi_hpp 
#define dugumGosterimi_hpp

#include<iostream> 

class dugumGosterimi
{
    public:

    void cizgiYaz();
    void isaretYaz(int indeks, int offset);
    void cizgiArasiDegerYaz(int deger);
    void birSatirCiz(int baslangic, int bitis);
    void bagliListeYaz(int liste[], int boyut, int baslangic, int bitis, int toplamlar[]);
    

};

#endif