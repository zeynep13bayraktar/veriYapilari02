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



#include "agacCizim.hpp"
#include <iostream>
#include <algorithm> // std::max

TreeNode::TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}

agacCizim::agacCizim() : root(nullptr) {}

agacCizim::~agacCizim() {
    deleteTree(root);
}

void agacCizim::insert(char value) {
    if (!root) {
        root = new TreeNode(value);
    } else {
        insertNode(root, value);
    }
}

void agacCizim::printTree() {
    if (!root) {
        std::cout << "Agac bos!" << std::endl;
        return;
    }

    int height = getHeight(root);
    int width = (1 << height) - 1; // 2^height - 1
    char** lines = new char*[height * 2 - 1];

    for (int i = 0; i < height * 2 - 1; ++i) {
        lines[i] = new char[width + 1];
        std::fill(lines[i], lines[i] + width, ' ');
        lines[i][width] = '\0';
    }

    fillTreeLines(root, lines, 0, 0, width - 1);

    for (int i = 0; i < height * 2 - 1; ++i) {
        std::cout << lines[i] << std::endl;
        delete[] lines[i];
    }
    delete[] lines;
}

void agacCizim::insertNode(TreeNode* node, char value) {
    if (value < node->data) {
        if (node->left) {
            insertNode(node->left, value);
        } else {
            node->left = new TreeNode(value);
        }
    } else {
        if (node->right) {
            insertNode(node->right, value);
        } else {
            node->right = new TreeNode(value);
        }
    }
}

int agacCizim::getHeight(TreeNode* node) {
    if (!node) return 0;
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
}

void agacCizim::fillTreeLines(TreeNode* node, char** lines, int depth, int left, int right) {
    if (!node || depth < 0 || left > right) return;

    int mid = (left + right) / 2;
    lines[depth * 2][mid] = node->data;

    if (node->left) {
        lines[depth * 2 + 1][mid - 1] = '.';
        for (int i = mid - 2; i >= (left + mid) / 2; --i) {
            lines[depth * 2 + 1][i] = '-';
        }
        lines[depth * 2 + 2][(left + mid) / 2] = '.';
        fillTreeLines(node->left, lines, depth + 1, left, mid - 1);
    }

    if (node->right) {
        lines[depth * 2 + 1][mid + 1] = '.';
        for (int i = mid + 2; i <= (right + mid + 1) / 2; ++i) {
            lines[depth * 2 + 1][i] = '-';
        }
        lines[depth * 2 + 2][(right + mid + 1) / 2] = '.';
        fillTreeLines(node->right, lines, depth + 1, mid + 1, right);
    }
}

void agacCizim::deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
