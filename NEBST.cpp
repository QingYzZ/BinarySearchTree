#include <iostream>
#include "BST.hpp"

using namespace std;

template <typename K, typename V>
class NEBST : public BST <K, V>{
	private:
	K key;
	V value;
	unique_ptr< BST <K, V> > left, right;

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
			right = right->insertKeyWithValue(newKey, newValue);
		} else {
			left = left->insertKeyWithValue(newKey, newValue);
		}
		/* return the pointer to the current tree */
		return this;
	}

	int sizeOfTree() const {
		return 1 + left.sizeOfTree() + right.sizeOfTree();
	}

	V lookupValueForKey(const K& targetKey) const {
		if (targetKey == NULL) {
			perror("Invalid Parameters");
			exit(EXIT_FAILURE);
		}

		if (!key.compare(targetKey)) {
			return value;
		} else if (key.compare(targetKey) > 0) {
			return right->lookupValueForKey(targetKey);
		} else {
			return left->lookupValueForKey(targetKey);
		}
	}

	K largestKey() const {
		if(right == nullptr) {
			return key;
		} 
		return right->largestKey();
	}

	K smallestKey() const {
		if (left == nullptr) {
			return key;
		}
		return left->smallestKey();
	}

	 K parent(const K& targetKey) const {
		if (targetKey == nullptr) {
			perror("Invalid Parameters");
			exit(EXIT_FAILURE);
		}
        return parent(targetKey, this);
    }

	K parent(const K& targetKey, BST<K, V>* root) const {
		if (!root || (root->key == targetKey)) {
            throw runtime_error("No parent found");
        }
        if ((root->left && root->left->key == targetKey) || 
            (root->right && root->right->key == targetKey)) {
            return root->key;
        }
        if (targetKey < root->key && root->left) {
            return parent(targetKey, root->left.get());
        } else if (targetKey > root->key && root->right) {
            return parent(targetKey, root->right.get());
        }
        throw runtime_error("No parent found");
	}

	BST<K, V>* removeKeyWithValue(const K& targetKey) {
		if (targetKey == nullptr) {
			perror("Invalid Parameters");
			exit(EXIT_FAILURE);
		}

		if (targetKey < key) {
			if (left) {
				left = unique_ptr<BST <K, V> >(left->removeKeyWithValue(targetKey));
			}
		} else if (targetKey > key) {
			if (right) {
				right = unique_ptr<BST <K, V> >(right->removeKeyWithValue(targetKey));
		}
		} else {
			if (!left) {
				return right.release();
			} else if (!right) {
				return left.release();
			} else {
				K minKey = right->smallestKey();
				value = right->lookupValueForKey(minKey);
				key = minKey;
				right = unique_ptr<BST <K, V> >(right->removeKeyWithValue(minKey));
			}
		}
		return this;
	}

};