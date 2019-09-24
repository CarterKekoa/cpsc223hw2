/**	This function deals with the vectors and performs various
*		tasks on them.
*	Carter Mooring
*	CSPC 223 Dr. Bowers
*	hw3
*	vector_collection.h
*	9/23/19
*/

#ifndef VECTOR_COLLECTION_H
#define VECTOR_COLLECTION_H

#include <vector>
#include <algorithm>
#include "collection.h"

using namespace std;

template <typename K, typename V>
class VectorCollection : public Collection <K,V>{
  public:

    // insert a key-value pair into the collection
    void insert(const K& key, const V& val);

    // remove a key-value pair from the collection
    void remove(const K& key);

    // find and return the value associated with the key
    bool find(const K& key, V& val) const;

    // find and return the list of keys >= to k1 and <= to k2
    void find(const K& k1, const K& k2, std::vector<K>& keys) const;

    // return all of the keys in the collection
    void keys(std::vector <K>& keys) const;

    // return all of the keys in the collection
    void sort(std::vector <K>& keys) const;

    // return the number of keys in collection
    int size() const;

  private:
    std::vector<std::pair<K,V>> kv_list;

};


template <typename K, typename V>
// insert a key-value pair into the collection
void VectorCollection<K,V>::insert(const K& key, const V& val){
  std::pair<K,V> p(key, val);
  kv_list.push_back(p);
}

template <typename K, typename V>
// remove a key-value pair from the collection
void VectorCollection <K,V>::remove(const K& key){
  int i = 0;
  for(pair<K,V> P : kv_list){
    if(P.first == key){
      kv_list.erase(kv_list.begin() + i);
    }
    i++;
  }
}

template <typename K, typename V>
// find and return the value associated with the key
bool VectorCollection<K,V>::find(const K& key, V& val) const{
  for(pair<K,V> P : kv_list){
    if(P.first == key){
      val = P.second;
      return true;
    }
  }
  return false;
}

template <typename K, typename V>
// find and return the list of keys >= to k1 and <= to k2
void VectorCollection <K,V>::find(const K& k1, const K& k2, std::vector<K>& keys) const{
  for(pair<K,V> P : kv_list){
    if(P.first >= k1 && P.first <= k2){
      keys.push_back(P.first);
    }
  }
}

template <typename K, typename V>
// return all of the keys in the collection
void VectorCollection <K,V>::keys(std::vector <K>& keys) const{
	if(kv_list.size() != 0){
		for(pair<K,V> P : kv_list){
			keys.push_back(P.first);
		}
	}
}


template <typename K, typename V>
// return all of the keys in the collection
void VectorCollection <K,V>::sort(std::vector <K>& keys) const{
  vector <pair<K,V>> copy = kv_list;
  std::sort(copy.begin(), copy.end());

  if(kv_list.size() != 0){
	for(pair<K,V> P : copy){
		keys.push_back(P.first);
	}
  }
}

template <typename K, typename V>
// return the number of keys in collection
int VectorCollection <K,V>::size() const{
  return kv_list.size();
}

#endif
