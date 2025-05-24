/*VERİ YAPILARI DERSİ BİRİNCİ ÖĞRETİM C GRUBU 
VERİ YAPILARI BİRİNCİ ÖDEV
ÖDEVE BAŞLADIĞIM TARİH: 14-11-24
ÖDEVİ BİTİRDİĞİM TARİH: 26-11-24
ÖDEV RAPORUNU YAZDIĞIM TARİH: 27-11-24
ZEYNEP BAYRAKTAR G231210081
MAİL: zeynep.bayraktar5@ogr.sakarya.edu.tr 
KODUMDAKİ FONKSİYONLARDAN ÇAPRAZLAMA, Dna.txt DEKİ KROMOZOMLARA GÖRE KULLANICI TARAFINDAN GİRİLEN 2 KROMOZOMU ÇAPRAZLAR. ÇAPRAZLAMA İŞLEMİNİN 
ALGORİTMASI KROMOZOMUN ÇİFT VEYA TEK SAYIDA GEN İÇERMESİ DURUMUNA GÖRE DEĞİŞİR. ÇİFT SAYIDA GEN İÇERİYORSA KROMOZOM ÇOCUK KROMOZOMLARA 2 
YARISINDAN BİRİNİ AKTARIR. TEK SAYIDA GEN İÇERİYORSA İŞLEM, ORTANCA GEN YOKMUŞ GİBİ YAPILIR.OLUŞAN 2 YENİ KROMOZOM VE GÜNCEL KROMOZOM LİSTESİ 
EKRANA VERİLİR MUTASYON FONKSİYONU SATIR NUMARASI GİRİLEN KROMOZOMUN SÜTUN NUMARASI GİRİLEN GENİNİ 'X' E ÇEVİRİR. KROMOZOMUN MUTASYONA UĞRAMADAN 
ÖNCEKİ HALİ VE SONRAKİ HALİ EKRANA VERİLİR. OTOMATİK İŞLEMLERDE Islemler.txt DEKİ HER SATIRDAKİ İŞLEM YAPILIR VE EKRANA VERİLİR. C X Y İŞLEMİ 
X. VE Y. SATIRLARDAKİ GENLERİ ÇAPRAZLA DEMEKTİR. M X Y İSE X. SATIRDAKİ KROMOZOMUN Y. SATIRDAKİ GENİNİ MUTASYONA UĞRAT DEMEKTİR. EKRANA YAZ, 
AYNI KROMOZOM ÜZERİNDE EN BÜYÜK İNDİSLİ GENDEN 0. İNDİSLİ GENE DOĞRU TARAR VE 0. İNDİSLİ GENDEN ALFBEDE ÖNCE GELEN İLK BULDUĞU GEİ ALIP EKRANA YAZAR 
VE SIRADAKİ KROMOZOMA GEÇER. EĞER 0. İNDİSLİ GENDEN ALFABEDE DAHA ÖNCE GELEN BİR GEN YOKSA O KROMOZOMDA, EKRANA 0. İNDİSLİ GEN BASILIR. ÇIKIŞ,
PROGRAMDAN ÇIKIŞ İÇİNDİR. */




#include "dna.hpp"


#include <fstream>
#include <iostream>


dna::dna()
{
    ilk= nullptr;
}


