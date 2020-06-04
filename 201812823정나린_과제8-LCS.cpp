#include<iostream>
using namespace std;

char Xm[9]="abcbdabc";
char Yn[8]="bdcabac";
int C[9][8];

void LCS(int m, int n){
	for(int i=0; i<=m; i++)
		C[i][0]=0;
	for(int i=0; i<=n; i++)
		C[0][i]=0;
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
		{
			int p=i+1;
			int q=j+1;
			if(Xm[i]==Yn[j]) C[p][q]=C[p-1][q-1]+1;
			else C[p][q]=max(C[p-1][q], C[p][q-1]);
		}
	}		
}

int main(){
	LCS(8, 7);
	cout << "\n***C[m,n] 원소 출력***\n\n";
	for(int i=0; i<=8; i++){
		cout << " ";
		for(int j=0; j<=7; j++){
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nLCS의 길이: " <<C[8][7] << "\n";
	return 0;
}
