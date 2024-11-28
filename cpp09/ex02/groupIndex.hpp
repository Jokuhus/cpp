#ifndef _GROUPINDEX_HPP_
	#define _GROUPINDEX_HPP_

#include <iterator>
#include <algorithm>

template<class Container>
struct groupIndex
{
	typename Container::size_type	base;
	typename Container::size_type	size;
};

template<class Container>
groupIndex<Container> MakeGroupIndex(std::size_t it, typename std::size_t size)
{
	struct groupIndex<Container>	group;

	group.base = it;
	group.size = size;

	return group;
}

template<class Container>
groupIndex<Container> MakeGroupIndex(groupIndex<Container> it, typename Container::size_type size)
{
	struct groupIndex<Container>	group;

	group.base = it.base;
	group.size = size * it.size;

	return group;
}

template<class Container>
void	IndexSwapIf(typename Container::size_type lhs, typename Container::size_type rhs, Container &container)
{
	if (container[lhs] < container[rhs])
	{
		for (typename Container::size_type i = 0; lhs + i < rhs; ++i)
			std::swap(container[lhs + i], container[rhs + i]);
	}
}

template<class Container>
typename Container::iterator	IndexToIter(Container &container, typename Container::size_type index)
{
	typename Container::iterator it = container.begin();

	if (index >= container.size())
		return container.end();
	std::advance(it, index);
	return it;
}

template<class Container>
typename Container::size_type	UpperBound(Container &container, typename std::size_t start, typename std::size_t end, int value, typename std::size_t size)
{
    while (start < end)
	{
		typename	std::size_t	mid = start + ((end - start) / (2 * size)) * size;

		if (container[mid] == value)
			return mid;
		else if (container[mid] < value)
			start = mid + size;
		else
			end = mid;
	}
    return end;
}

template<class Container>
void	MergeInsertionSort(groupIndex<Container> first, groupIndex<Container> last, Container &container)
{
	typedef typename Container::size_type	size_t;

	size_t	size = (last.base - first.base) / first.size;
	if (size < 2)
		return ;

	bool	has_stray = (size % 2 != 0);

	groupIndex<Container>	end = MakeGroupIndex<Container>(has_stray ? last.base - last.size : last.base, last.size);
	for (size_t i = first.base; i < end.base; i += first.size * 2)
	{
		IndexSwapIf(i, i + first.size, container);
	}
	MergeInsertionSort(MakeGroupIndex(first, 2), MakeGroupIndex(end, 2), container);

	Container	mainChain;
	Container	sideChain;

	for (size_t i = first.base; i < end.base; i += first.size * 2)
	{
		mainChain.insert(mainChain.end(), IndexToIter(container, i), IndexToIter(container, i + first.size));
		sideChain.insert(sideChain.end(), IndexToIter(container, i + first.size), IndexToIter(container, i + (first.size * 2)));
	}
	if (container.size() > end.base)
		sideChain.insert(sideChain.end(), IndexToIter(container, end.base), container.end());

	size_t	current_main = first.size;
	size_t	current_side = 0;

	mainChain.insert(mainChain.begin(), sideChain.begin(), IndexToIter(sideChain, first.size));
	current_main += first.size;

	for (size_t	pow2 = 1, jn = 0, dist = 2;
		 current_side + first.size < sideChain.size();
		 pow2 *= 2, jn = pow2 - jn, dist = 2 * jn)
	{
		size_t	it, pe;

		pe = current_side + (dist * first.size);
		it = current_main + (dist * first.size);
		if (it > mainChain.size())
			it = mainChain.size();
		while (pe >= (sideChain.size() / first.size) * first.size)
			pe -= first.size;
		current_main = it;
		while (pe > current_side)
		{
			size_t	insertion_point = UpperBound(mainChain, 0, it, sideChain[pe], first.size);
			mainChain.insert(IndexToIter(mainChain, insertion_point), IndexToIter(sideChain, pe),
							 IndexToIter(sideChain, pe + first.size));
			current_main += first.size;
			if (it == insertion_point)
				it -= first.size;
			if (pe > first.size)
				pe -= first.size;
			else
				pe = 0;
		}
		current_side += (dist * first.size);
	}

	if (container.size() > last.base)
		mainChain.insert(mainChain.end(), IndexToIter(container, last.base), container.end());
	container = mainChain;
}

#endif