void dna::oku(const char* isim)
{
    std::ifstream file("./doc/Dna.txt"); 
    if(!file)
    {
        std::cerr<<"Dosya acilamadi!"<<std::endl;
        return;
    }
    Kromozom* sonKromo=nullptr;
    Kromozom* yeniKromo=nullptr;
    gen* oncekiGen=nullptr;
    char karakter;
    while(file.get(karakter))
    {
        if(karakter=='\n')
        {
            if(yeniKromo)
            {
                if(!ilk)
                {
                    ilk=yeniKromo;

                }
                else
                {
                    sonKromo->sonraki=yeniKromo;
                }
                sonKromo=yeniKromo;
                yeniKromo=nullptr;
            }
        }
        else if (karakter!=' ')
        {
            gen* yeniGen=new gen(karakter);

            if(!yeniKromo)
            {
                yeniKromo=new Kromozom();
                oncekiGen = nullptr;
            }
            if(!yeniKromo->ilk)
            {
                yeniKromo->ilk=yeniGen;

            }
            else
            {
              oncekiGen->sonraki=yeniGen;
            }
            oncekiGen=yeniGen;
        }
    }
    if(yeniKromo)
    {
        if(!ilk)
        {
            ilk=yeniKromo;
        }
        else
        {
            sonKromo->sonraki=yeniKromo;
        }
    }
    file.close();
}
void dna::kromozomEkle(Kromozom* kromozom)
{
    if(!ilk)
    {
        ilk=kromozom;
    }
    else
    {
        Kromozom* gecici = ilk;
        while(gecici->sonraki)
        {
            gecici=gecici->sonraki;
        }
        gecici->sonraki=kromozom;
    }
    kromozom->sonraki=nullptr;
} 
void dna::yazdir2() const
{
   Kromozom* simdikiKromo=ilk;
   int satirNo=0;
   while(simdikiKromo)
   {
    std::cout<<"Kromozom "<<satirNo++<<": ";
    gen* simdikiGen = simdikiKromo->ilk;
    while(simdikiGen)
    {
        std::cout<<simdikiGen->veri<<" ";
        simdikiGen=simdikiGen->sonraki;
    }
    std::cout<<std::endl;
    simdikiKromo=simdikiKromo->sonraki;
   }
   
}


