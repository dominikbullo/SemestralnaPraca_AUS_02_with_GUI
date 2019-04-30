#pragma once

#include "table.h"
#include "../list/list.h"
#include "../tree/binary_tree.h"
#include <stdexcept>

namespace structures
{

	/// <summary> Binarny vyhladavaci strom. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class BinarySearchTree : public Table<K, T>
	{
	public:
		// NOTE: vrchol binarneho vyhľadávacieho stromu pomenovaný
		typedef typename BinaryTreeNode<TableItem<K, T>*> BSTTreeNode;
	public:
		/// <summary> Konstruktor. </summary>
		BinarySearchTree();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> BinarySearchTree, z ktoreho sa prevezmu vlastnosti. </param>
		BinarySearchTree(const BinarySearchTree<K, T>& other);

		/// <summary> Destruktor. </summary>
		~BinarySearchTree();

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat udajovej struktury. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		virtual Structure* clone() const;

		/// <summary> Vrati pocet prvkov v tabulke. </summary>
		/// <returns> Pocet prvkov v tabulke. </returns>
		size_t size() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Tabulka, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato tabulka nachadza po priradeni. </returns>
		Table<K, T>& operator=(const Table<K, T>& other) override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Binarny vyhladavaci strom, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato tabulka nachadza po priradeni. </returns>
		virtual BinarySearchTree<K, T>& operator=(const BinarySearchTree<K, T>& other);

		/// <summary> Vrati adresou data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <returns> Adresa dat s danym klucom. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak kluc nepatri do tabulky. </exception>  
		T& operator[](const K key) override;

		/// <summary> Vrati hodnotou data s daynm klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <returns> Hodnota dat s danym klucom. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak kluc nepatri do zoznamu. </exception>  
		const T operator[](const K key) const override;

		/// <summary> Vlozi data s danym klucom do tabulky. </summary>
		/// <param name = "key"> Kluc vkladanych dat. </param>
		/// <param name = "data"> Vkladane data. </param>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka uz obsahuje data s takymto klucom. </exception>  
		void insert(const K& key, const T& data) override;

		/// <summary> Odstrani z tabulky prvok s danym klucom. </summary>
		/// <param name = "key"> Kluc prvku. </param>
		/// <returns> Odstranene data. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka neobsahuje data s takymto klucom. </exception>  
		T remove(const K& key) override;

		/// <summary> Bezpecne ziska data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <param name = "data"> Najdene data (vystupny parameter). </param>
		/// <returns> true, ak sa podarilo najst a naplnit data s danym klucom, false inak. </returns>
		bool tryFind(const K& key, T& data) override;

		/// <summary> Zisti, ci tabulka obsahuje data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <returns> true, tabulka obsahuje dany kluc, false inak. </returns>
		bool containsKey(const K& key) override;

		/// <summary> Vymaze tabulku. </summary>
		void clear() override;

		/// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
		/// <returns> Iterator na zaciatok struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<TableItem<K, T>*>* getBeginIterator() const override;

		/// <summary> Vrati skutocny iterator na koniec struktury </summary>
		/// <returns> Iterator na koniec struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<TableItem<K, T>*>* getEndIterator() const override;
	protected:
		/// <summary> Najde vrchol binarneho vyhladavacieho stromu s danym klucom. </summary>
		/// <param name = "key"> Hladany kluc. </param>
		/// <param name = "found"> Vystupny parameter, ktory indikuje, ci sa kluc nasiel. </param>
		/// <returns> Vrchol binarneho vyhladavacieho stromu s danym klucom. Ak sa kluc v tabulke nenachadza, vrati otca, ktoreho by mal mat vrchol s takym klucom. </returns>
		typename BSTTreeNode* findBSTNode(const K& key, bool & found) const;
	protected:
		/// <summary> Binarny strom s datami. </summary>
		BinaryTree<TableItem<K, T>*>* binaryTree_;
		/// <summary> Pocet prvkov v binarnom vyhladavacom strome. </summary>
		size_t size_;

		/// <summary> Vlozi vrchol do stromu tak, aby nedoslo k naruseniu usporiadania BST. </summary>
		/// <param name = "node"> Vrchol stromu, ktory ma byt vlozeny. </param>
		/// <returns> true, ak sa podarilo vrchol vlozit (teda v strome nie je vrchol s rovnakym klucom), false inak. </returns>
		bool tryToInsertNode(BSTTreeNode* node);

		/// <summary> Bezpecne vyjme zo stromu vrchol stromu tak, aby nedoslo k naruseniu usporiadania BST. </summary>
		/// <param name = "node"> Vrchol stromu, ktory ma byt vyjmuty. </param>
		/// <remarks> Vrchol nebude zruseny, iba odstraneny zo stromu a ziadne vrcholy nebudu ukazovat na neho a ani on nebude ukazovat na ziadne ine vrcholy. </remarks>
		void extractNode(BSTTreeNode* node);
	};

