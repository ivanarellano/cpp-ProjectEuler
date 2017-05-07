#pragma once

template<class T>
class Tree {
public:
	~Tree();
private:
	template<class T>
	class Node {
	public:
		T data;
		Node<T>* left;
		Node<T>* right;
		Node<T>(const T& d) : data(d), left(), right() {}
		Node<T>(const Node<T>& copyNode, Node<T>* left, Node<T>* right) : data(copyNode.data), left(left), right(right) {}
	private:
		Node<T>& operator=(const Node<T>&) = delete;
	};
};

template<class T>
Tree<T>::~Tree() {
}