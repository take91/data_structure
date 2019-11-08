package com.take91.ds.queue;

import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		int[] input = new int[1000000];

		for (int i = 0; i < input.length; i++) {
			input[i] = i + 1;
		}

		long start = System.currentTimeMillis();
		System.out.println(linearSearch(input, 1000000));
		long end = System.currentTimeMillis();
		System.out.println((end - start) / 1000.0);

		start = System.currentTimeMillis();
		System.out.println(binarySearch(input, 1000000));
		end = System.currentTimeMillis();
		System.out.println((end - start) / 1000.0);
	}

	static int binarySearch(int[] arr, int data) {

		int median = arr.length / 2;

		if (data > arr[median]) {
			return binarySearch(Arrays.copyOfRange(arr, median, arr.length), data);
		}
		if (data < arr[median]) {
			return binarySearch(Arrays.copyOfRange(arr, 0, median), data);
		} else {
			return arr[median];
		}
	}

	static int linearSearch(int[] arr, int data) {
		int answer = 0;

		while (arr[answer] != data) {
			answer++;
		}

		return arr[answer];
	}

	static int[] selectionSort(int[] input) {

		for (int i = 1; i < input.length; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (input[i] < input[j]) {

				}
			}
		}

		return input;
	}
}
