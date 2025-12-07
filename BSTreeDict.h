#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree ;

    public:
        BSTreeDict(){
	tree = new BSTree<TableEntry<V>>();
	}
	~BSTreeDict(){
	delete tree;
	}
	friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
	 bs.tree->inorder([&out](const TableEntry<V> &te){out << "('" << te.key << "' => " << te.value << ") "; });
	 return out;
	}
	

	V operator[](std::string key){
	return search(key);
	}

	int entries()  override;          // llama tree->size()
    	void insert(std::string key, V value) override;  // llama tree->insert(TableEntry)
    	V search(std::string key)  override;       // llama tree->search(TableEntry)
   	V remove(std::string key) override;             // llama tree->remove(TableEntry)
        
};

#endif
