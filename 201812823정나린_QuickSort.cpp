#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int list[], int p, int r)
{
	int tmp;
	int x = list[r];
	int i=p-1;
	for(int j=p; j<=r-1; j++){
		if(list[j]<=x){
			++i;
			tmp=list[i];
			list[i]=list[j];
			list[j]=tmp;
		}
	}
	++i;
	tmp=list[i];
	list[i]=list[r];
	list[r]=tmp;
	return i;
}

void quicksort(int list[], int p, int r)
{
	if(p<r){
		int q=partition(list, p, r);
		quicksort(list, p, q-1);
		quicksort(list, q+1, r);
	}
}

int main(){
	int n;
	cout << "배열의 크기를 입력하세요: ";
	cin >> n;
	int list[n];
	for(int i=0; i<n; i++){
		list[i]=rand()%20000;
	}
	cout << "\n--QuickSort result--\n\n" << "정렬 전 ( ";
	for(int i=0; i<n; i++){
		cout<<list[i] << " ";
	}
	cout << ")\n";
	
	quicksort(list, 0, n-1); 
	
	cout << "정렬 후 ( ";
	for(int i=0; i<n; i++){
		cout << list[i] << " ";
	}
	cout << ")"; 
	
	return 0;
}
