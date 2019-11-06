//
//  CustomQueue.cpp
//  DataStructure
//
//  Created by Gonhong on 2019/11/06.
//  Copyright © 2019 Gonhong. All rights reserved.
//

#include "CustomQueue.hpp"
#include <iostream>
using namespace std;

typedef struct qNode{
    char* data;
    struct qNode* next;
} Node;

typedef struct listQueue{
    Node* front;
    Node* rear;
    int size;
} Queue;


void createQueue(Queue* queue){
    queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

Node* createNode(char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(data)+1);
    newNode->next = NULL;
    
    return newNode;
}


void deleteNode(Node* remove){
    free(remove->data);
    free(remove);
}

Node* peek(Queue* queue){
    return queue->front;
}

void enQueue(Queue* queue, Node* newNode){
    // 아무것도 없을 때
    if(queue->size==0){
        queue->front = newNode;
        queue->rear = newNode;
    }
    
    // 뭔가 있을 때
    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    queue->size++;
}


Node* deQueue(Queue* queue){
    Node* tmp = queue->front;
    
    // 꺼낼 노드가 없을 때
    if(queue->size == 0){
        std::cout<<"Queue has Nothing"<<std::endl;
        return NULL;
    }
    else if(queue->size == 1){
        queue->front = NULL;
        queue->rear = NULL;
        queue->size--;
    }
    else{
        queue->front = queue->front->next;
        queue->size--;
    }
    
    return tmp;
}


void deleteQueue(Queue* queue){
    
    int cnt = queue->size;
    
    // 큐가 가진 노드를 하나씩 꺼내서 지워줌
    while(cnt--!=0){
        Node* tmp = deQueue(queue);
        cout<<"Dequeued Data : "<<tmp->data<<endl;
        deleteNode(tmp);
    }
    free(queue);
}
