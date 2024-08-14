#include <iostream>
#include "BST.hpp"

template <typename K, typename V>
class NEBST : public BST <K, V>{
	private:
	K key;
	V value;
	BST<K, V> left, right;

	public:

	BST<K, V>* insertKeyWithValue(const K& newKey, const V& newValue) {
		if (newKey == NULL || newValue == NULL) {
			perror("Invalid Parameters");
			exit(EXIT_FAILURE);
		}

		/* if newKey already present, simply overwrite the old value */
		if (!key.compare(newKey)) {
			value = newValue;
		} else if (key.compare(newKey) > 0) { /* According to BST, greater key is on the right side */
			right = right.insertKeyWithValue(newKey, newValue);
		} else {
			left = left.insertKeyWithValue(newKey, newValue);
		}
		/* return the pointer to the current tree */
		return this;
	}

	int sizeOfTree() {
		return 1 + left.sizeOfTree() + right.sizeOfTree();
	}

	V lookupValueForKey(const K& targetKey) {
		
	}
};