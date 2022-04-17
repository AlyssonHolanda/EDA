/* Estrutura de dados e algoritmos
*  Implementação Bubblesort otimizado
*  Autor: Alysson Lima */
#include<iostream>


using namespace std;

void bubbleSort(int a[], int n) {
    cout<< "n: " << n << endl;
    bool flag = true;
    int context = 0, contint = 0; // contadores de iterações
    while (flag == true){
        flag = false; 
        context++;
        for (int j = 0; j <= n-1; j++) {
            contint++;
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = true;           
            } 
        }
        n = n-1; // otimização laço interno
    }
cout<< "quantidade de iteracoes laco externo: " << context << endl;
cout <<"quantidade de iteracoes laco interno: " << contint << endl;
}

// imprimir um vetor
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl; 
}

int main(){
    // criacao do vetor de testes
  int arr[] = {36, 92, 66, 60, 36, 83, 39, 100, 35, 39, 24, 60, 87, 57, 56, 37, 60, 74, 3, 57, 49, 68, 19, 67, 64, 99, 89, 31, 40, 78, 90, 12, 13, 75, 20, 17, 72, 99, 56, 37, 19, 25, 34, 26, 24, 36, 99, 56, 33, 75, 66, 59, 78, 85, 88, 83, 10, 78, 92, 79, 19, 60, 3, 100, 56, 13, 44, 82, 60, 84, 16, 94, 57, 2, 52, 66, 70, 79, 47, 63, 48, 32, 77, 97, 23, 76, 96, 60, 33, 70, 14, 25, 50, 5, 63, 66, 42, 31, 61, 15};
  int n = sizeof(arr)/sizeof(arr[0]); // calcula o tamanho do vetor arr
  cout << "Vetor de entrada:" << endl;
  printArray(arr, n);

   bubbleSort(arr, n);
  cout << "Vetor ordenado:" << endl;
  printArray(arr, n);
  return 0;
}