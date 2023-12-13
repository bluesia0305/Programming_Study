#pragma once
#include <iostream>

template<typename T1, typename T2>
class Map
{
private:
	std::pair<T1, T2>* container = nullptr;
	unsigned length = 0;

	void Swap(unsigned n1, unsigned n2)
	{
		if (!Empty())
		{
			std::pair<T1, T2> temp = container[n2];
			container[n2] = container[n1];
			container[n1] = temp;
		}
	}

	void Sort()
	{
		for (unsigned i = 0; i < Length() - 1; i++)
			for (unsigned j = 0; j < Length() - (i + 1); j++)
				if (container[j].first > container[j + 1].first) Swap(j, j + 1);
	}

public:
	virtual ~Map() = default;

	unsigned Length() const
	{ return length; }

	unsigned Size() const
	{ return length * sizeof(std::pair<T1, T2>); }

	void Print() const
	{
		for (unsigned i = 0; i < Length(); i++)
			std::cout << container[i].first << " : " << container[i].second << std::endl;
	}

	void Insert(std::pair<T1, T2> data)
	{
		if (Find(data.first) == End())
		{
			std::pair<T1, T2>* temp = new std::pair<T1, T2>[length + 1];
			for (unsigned i = 0; i < Length(); i++)
			{ temp[i] = container[i]; }

			temp[Length()] = data;
			delete[] container;
			container = temp;
			length++;

			if (Length() > 2) Sort();
			else if (Length() == 2)
				if (container[0].first > container[1].first) Swap(0, 1);
		}
	}

	void Erase(T1 key)
	{
		if (!Empty())
		{
			std::pair<T1, T2>* pTemp = Find(key);
			if (pTemp != End())
			{
				if (Length() > 1)
				{
					unsigned j = 0;
					std::pair<T1, T2>* container_erased = new std::pair<T1, T2>[Length() - 1];
					for (unsigned i = 0; i < Length(); i++)
					{
						if (container[i] != *pTemp)
						{
							container_erased[j] = container[i];
							j++;
						}
					}

					delete[] container;
					container = container_erased;
					length--;
				}
				else if (Length() == 1) Clear();
			}
			else printf("container 내에 존재하지 않는 key 입니다.\n");
		}
		else printf("container가 이미 empty 상태입니다.\n");
	}

	std::pair<T1, T2>* Begin() const
	{ return container; }

	std::pair<T1, T2>* End() const
	{ return container + Length(); }

	std::pair<T1, T2>* Find(T1 key) const
	{
		unsigned i = 0;
		for (; i < Length(); i++)
			if (container[i].first == key) break;
		return container + i;
	}

	bool Empty() const
	{ return Length() ? false : true; }

	void Clear()
	{
		if (Length())
		{
			delete[] container;
			container = nullptr;
			length = 0;
		}
	}

	T2& At(T1 key) const
	{ if (Find(key) != End()) return Find(key)->second; }

	T2& operator[] (T1 key) const
	{ return At(key); }
};
