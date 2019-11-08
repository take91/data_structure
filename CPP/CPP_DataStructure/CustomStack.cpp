//
//  CustomStack.cpp
//  DataStructure
//
//  Created by Gonhong on 2019/11/08.
//  Copyright © 2019 Gonhong. All rights reserved.
//
#include <iostream>
using namespace std;

typedef struct StackNode{
    char* data;
    struct StackNode* under;
} Node;

typedef struct customStack{
    Node* top;
    Node* bottom;
    int size;
} Stack;

void createStack(Stack* stack){
    stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size=0;
}

Node* createNode(const char* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(data)+1);
    strcpy(newNode->data, data);
    newNode->under = NULL;
    
    return newNode;
}


void deleteNode(Node* remove){
    free(remove->data);
    free(remove);
}

void push(Stack* stack, Node* node){
    // 아무 것도 없을 때
    if(stack->size==0){
        stack->top = node;
        stack->bottom = node;
    }
    
    
    // 뭔가 있을때
    else{
        node->under = stack->top;
        stack->top = node;
    }
    
    stack->size++;
}

Node* pop(Stack* stack){
    Node* tmp = stack->top;
    
    // 꺼낼 노드가 없을 때
    if(stack->size == 0){
        cout<<"Stack has Nothing"<<endl;
        return NULL;
    }
    else if(stack->size == 1){
        stack->top = NULL;
        stack->bottom = NULL;
    }
    else{
        stack->top = stack->top->under;
    }
    
    stack->size--;
    return tmp;
    
}

void deleteStack(Stack* stack){
    int cnt = stack->size;
    
    // 큐가 가진 노드를 하나씩 꺼내서 지워줌
    while(cnt--!=0){
        Node* tmp = pop(stack);
        std::cout<<"Poped Data : "<<tmp->data<<std::endl;
        deleteNode(tmp);
    }
    free(stack);
}
