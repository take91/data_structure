package com.take91.ds.list;

public class DynamicDoubleList<T> extends DynamicSingleList<T> {
	private class DoubleNode extends Node {
		DoubleNode prevLink;
	}

	private DoubleNode firstNode;
	private DoubleNode lastNode;
	private int size;

	public DoubleNode fromTailSearch(DoubleNode n, int index) {
		if (n.index == index) {
			return n;
		} else if (n.prevLink != null && n.index != index) {
			return fromTailSearch(n.prevLink, index);
		} else {
			return null;
		}
	}

	public DynamicDoubleList() {
		this.firstNode = new DoubleNode();
		this.lastNode = firstNode;
	}

	@Override
	public T get(int index) {
		if (index >= size || index < 0) {
			throw new IndexOutOfBoundsException();
		} else if (index < size / 2) {
			return super.search(this.firstNode, index).data;
		} else {
			return fromTailSearch(this.lastNode, index).data;
		}
	}

	@Override
	public void add(T data) {
		if (size == 0) {
			this.firstNode.data = data;
			this.firstNode.index = 0;
			this.size++;
		} else {
			DoubleNode newNode = new DoubleNode();
			newNode.data = data;
			newNode.prevLink = lastNode;
			newNode.index = this.lastNode.index + 1;
			this.lastNode.nextLink = newNode;
			this.lastNode = newNode;
			this.size++;
		}
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