void dna::caprazlama(int satir1, int satir2) 
{
    
    std::ifstream file("./doc/Dna.txt"); 
    if (!file) 
    {
        std::cerr << "Dosya acilamadi!" << std::endl;
        return;
    }

    
    Kromozom* anne = nullptr;
    Kromozom* baba = nullptr;
    Kromozom* simdikiKromo = nullptr;
    gen* oncekiGen = nullptr;
    
    int satirNo = 0;
    char karakter;

    while (file.get(karakter)) 
    {
        if (karakter == '\n') 
        {
            if (satirNo == satir1) 
            {
                anne = simdikiKromo;
            } 
            if (satirNo == satir2) 
            {
                baba = simdikiKromo;
            }
            if (anne && baba) break;  
            simdikiKromo = nullptr;
            satirNo++;
        } 
        else if (karakter != ' ') 
        {
            gen* yeniGen = new gen(karakter);
            if (!simdikiKromo) 
            {
                simdikiKromo = new Kromozom();
            }
            if (!simdikiKromo->ilk) 
            {
                simdikiKromo->ilk = yeniGen;
            } 
            else 
            {
                oncekiGen->sonraki = yeniGen;
            }
            oncekiGen = yeniGen;
        }
    }

    file.close();

    
    if (!anne || !baba) 
    {
        std::cerr << "Verilen satir numaralarinda kromozom bulunamadi!" << std::endl;
        return;
    }

    
    Kromozom* cocuk1 = new Kromozom();
    Kromozom* cocuk2 = new Kromozom();

    
    gen* geclist1 = anne->ilk;
    gen* geclist2 = baba->ilk;

    
    int size1 = 0, size2 = 0;
    while (geclist1) 
    {
        size1++;
        geclist1 = geclist1->sonraki;
    }
    while (geclist2) 
    {
        size2++;
        geclist2 = geclist2->sonraki;
    }

    
    geclist1 = anne->ilk;
    geclist2 = baba->ilk;

    
    if ((size1 % 2 == 0 && size2 % 2 == 1) || (size1 % 2 == 1 && size2 % 2 == 0)) 
    {
        Kromozom* ciftKromozom = (size1 % 2 == 0) ? anne : baba;
        Kromozom* tekKromozom = (size1 % 2 == 1) ? anne : baba;

        
        gen* geciciCift = ciftKromozom->ilk;
        int ciftSize = (size1 % 2 == 0) ? size1 : size2;
        for (int i = 0; i < ciftSize / 2; i++) 
        {
            cocuk1->genEkle(geciciCift->veri);
            geciciCift = geciciCift->sonraki;
        }
        while (geciciCift) 
        {
            cocuk2->genEkle(geciciCift->veri);
            geciciCift = geciciCift->sonraki;
        }

        
        gen* geciciTek = tekKromozom->ilk;
        int tekSize = (size1 % 2 == 1) ? size1 : size2;
        int orta = tekSize / 2;

        
        for (int i = 0; i < orta; i++) 
        {
            cocuk1->genEkle(geciciTek->veri);
            geciciTek = geciciTek->sonraki;
        }
        
        geciciTek = geciciTek->sonraki;

        
        while (geciciTek) 
        {
            cocuk2->genEkle(geciciTek->veri);
            geciciTek = geciciTek->sonraki;
        }
    } 
    else if (size1 % 2 == 0 && size2 % 2 == 0) 
    {
        
        geclist1 = anne->ilk;
        geclist2 = baba->ilk;
        for (int i = 0; i < size1 / 2; i++) 
        {
            cocuk1->genEkle(geclist1->veri);
            geclist1 = geclist1->sonraki;
        }
        for (int i = 0; i < size2 / 2; i++) 
        {
            cocuk2->genEkle(geclist2->veri);
            geclist2 = geclist2->sonraki;
        }

        
        while (geclist1) 
        {
            cocuk2->genEkle(geclist1->veri);
            geclist1 = geclist1->sonraki;
        }
        while (geclist2) 
        {
            cocuk1->genEkle(geclist2->veri);
            geclist2 = geclist2->sonraki;
        }
    } 
    else if (size1 % 2 == 1 && size2 % 2 == 1) 
    {
        
        geclist1 = anne->ilk;
        geclist2 = baba->ilk;
        int orta1 = size1 / 2;
        int orta2 = size2 / 2;

        
        for (int i = 0; i < orta1; i++) 
        {
            cocuk1->genEkle(geclist1->veri);
            geclist1 = geclist1->sonraki;
        }
        for (int i = 0; i < orta2; i++) 
        {
            cocuk2->genEkle(geclist2->veri);
            geclist2 = geclist2->sonraki;
        }

        
        geclist1 = anne->ilk;
        geclist2 = baba->ilk;
        for (int i = 0; i < orta1 + 1; i++) 
        {
            geclist1 = geclist1->sonraki;
        }
        for (int i = 0; i < orta2 + 1; i++) 
        {
            geclist2 = geclist2->sonraki;
        }

        while (geclist1) 
        {
            cocuk2->genEkle(geclist1->veri);
            geclist1 = geclist1->sonraki;
        }
        while (geclist2) 
        {
            cocuk1->genEkle(geclist2->veri);
            geclist2 = geclist2->sonraki;
        }
    }


    
    kromozomEkle(cocuk1);
    kromozomEkle(cocuk2);

    std::cout << "Olusan kromozomlar: " << std::endl;
    yazdir(cocuk1);
    yazdir(cocuk2);

    std::cout << std::endl;
    std::cout << "Caprazlama islemi tamamlandi." << std::endl;
    yazdir2();

    
    delete anne;
    delete baba;
    delete cocuk1;
    delete cocuk2;
}

void dna::mutasyon(int satir, int sutun)
{ 
    std::ifstream file("./doc/Dna.txt");
    if(!file)
    {    
        std::cerr<<"Dosya acilamadi!"<<std::endl;
        return;
    }
       
   
     

    if(satir<0||sutun<0)
    {
        std::cerr<<"Hatali satir veya sutun numarasi..."<<std::endl;
        return;
    }

    Kromozom* secilenKromo = kromoSatir(satir);
    if(!secilenKromo)
    {
        std::cout<<"Gecersiz satir numarasi!"<<std::endl;
        return;
    }

    gen* seciliGen=genSutun(secilenKromo, sutun);
    if(!seciliGen)
    {
        std::cout<<"Gecersiz sutun numarasi girdiniz."<<std::endl;
        return;
    }
    std::cout<<"Mutasyon icin sectiginiz kromozom: "<<std::endl;
    gen* genn=secilenKromo->ilk;
    while(genn)
    {
        std::cout<<genn->veri<<" ";
        genn=genn->sonraki;
    } 
    std::cout<<std::endl;

    seciliGen->veri = 'X';
    std::cout<<"Mutasyonlu kromozomumuz: "<<std::endl;
    genn=secilenKromo->ilk;
    while(genn)
    {
        std::cout<<genn->veri<<" ";
        genn=genn->sonraki;
    }
    std::cout<<std::endl;
}

