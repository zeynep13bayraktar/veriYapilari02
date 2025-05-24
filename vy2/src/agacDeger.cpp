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
#include "agacDeger.hpp"
#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;
// Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Add a value to the tree
void BinarySearchTree::add(int value) {
    if (!root) {
        root = new Node(value);
    } else {
        insert(root, value);
    }
}

// Get the root of the tree
Node* BinarySearchTree::getRoot() const {
    return root;
}

// Helper function to insert a value into the tree
void BinarySearchTree::insert(Node* node, int value) {
    if (value < node->value) {
        if (!node->left) {
            node->left = new Node(value);
        } else {
            insert(node->left, value);
        }
    } else {
        if (!node->right) {
            node->right = new Node(value);
        } else {
            insert(node->right, value);
        }
    }
}

// Process a single line and compute the total sum
int processLine(const std::string& line) {
    if (line.empty()) return 0;

    BinarySearchTree bst;
    int totalSum = 0;

    // Add the root value
    int rootValue = static_cast<int>(line[0]);
    bst.add(rootValue);
    totalSum += rootValue;

    // Process the rest of the line
    for (size_t i = 1; i < line.size(); ++i) {
        int asciiValue = static_cast<int>(line[i]);
        Node* current = bst.getRoot();
        bool isLeft = false;

        // Traverse the tree and determine the insertion direction
        while (current) {
            if (asciiValue < current->value) {
                if (!current->left) {
                    isLeft = true; // Left branch
                    break;
                }
                current = current->left;
            } else {
                if (!current->right) {
                    isLeft = false; // Right branch
                    break;
                }
                current = current->right;
            }
        }

        // Update the total sum
        if (isLeft) {
            totalSum += 2 * asciiValue; // Left branch -> 2x
        } else {
            totalSum += asciiValue;    // Right branch -> Direct addition
        }

        // Add the character to the tree
        bst.add(asciiValue);
    }

    return totalSum;
}

// Process a file and fill the array with computed totals
void processFile(const std::string& fileName, int toplamlar[], int maxBoyut) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Dosya acilamadi: " << fileName << std::endl;
        return;
    }

    std::string line;
    int index = 0;

    while (std::getline(file, line) && index < maxBoyut) {
        toplamlar[index] = processLine(line);
        ++index;
    }

    // Fill remaining array slots with 0
    for (; index < maxBoyut; ++index) {
        toplamlar[index] = 0;
    }

    file.close();
}

BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

void BinarySearchTree::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}