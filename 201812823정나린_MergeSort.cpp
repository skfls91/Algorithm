#include<iostream>
#include<cstdlib>
using namespace std;

int n; 
void merge(int list[], int p, int q, int r)
{
	int i=p; int j=q+1; int t=1;
	int tmp[n];
	while(i<=q && j<=r)
	{
		if(list[i]<=list[j])
			tmp[t++]=list[i++];
		else 
			tmp[t++]=list[j++]; 
	}
	while(i<=q)
		tmp[t++]=list[i++];
	while(j<=r)
		tmp[t++]=list[j++];
	i=p; t=1;
	while(i<=r) //����� ���� 
		list[i++]=tmp[t++];
}
void mergesort(int list[], int p, int r)
{
	if(p<r){
		int q=(p+r)/2;
		mergesort(list, p, q);
		mergesort(list, q+1, r);
		merge(list, p, q, r);
	}
}


int main(){
	cout << " �迭�� ũ�⸦ �Է����ּ���: "; 
	cin >> n;
	int list[n];
	for(int i=0; i<n; i++){
		list[i]=rand()%1000;
	}
	
	cout << "\n--Mergesort result--\n\n"<< "���� �� { ";
	for(int i=0; i<n; i++){
		cout<<list[i] << " ";
	}
	cout << "}\n";
	 
	mergesort(list, 0, n-1); //mergesort ȣ�� 
	
	cout << "���� �� { ";
	for(int i=0; i<n; i++){
		cout << list[i] << " ";
	}
	cout << "}"; 
	return 0;
}
