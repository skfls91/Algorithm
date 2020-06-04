#include<iostream>
using namespace std;

char p[14];
int rank[14];


void Make_set2(char x)
{
	int id = x-'a';
	p[id]=x;
	rank[id]=0;
}

int Find_Set(char x)
{
	int id = x-'a';
	if(x==p[id]) 
		return x;
	else 
		return Find_Set(p[id]);
}

void Union2(char x, char y)
{
	x=Find_Set(x);
	y=Find_Set(y);
	int idx = x-'a';
	int idy = y-'a';
	if(rank[idx]>rank[idy]){
		p[idy]=x;
	}
	else{
		p[idx]=y;
		if(rank[idx]==rank[idy])
			rank[idy]+=1;

	}
}


int main(){
	char key;
	

	//루트c 트리 
	for(int i=0; i<4; i++){
		cin >> key;
		Make_set2(key);
	}
	
	Union2('h', 'c');
	Union2('a', 'b');
	Union2('b', 'c');
	
	for(int i=0; i<14; i++){
		if(p[i]!='\0'){
			cout << " " << (char)(i+97) << " 부모: " << p[i] << "\trank: " << rank[i] << "\n"; 
		}
	}
	
	cout << "\n";
	
	//루트e 트리 
	for(int i=0; i<5; i++){
		cin >> key;
		Make_set2(key);
	}
	
	//after union
	Union2('d', 'e');
	Union2('m', 'f');
	Union2('f', 'k');
	Union2('f', 'e');
	

	for(int i=0; i<14; i++){
		if(p[i]!='\0'){
			cout << " " << (char)(i+97) << " 부모: " << p[i] << "\trank: " << rank[i] << "\n" ; 
		}
	
	}
	
	cout << endl;
	
	//전체 유니온
	cout << "\nAfter Union2(c, e)\n";
	cout << "#-------------------------#\n"; 
	Union2('c', 'e');

	for(int i=0; i<14; i++){
		if(p[i]!='\0'){
			cout << " " << (char)(i+97) << " 부모: " << p[i] << "\trank: " << rank[i] << "\n"; 
		}
	}
	cout << "#-------------------------#\n"; 
	return 0;
}
