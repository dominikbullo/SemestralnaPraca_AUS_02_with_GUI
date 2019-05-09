#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"
#include "../../../SortingKey.h"

namespace structures
{

	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class HeapSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
		void sortByCustomKey(UnsortedSequenceTable<K, T>& table, bool desc);
	};

	template<typename K, typename T>
	inline void HeapSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		bool swapping;
		for (int i = 1; i < (int)table.size(); i++) {
			int current = i;
			do {
				swapping = false;
				int father = (current - 1) / 2;
				//K test1 = table.getItemAtIndex(current).getKey();
				//K test2 = table.getItemAtIndex(father).getKey();
				//auto test3 = table.getItemAtIndex(current).getKey()->getValue();
				//auto test4 = table.getItemAtIndex(father).getKey()->getValue();
				//if (test1 > test2 != test3 > test4)
				//{
				//	throw std::exception("TOTO sa nesmie sta!");
				//}
				if ((current > 0) && (table.getItemAtIndex(current).getKey() > table.getItemAtIndex(father).getKey())) {
					table.swap(current, father);
					current = father;
					swapping = true;
				}
			} while (swapping);
		}
		for (int i = table.size() - 1; i > 0; i--) {
			table.swap(0, i);
			int current = 0;
			do {
				swapping = false;
				int max;
				int left = current * 2 + 1;
				int right = current * 2 + 2;
				if (left < i && right < i)
					max = table.getItemAtIndex(left).getKey() > table.getItemAtIndex(right).getKey() ? left : right;
				else
					max = left < i ? left : right;
				if (max < i && table.getItemAtIndex(max).getKey() > table.getItemAtIndex(current).getKey()) {
					table.swap(max, current);
					current = max;
					swapping = true;
				}
				//notify();
			} while (swapping);
		}
	}

	template<typename K, typename T>
	inline void HeapSort<K, T>::sortByCustomKey(UnsortedSequenceTable<K, T>& table, bool desc)
	{
		// primary sorting from smallest to biggest
		bool swapping;
		for (int i = 1; i < (int)table.size(); i++) {
			int current = i;
			do {
				swapping = false;
				int father = (current - 1) / 2;
				if (desc) {
					if ((current > 0) && (table.getItemAtIndex(current).getKey()->getValue() < table.getItemAtIndex(father).getKey()->getValue())) {
						table.swap(father, current);
						father = current;
						swapping = true;
					}
				}
				else {
					auto test1 = table.getItemAtIndex(current).getKey()->getValue();
					auto test2 = table.getItemAtIndex(father).getKey()->getValue();
					if ((current > 0) && (table.getItemAtIndex(current).getKey()->getValue() > table.getItemAtIndex(father).getKey()->getValue()))
					{
						table.swap(current, father);
						current = father;
						swapping = true;
					}
				}

			} while (swapping);
		}
		for (int i = table.size() - 1; i > 0; i--) {
			table.swap(0, i);
			int current = 0;
			do {
				swapping = false;
				int max;
				int left = current * 2 + 1;
				int right = current * 2 + 2;
				if (left < i && right < i)
				{
					if (desc)
					{
						max = table.getItemAtIndex(left).getKey()->getValue() < table.getItemAtIndex(right).getKey()->getValue() ? left : right;
					}
					else
					{
						max = table.getItemAtIndex(left).getKey()->getValue() > table.getItemAtIndex(right).getKey()->getValue() ? left : right;
					}
				}
				else
				{
					max = left < i ? left : right;
				}

				if (desc)
				{
					if (max < i && table.getItemAtIndex(max).getKey()->getValue() < table.getItemAtIndex(current).getKey()->getValue()) {
						table.swap(max, current);
						current = max;
						swapping = true;
					}
				}
				else
				{
					if (max < i && table.getItemAtIndex(max).getKey()->getValue() > table.getItemAtIndex(current).getKey()->getValue()) {
						table.swap(max, current);
						current = max;
						swapping = true;
					}

				}
				//notify();
			} while (swapping);
		}
	}

}