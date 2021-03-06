#include <iostream>
#include <cstring>

int pf=0, pp=0;
int queue[10000];

void push();
void pop();
void size();
void empty();
void front();
void back();

int main() {
	int n;
	
	std::cin>>n;
	
	for(int i=0; i<n; i++) {
		char name[6];
		
		std::cin>>name;
		
		if(strcmp(name, "push")==0)
			push();
		else if(strcmp(name, "pop")==0)
			pop();
		else if(strcmp(name, "size")==0)
			size();
		else if(strcmp(name, "empty")==0)
			empty();
		else if(strcmp(name, "front")==0)
			front();
		else if(strcmp(name, "back")==0)
			back();
	}
	
	return 0;
}

void push() {
	std::cin>>queue[pf];
	pf++;
}
void pop() {
	if(pp==pf) std::cout<<"-1"<<std::endl;
	else {
		std::cout<<queue[pp]<<std::endl;
		pp++;
	}
}
void size() {
	std::cout<<pf-pp<<std::endl;
}
void empty() {
	if(pp==pf) std::cout<<'1'<<std::endl;
	else std::cout<<'0'<<std::endl;
}
void front() {
	if(pp==pf) std::cout<<"-1"<<std::endl;
	else std::cout<<queue[pp]<<std::endl;
}
void back() {
	if(pp==pf || pf==0) std::cout<<"-1"<<std::endl;
	else std::cout<<queue[pf-1]<<std::endl;
}