void dna:: otoIslemler(const char* dosyaAdi)
{
    std::ifstream file("./doc/Islemler.txt");
    if(!file)
    {
        std::cerr<<"Dosya acilamadi!"<<std::endl;
        return;
    }

    char islemler;
    int satir1 ,satir2;
    while(file>>islemler>>satir1>>satir2)
    {
      

        if(islemler=='C')
        {
            std::cout<<satir1<<". ve "<<satir2<<". kromozomlar caprazlaniyor: "<<std::endl;
            caprazlama(satir1,satir2);
        }
        else if(islemler=='M')
        {
            std::cout<<satir1<<". kromozomun "<<satir2<<". geni mutasyona ugruyor:"<<std::endl; //satir2 yi sutun gibi kullandım
            mutasyon(satir1,satir2);
        }
        else 
        {
            std::cout<<"Gecersiz islem: "<<islemler<<std::endl;
        }
    }
    file.close();
}

dna::~dna()
{
    Kromozom* mevcutKromo=ilk;
    while(mevcutKromo)
    {
        gen*mevcutGen=mevcutKromo->ilk;
        while(mevcutGen)
        {
            gen* silinecekGen=mevcutGen;
            mevcutGen=mevcutGen->sonraki;
            delete silinecekGen;
        }
        Kromozom*silinecekKromo=mevcutKromo;
        mevcutKromo=mevcutKromo->sonraki;
        delete silinecekKromo;
    }
    ilk=nullptr;
    
}
Kromozom* dna::kromoSatir(int satir)
{
    int ilkSat=0;
    Kromozom* gecici = ilk;
    while(gecici)
    {
        if(ilkSat==satir)
        {
            return gecici;
        }
        gecici = gecici->sonraki;
        ilkSat++;
    } 
    return nullptr;
}

gen*dna::genSutun(Kromozom* kromo, int sutun)
{
    int ilkSut=0;
    gen* gecici=kromo->ilk;
    while(gecici)
    {
        if(ilkSut==sutun)
        {
            return gecici;
        }
        gecici=gecici->sonraki;
        ilkSut++;
    }
    return nullptr;
}
void dna::yazdir(Kromozom* kromozom)
{
    if(!kromozom || !kromozom->ilk)
    {
        std::cout<<"Kromozomda yazdirilacak gen yok... "<<std::endl;
        return;
    }
    gen* gecici= kromozom->ilk;
    while(gecici)
    {
        std::cout<<gecici->veri<<" ";
        gecici=gecici->sonraki;


    }
    std::cout<<std::endl;
}
void dna::yazdirAlf()
{
    std::ifstream file("./doc/Dna.txt");
    if(!file)
    {    
        std::cerr<<"Dosya acilamadi!"<<std::endl;
        return;
    }
    Kromozom* simdikiKromo = ilk; // DNA'nın ilk kromozomundan başla
    int satirNo = 0;             // Kromozom numaralarını takip etmek için

    while (simdikiKromo) { // Her kromozomu sırayla kontrol et
        if (!simdikiKromo->ilk) {
            std::cout << "Kromozom " << satirNo << ": Gen bulunamadi!" << std::endl;
        } else {
            gen* simdikiGen = simdikiKromo->ilk;
            char enKucuk = simdikiGen->veri; // İlk geni başlangıç olarak kabul et

            // Genleri sırayla kontrol et
            while (simdikiGen) {
                if (simdikiGen->veri < enKucuk) {
                    enKucuk = simdikiGen->veri; // Daha küçük bir gen bulundu
                }
                simdikiGen = simdikiGen->sonraki;
            }

            // En küçük geni yazdır
            std::cout << "Kromozom " << satirNo << ": " << enKucuk << std::endl;
        }

        simdikiKromo = simdikiKromo->sonraki; // Bir sonraki kromozoma geç
        satirNo++;
    }

   
}