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

#ifndef agacDeger_hpp
#define agacDeger_hpp

#include <string>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree();
    void add(int value);
    Node* getRoot() const;
    ~BinarySearchTree();
    void clear(Node* node);

private:
    Node* root;
    void insert(Node* node, int value);
};

int processLine(const std::string& line);
void processFile(const std::string& fileName, int toplamlar[], int maxBoyut);







#endif 


