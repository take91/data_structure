package com.take91.ds.list;
/*
 * 리스트가 기본적으로 가지고 있어야 할 기능을 정의한 인터페이스
 */
public interface CustomList<T> {
	public T get(int index);

	public void add(T data);

	public int size();

}
