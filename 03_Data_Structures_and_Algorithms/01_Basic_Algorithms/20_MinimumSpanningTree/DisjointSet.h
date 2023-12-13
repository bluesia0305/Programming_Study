#pragma once

template<typename T>
class DisjointSet
{
public:
	struct Set;

public:
	static Set* CreateSet(T data)
	{
		Set* set = new Set();
		set->Parent = nullptr;
		set->Data = data;

		return set;
	}

	static void DestroySet(Set* set)
	{
		delete set;
		set = nullptr;
	}

	static void UnionSet(Set* parent, Set* set)
	{
		set = FindSet(set);
		set->Parent = parent;
	}

	static Set* FindSet(Set* set)
	{
		while (set->Parent != nullptr)
			set = set->Parent;

		return set;
	}

public:
	struct Set
	{
		T Data;
		Set* Parent;
	};
};