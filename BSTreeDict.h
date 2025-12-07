#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V> {

private:
    BSTree<TableEntry<V>>* tree;

public:
    // Constructor
    BSTreeDict() {
        tree = new BSTree<TableEntry<V>>();
    }

    // Destructor
    ~BSTreeDict() {
        delete tree;
    }

    // Operador [] para acceso rápido
    V operator[](std::string key) {
        return search(key);
    }

    // Sobrecarga friend global de <<
    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
        bs.tree->print_inorder(out);  // Ahora es un método público
        return out;
    }

    // Declaraciones de los métodos de Dict<V>
    int entries() override;
    void insert(std::string key, V value) override;
    V search(std::string key) override;
    V remove(std::string key) override;
};

// Implementación de los métodos

template <typename V>
int BSTreeDict<V>::entries() {
    return tree->size();
}

template <typename V>
void BSTreeDict<V>::insert(std::string key, V value) {
    TableEntry<V> te(key, value);
    tree->insert(te);
}

template <typename V>
V BSTreeDict<V>::search(std::string key) {
    TableEntry<V> te(key, V());
    return tree->search(te).value;
}

template <typename V>
V BSTreeDict<V>::remove(std::string key) {
    TableEntry<V> te(key, V());
    tree->remove(te);  // Llamada al método remove() de BSTree, no es necesario almacenar el valor
    return te.value;    // Retorna el valor de la entrada eliminada
}

#endif // BSTREEDICT_H
