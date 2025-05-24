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

#include "dugumGosterimi.hpp"
#include <iostream>
#include <iomanip>


int boslukMiktari = 5;
void dugumGosterimi::cizgiYaz()
{
    
    for(int i=0;i<boslukMiktari;i++)
        std::cout<<" ";
    std::cout<<"********";
}

void dugumGosterimi::isaretYaz(int indeks, int offset) //kaçıncı indekste ise oraya yerleştiricek
{
    // Her blok 8 karakterlik genişlik (********) + boslukMiktari
    int blokGenisligi = boslukMiktari + 8;

    // İndeks kadar boşluk bırak
    for (int i = 0; i < indeks-offset; i++)
    {
        for (int j = 0; j < blokGenisligi; j++)
            std::cout << " ";
    }

    // İşaretin başlangıcı için ekstra boşluk bırak
    for (int i = 0; i < boslukMiktari; i++)
        std::cout << " ";

    // İşareti çiz
    std::cout << "^^^^^^^^";
}

void dugumGosterimi::cizgiArasiDegerYaz(int deger)
{
    for(int i=0;i<boslukMiktari;i++)
        std::cout<<" ";
    std::cout<<"*";
    std::cout<<std::setw(6)<<deger;
    std::cout<<"*";
} 

void dugumGosterimi::birSatirCiz(int baslangic, int bitis)
{
   for(int i=baslangic;i<bitis;i++) //yanyana 8 tane yıldızdan oluşan 8 tane * yazdırdı
        cizgiYaz();
   std::cout<<std::endl;
}

void dugumGosterimi::bagliListeYaz(int liste[], int boyut, int baslangic, int bitis, int toplamlar[])
{
    const int adresBaslangic = 1000; // İlk düğümün adresi
    const int adresArtis = 8;       // Her düğümün adres artışı
    

    birSatirCiz(baslangic,bitis);
   
   for(int i=baslangic;i<bitis;i++)
    {
      int adres = adresBaslangic + (i * adresArtis);
      cizgiArasiDegerYaz(adres);
    }
   std::cout<<std::endl;

   birSatirCiz(baslangic,bitis);//alt satıra da yazmış olduk yine 8 adet
   
   
   for(int i=baslangic;i<bitis;i++)
      cizgiArasiDegerYaz(toplamlar[i]);
   std::cout<<std::endl;

   birSatirCiz(baslangic,bitis); 


   for (int i = baslangic; i < bitis; i++)
    {
        int sonrakiAdres = adresBaslangic + (((i + 1) % boyut) * adresArtis);
        cizgiArasiDegerYaz(sonrakiAdres);
    }
    std::cout << std::endl;

    birSatirCiz(baslangic, bitis);
   
} 

