#include <stdexcept>

template <typename K, typename V>
class BST {
public:
    virtual ~BST() = default;

    virtual BST<K, V>* insertKeyWithValue(const K& newKey, const V& newValue) = 0;
    virtual int sizeOfTree() const = 0;
    virtual V lookupValueForKey(const K& targetKey) const = 0;
    virtual K largestKey() const = 0;
    virtual K smallestKey() const = 0;
    virtual K parent(const K& targetKey) const = 0;
    virtual K parent(const K& targetKey, BST<K, V>* root) const = 0;
    virtual BST<K, V>* removeKeyWithValue(const K& targetKey) = 0;
};

// Example of custom exception class
class EmptyBSLTException : public std::runtime_error {
public:
    EmptyBSLTException(const std::string& message) 
        : std::runtime_error(message) {}
};
