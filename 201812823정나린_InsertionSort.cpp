#include<iostream>
#include<cstdlib>
using namespace std;

int n;

void InsertionSort(int list[],int n)
{
	for(int i=1; i<n; i++){
		int num=list[i];
		for(int j=i-1; j>=0; j--){
			if(list[j]>num){
				list[j+1]=list[j];
				if(j==0) list[j]=num;
			}
			else{
				list[j+1]=num;
				break;
			}
		}
	}
}
int main(){

	cout << "�迭�� ũ�⸦ �Է��ϼ���: ";
	cin >> n; 
	int list[n];
	for(int i=0; i<n; i++){
		list[i]=rand()%10000;
	}
	cout << "\n--InsertionSort result--\n\n" << "���� �� [ ";
	for(int i=0; i<n; i++){
		cout<<list[i] << " ";
	}
	cout << " ]\n";
	 
	InsertionSort(list, n);
	
	cout << "���� �� [ ";
	for(int i=0; i<n; i++){
		cout << list[i] << " ";
	}
	cout << " ] "; 
	return 0;
}
