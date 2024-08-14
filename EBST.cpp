#include <iostream>

#include "BST.hpp"

template <typename K, typename V>
class EBST : public BST <K, V> {

	EBST<K, V>* insertKeyWithValue(const K& newKey, const V& newValue) {
		return new EBST(newKey, newValue);
	}

	int sizeOfTree() {
		return 0;
	}

	V lookupValueForKey(const K& targetKey) {
		return NULL;
	}

	K largestKey() {
		perror("Invalid call to Empty BST");
		exit(EXIT_FAILURE);
	}

	K smallestKey() {
		perror("Invalid call to Empty BST");
		exit(EXIT_FAILURE);
	}

	K parent(const K& targetKey) {
		return NULL;
	}

	K parent(const K& targetKey, BST<K, V>* root) {
		return NULL;
	}

	BST<K, V>* removeKeyWithValue(const K& targetKey) {
		return this;
	}

};