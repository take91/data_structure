package com.take91.ds.list;

public class DynamicSingleList<T> implements CustomList<T> {
	class Node {
		T data;
		Node nextLink;
		int index;
	}

	private Node firstNode;
	private Node curNode;
	private int size = 0;

	public DynamicSingleList() {
		this.firstNode = new Node();
		this.curNode = firstNode;
	}

	public Node search(Node n, int index) {
		if (n.index == index) {
			return n;
		} else if (n.nextLink != null && n.index != index) {
			return search(n.nextLink, index);
		} else {
			return null;
		}
	}

	@Override
	public T get(int index) {
		if (index >= this.size || index < 0) {
			throw new IndexOutOfBoundsException();
		}
		return search(this.firstNode, index).data;
	}

	@Override
	public void add(T data) {
		if (size == 0) {
			this.firstNode.data = data;
			this.firstNode.index = 0;
			this.size++;
		} else {
			Node newNode = new Node();
			newNode.data = data;
			newNode.index = this.curNode.index + 1;
			this.curNode.nextLink = newNode;
			this.curNode = newNode;
			this.size++;
		}
	}

	@Override
	public int size() {
		return this.size;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < this.size; i++) {
			if (i != this.size - 1) {
				sb.append(get(i) + " , ");
			} else {
				sb.append(get(i));
			}
		}
		return "[ " + sb.toString() + " ]";
	}
}
