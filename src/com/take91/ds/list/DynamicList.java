package com.take91.ds.list;

public class DynamicList<T> implements CustomList<T> {
	private class Node {
		T data;
		Node nextLink;
		int index;

		public Node search(Node n, int index) {
			if (n.index == index) {
				return n;
			} else if (n.nextLink != null && n.index != index) {
				return search(n.nextLink, index);
			} else {
				return null;
			}
		}
	}

	private Node firstNode;
	private Node curNode;
	private int size = 0;

	public DynamicList() {
		this.firstNode = new Node();
		this.curNode = firstNode;
	}

	@Override
	public T get(int index) {
		if (index >= this.size) {
			throw new IndexOutOfBoundsException();
		}
		return this.firstNode.search(this.firstNode, index).data;
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
		return super.toString();
	}

}
