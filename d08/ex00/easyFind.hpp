template <typename T>
typename T::const_iterator easyFind(T &src, int toFind) {
	typename T::const_iterator it;
	it = src.begin();
	while (it != src.end() && *it != toFind)
		++it;
	if (it == src.end())
		throw std::out_of_range("Not found");
	else
		return (it);
}
