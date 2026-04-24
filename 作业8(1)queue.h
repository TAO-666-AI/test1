#pragma once
#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H
typedef struct {
	QElemType element[MAXSIZE];
	int front;
	int rear;
}SeqQueue;
void InitQueue(SeqQueue* Q) {
	Q->front = Q->rear = 0;
}

bool _IsFull(SeqQueue* Q) {
	return (Q->rear + 1) % MAXSIZE == Q->front;
}

bool _IsEmpty(SeqQueue* Q) {
	return Q->rear == Q->front;
}

void EnterQueue(SeqQueue* Q, QElemType x) {
	if (_IsFull(Q))
		return;
	Q->element[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
}

void DeleteQueue(SeqQueue* Q, QElemType* x) {
	if (_IsEmpty(Q))
		return;
	*x = Q->element[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
}
#endif