	// NOTE: aký je rozdiel medzi binarnym stromov a medzi binarnym vyhľadávacím stromom
	// binarnym stromov  -> strom ako graf -> nemá kľúč
	// binarnym vyhľadávacím stromom -> tabuľka -> má kľúč
	template<typename K, typename T>
	inline BinarySearchTree<K, T>::BinarySearchTree() :
		Table<K, T>(),  // predkom je tabuľka
		binaryTree_(new BinaryTree<TableItem<K, T>*>()),
		size_(0)
	{
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>::BinarySearchTree(const BinarySearchTree<K, T>& other) :
		BinarySearchTree()
	{
		*this = other;
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>::~BinarySearchTree()
	{
		clear();
		delete binaryTree_;
		binaryTree_ = 0;
	}

	template<typename K, typename T>
	inline Structure * BinarySearchTree<K, T>::clone() const
	{
		return new BinarySearchTree<K, T>(*this);
	}

	template<typename K, typename T>
	inline size_t BinarySearchTree<K, T>::size() const
	{
		return size_;
	}

	template<typename K, typename T>
	inline Table<K, T>& BinarySearchTree<K, T>::operator=(const Table<K, T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const BinarySearchTree<K, T>&>(other);
		}
		return *this;
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>& BinarySearchTree<K, T>::operator=(const BinarySearchTree<K, T>& other)
	{
		// 1. Test identity
		// 2. clear();
		// 3. kopie table Itemov -> nemôžem InOrder ani for použiť, lebo z toho spraví zoznam
		if (this != &other)
		{
			clear();
			Iterator<TableItem<K, T>* >* iteratorCurrent =
				new Tree<TableItem<K, T>*>::PreOrderTreeIterator(other.binaryTree_->getRoot());
			Iterator<TableItem<K, T>* >* iteratorEnd =
				new Tree<TableItem<K, T>* >::PreOrderTreeIterator(nullptr);

			while (*iteratorCurrent != *iteratorEnd)
			{
				// NOTE: 
				TableItem<K, T>* item = *(*iteratorCurrent);
				insert(item->getKey(), item->accessData());
				++(*iteratorCurrent);
			}
			delete iteratorCurrent;
			delete iteratorEnd;
		}
		return *this;
	}

	template<typename K, typename T>
	inline T & BinarySearchTree<K, T>::operator[](const K key)
	{
		bool found = false;
		BSTTreeNode* node = findBSTNode(key, found);
		if (!found)
		{
			throw std::out_of_range("T & BinarySearchTree<K, T>::operator[](const K key): Data not found");
		}
		// vráti mi posledný bod, kde som našiel dáta
		// NOTE: dva krát je to tam, kvôli tomuze prvý je na tree node a druhý na table item
		// odporúčanie -> kresliť si to !
		return node->accessData()->accessData();
	}

	template<typename K, typename T>
	inline const T BinarySearchTree<K, T>::operator[](const K key) const
	{
		bool found = false;
		BSTTreeNode* node = findBSTNode(key, found);
		if (!found)
		{
			throw std::out_of_range("T & BinarySearchTree<K, T>::operator[](const K key): Data not found");
		}
		// vráti mi posledný bod, kde som našiel dáta
		// NOTE: dva krát je to tam, kvôli tomuze prvý je na tree node a druhý na table item
		// odporúčanie -> kresliť si to !
		return node->accessData()->accessData();
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::insert(const K & key, const T & data)
	{
		// 1. vytvor table item
		// 2. vytvor BSST
		// 3. try to insert
		BSTTreeNode* node = new BSTTreeNode(new TableItem<K, T>(key, data));

		if (!tryToInsertNode(node))
		{
			delete node->accessData();
			delete node;
			throw std::logic_error("Key is already in table!");
		}
	}

	template<typename K, typename T>
	inline T BinarySearchTree<K, T>::remove(const K & key)
	{
		bool found(0);
		BSTTreeNode* node = findBSTNode(key, found);
		if (!found)
		{
			throw std::out_of_range("Key not found");
		}
		extractNode(node);
		T data = node->accessData()->accessData();
		delete node->accessData();
		delete node;
		size_--;
		return data;
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::tryFind(const K & key, T & data)
	{
		bool result = false;
		BSTTreeNode* node = findBSTNode(key, result);
		if (result)
		{
			data = node->accessData()->accessData();
		}
		return result;
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::containsKey(const K & key)
	{
		bool found(0);
		findBSTNode(key, found);
		return found;
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::clear()
	{
		for (TableItem<K, T>* item : *binaryTree_)
		{
			delete item;
		}

		binaryTree_->clear();
		size_ = 0;
	}

	template<typename K, typename T>
	inline Iterator<TableItem<K, T>*>* BinarySearchTree<K, T>::getBeginIterator() const
	{
		return binaryTree_->getBeginIterator();
	}

	template<typename K, typename T>
	inline Iterator<TableItem<K, T>*>* BinarySearchTree<K, T>::getEndIterator() const
	{
		return binaryTree_->getEndIterator();
	}

	template<typename K, typename T>
	inline typename BinarySearchTree<K, T>::BSTTreeNode* BinarySearchTree<K, T>::findBSTNode(const K & key, bool & found) const
	{
		BSTTreeNode* node = dynamic_cast<BSTTreeNode *>(binaryTree_->getRoot());
		BSTTreeNode* result = node;
		while (node != nullptr && node->accessData()->getKey() != key)
		{
			node = key < node->accessData()->getKey() ? node->getLeftSon() : node->getRightSon();
			if (node != nullptr) {
				result = node;
			}
		}
		found = node != nullptr && node->accessData()->getKey() == key;
		return result;
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::tryToInsertNode(BSTTreeNode* node)
	{
		// NOTE: tu ošetrím aj size ak sa to podarí
		bool found(0); // found = false
		K key = node->accessData()->getKey();
		BSTTreeNode* parent = findBSTNode(key, found);
		if (!found)
		{
			if (isEmpty())
			{
				binaryTree_->replaceRoot(node);
			}
			else
			{
				if (key < parent->accessData()->getKey())
				{
					parent->setLeftSon(node);
				}
				else
				{
					parent->setRightSon(node);
				}
			}
		}
		else
		{
			size_++;
		}
		return !found;
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::extractNode(BSTTreeNode* node)
	{
		// TODO 10: BinarySearchTree
		throw std::exception("BinarySearchTree<K, T>::extractNode: Not implemented yet.");
	}

}
