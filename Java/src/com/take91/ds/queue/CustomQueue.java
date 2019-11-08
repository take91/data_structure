package com.take91.ds.queue;

public class CustomQueue {
	 class Node {
		String data;
		Node next;
	}

	private Node front;
	private Node rear;
	private int size;

	public int size() {
		return size;
	}
	
	

	void enQueue(String data) {

		if (this.size == 0) {
			Node newNode = new Node();
			newNode.data = data;
			this.front = newNode;
			this.rear = newNode;
			this.size++;
		} else {
			Node newNode = new Node();
			newNode.data = data;
			this.rear.next = newNode;
			this.rear = newNode;
			this.size++;
		}
	}

	Node deQueue() {
		Node tmp = this.front;

		if (this.size == 0) {
			System.out.println("This Queue has Nothing!");
			return null;
		}

		if (this.size == 1) {
			this.front = null;
			this.rear = null;
			this.size--;
		} else {
			this.front = tmp.next;
			this.size--;
		}
		return tmp;
	}

}
