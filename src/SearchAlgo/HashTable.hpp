#pragma once
#include <string>
#include <numeric>
#include <set>

namespace SeparateChaining {

template<typename K, typename V>
struct HashNode
{
    HashNode(const K k, const V v) : key(k), value(v), next(nullptr) {}
    HashNode() = default;
    HashNode(const HashNode&) = default;
    const K key{};
    V value{};
    HashNode* next{nullptr};
};

template<typename K, unsigned SIZE>
int hashFunction(const K key)
{
    return key % SIZE;
}

template<typename K, typename V, unsigned SIZE = 20>
struct HashMap
{

    //INSERT
    void insert(const K key, const V value)
    {
        const auto index = hashFunction<K, SIZE>(key);
        HashNode<K, V>* current = hashTable[index];
        HashNode<K, V>* prev = current;

        while(current != nullptr && key != current->key)
        {
            prev = current;
            current = current->next;
        }

        if(prev == nullptr)
        {
            hashTable[index] = new HashNode<K, V>(key, value);
        }
        else
        {
            //TODO create setValue for key
            if(current == nullptr)
            {
                prev->next = new HashNode<K, V>(key, value);
            }
            else
            {
                current->value = value;
            }
        }
    }

    //SEARCH
    HashNode<K, V>* getHashNode(const K key)
    {
        const auto index = hashFunction<K, SIZE>(key);
        HashNode<K, V>* current = hashTable[index];

        while(current != nullptr && current->key != key)
        {
            current = current->next;
        }

        return current;
    }

    //DELETE
    HashNode<K, V> deleteHashNode(const K key)
    {
        const auto index = hashFunction<K, SIZE>(key);
        HashNode<K, V>* current = hashTable[index];
        HashNode<K, V>* prev = current;

        while(current != nullptr && current->key != key)
        {
            prev = current;
            current = current->next;
        }

        if(prev == nullptr)
        {
            return HashNode<K, V>();
        }
        else
        {
            if(current == nullptr)
            {
                return HashNode<K, V>();
            }
            else
            {
                HashNode<K, V> temp(current->key, current->value);

                if(current->next != nullptr)
                {
                    prev->next = current->next;
                }

                delete current;
                return temp;
            }
        }

    }

    HashNode<K, V>* hashTable[SIZE] = {nullptr};
};

} // namespace SeparateChaining

namespace LinearProbing {

template<typename K, typename V>
struct HashNode
{
    HashNode(const K k, const V v): key(k), value(v) {}
    K key;
    V value;
};

template<typename K>
int hashFunction(const K key, unsigned SIZE)
{
    return key % SIZE;
}

template<>
int hashFunction<std::string>(const std::string key, unsigned SIZE)
{
    return std::accumulate(key.begin(), key.end(), 0) % SIZE;
}

template<typename K, typename V, unsigned SIZE>
struct HashMap
{
    static constexpr auto PROBING_INTERVAL = 1u;
    // INSERT
    void insert(const K key, const V value)
    {
        auto index = hashFunction(key, SIZE);
        auto step = 0u;
        while(step < SIZE && hashTable[index] != nullptr && hashTable[index]->key != key)
        {
            index = (index + PROBING_INTERVAL) % SIZE;
            ++step;
        }

        if(step >= SIZE)
        {
            std::cout << "No more space in HashTable" << std::endl;
        }
        else if(hashTable[index] == nullptr)
        {
            hashTable[index] = new HashNode<K, V>(key, value);
        }
        else
        {
            hashTable[index]->value = value;
        }
    }

    // SEARCH
    HashNode<K, V>* getNode(const K key)
    {
        auto index = hashFunction(key, SIZE);
        auto step = 0u;
        while(step < SIZE && hashTable[index]->key != key)
        {
            index = (index + PROBING_INTERVAL) % SIZE;
            ++step;
        }

        return (step >= SIZE) ? nullptr : hashTable[index]; // nullptr or value
    }

    // DELETE - palaisipan

    HashNode<K, V>* hashTable[SIZE] = {nullptr};
};

} // namespace LinearProbing

namespace QuadraticProbing {

template<typename K, typename V>
struct HashNode
{
    HashNode(const K k, const V v): key(k), value(v) {}
    K key;
    V value;
};

template<typename K>
int hashFunction(const K key, unsigned SIZE)
{
    return key % SIZE;
}

template<>
int hashFunction<std::string>(const std::string key, unsigned SIZE)
{
    return std::accumulate(key.begin(), key.end(), 0) % SIZE;
}

template<typename K, typename V, unsigned SIZE>
struct HashMap
{
    static constexpr auto PROBING_INTERVAL = 1u;
    // INSERT
    void insert(const K key, const V value)
    {
        if(currSize >= SIZE)
        {
            std::cout << "No more space in HashTable" << std::endl;
        }
        auto index = hashFunction(key, SIZE);
        auto probe = PROBING_INTERVAL;
        while(hashTable[index] != nullptr && hashTable[index]->key != key)
        {
            index = (index + (probe * probe)) % SIZE;
            ++probe;
        }

        if(hashTable[index] == nullptr)
        {
            hashTable[index] = new HashNode<K, V>(key, value);
            currSize++;
        }
        else
        {
            hashTable[index]->value = value;
        }
    }

    // SEARCH
    HashNode<K, V>* getNode(const K key)
    {
        auto index = hashFunction(key, SIZE);
        std::set<int> indexHashTable;
        auto probe = PROBING_INTERVAL;
        while(indexHashTable.size() <= SIZE && hashTable[index] != nullptr && hashTable[index]->key != key)
        {
            indexHashTable.insert(index);
            index = (index + (probe * probe)) % SIZE;
            ++probe;
        }

        return (indexHashTable.size() > SIZE) ? nullptr : hashTable[index]; // nullptr or value
    }

    // DELETE - palaisipan
    
    HashNode<K, V>* hashTable[SIZE] = {nullptr};
    unsigned currSize = {0};
};

} // namespace QuadraticProbing