#include <bits/stdc++.h>
using namespace std;

template< class T>
class Node{
public:
	Node * next;
	T content;
public:	
	Node(): next(0),content() {}
	static Node* buildNode(T * content_){
		Node * temp = new Node;
		temp->content = *content_;
		return temp;
	}
	static void desconstructNode(Node * No){ if(No) delete No;}
};

template<class TT>
class LIST{ // simplismente encadeada
private:
	Node<TT> * front;	
	int size;
public:	
	LIST():front(0),size(0){}
	
	~LIST(){ clear(); }	
	
	void push_front(TT content_){ // COLOCA NO COMEÇO
		Node<TT> *NEW = Node<TT>::buildNode(&content_);
		NEW->next = front;
		front = NEW;	
		size++;
	}
	
	void push_back(TT content_){ // COLOCA NO FINAL
		Node<TT> *NEW = Node<TT>::buildNode(&content_);
		if(!front) push_front(content_);
		else{
			Node<TT> **aux = &front;
			while((*aux)->next) { aux = &(*aux)->next; } //  vai ate o final, pra colocar no final
			(*aux)->next = NEW;		
			NEW->next = 0;	
			size++;
		}
	}
	
	void clear(){
		while(front){
			Node<TT> * aux = front;
			front = front->next;
			Node<TT>::desconstructNode(aux);
		}
		front = 0,size = 0;
	}
	
	void PRINT(){
		Node<TT> *aux = front;		
		while(aux){ printf("%d\n",aux->content),aux = aux->next; }
	}
};

/* ///////////////////////////////////
template <class T> 
class NodeD : public Node<T> {
public: 
	Node<T> * prev;
public: 
	
	NodeD():Node<T>(),prev(0){}
	
	NodeD(T * content_):Node<T>(),prev(0){ this.content = *content_; }
	
	static NodeD* buildNode(T * content_){
		NodeD * NOVO = new NodeD<T>(content_);
		return NOVO;
	}
};


template <class TT>
class ListaD : public LIST {
private:
	
public:
}
*///////////////////////////////////////




int main(){
	return 0;
}
