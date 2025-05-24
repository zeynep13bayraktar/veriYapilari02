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
#include "agacDeger.hpp"
#include "agacCizim.hpp"
#include<iostream> 
#include <iomanip>
#include<conio.h>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm> // std::max
using namespace std;

   
int main()
{
   dugumGosterimi gosterim;

   int indeks = 0;
   
   const int maxBoyut = 15; // Maksimum düğüm sayısı
    int liste[maxBoyut];     // Sabit boyutlu dizi
    int boyut = 15;          // Mevcut düğüm sayısı
    int toplamlar[maxBoyut] = {0};

    for (int i = 0; i < boyut; i++) {
        liste[i] = i + 1; // Diziyi 1'den 15'e kadar doldur
    }


const std::string fileName = "./doc/agaclar.txt";
    processFile(fileName, toplamlar, maxBoyut);

    

   while(true)//tuşa basarak ilerleyebilmek için. Sonsuz bir döngüye giricez çünkü uygulamamız devamlı çalışıyo
   {
    system("cls"); //ekranı temizliyo 


    if(indeks >= 13 && boyut > 13)
    {
        gosterim.bagliListeYaz(liste, boyut, 13, boyut, toplamlar); //çizim yapıyo
        cout<<endl;
        gosterim.isaretYaz(indeks-13, 0);
    }
    else
    {
        gosterim.bagliListeYaz(liste, boyut, 0, std::min(13, boyut), toplamlar); //çizim yapıyo
        cout<<endl;
        gosterim.isaretYaz(indeks,0);
    }
    
      
    cout<<endl;


    int secim = _getch(); //artık sil enter sil enter yapmıyo. Ben bir karaktere basınca silip yazıyo
    
    if (secim == 'x' || secim == 'X') // Çıkış için
            break;

        if (secim == 'd' || secim == 'D') { // Sağ hareket
            if (indeks < 14)
                indeks++;
        } else if (secim == 'a' || secim == 'A') { // Sol hareket
            if (indeks > 0)
                indeks--;
        } else if(secim == 's' || secim == 'S') {
             if (boyut > 0)
            {
              // Seçili sütunu sil ve kaydır
                for (int i = indeks; i < boyut - 1; i++)
                {
                    liste[i] = liste[i + 1];
                    toplamlar[i] = toplamlar[i + 1];
                }
                boyut--; // Düğüm sayısını azalt
                if (indeks >= boyut) {
                    indeks--; // Sona yaklaştıysak indeksi bir azalt
                }
            
                }
            }
           
           const std::string fileName = "./doc/agaclar.txt";
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Dosya acilamadi!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) continue;

        agacCizim tree;
        for (char ch : line) {
            tree.insert(ch);
        }

        std::cout << "Agac semasi:" << std::endl;
        tree.printTree();
        std::cout << std::endl;
    }

    inputFile.close();
   
        }
      
    

    return 0;
    
   
}