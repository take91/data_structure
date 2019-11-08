//
//  CustomQueue.cpp
//  DataStructure
//
//  Created by Gonhong on 2019/11/06.
//  Copyright © 2019 Gonhong. All rights reserved.
//


typedef struct qNode{
    char* data;
    struct qNode* next;
} Node;

typedef struct listQueue{
    Node* front;
    Node* rear;
    int size;
} Queue;


