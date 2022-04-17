/* Estrutura de dados e algoritmos
*  Implementação Timsort
*  Autor: Alysson Lima */

#include<iostream>
#include <bitset>

using namespace std;
const int Minimum = 64;
                    
int calcMinRun(int n){        // Entra com o comprimento do vetor de //entrada
    int r = 0;                      
    while (n >= Minimum){         
        r |= (n & 1);         // r recebe 1 se o dígito menos //significativo de n for 1
        n >>= 1;              // descolamento a direita é //equivalente a dividir n por 2, para aproximar (K/MinRun) de uma //potência de 2
    }                            
    return n + r;             // Retorna o tamanho calculado dos //MinRuns
}
// algoritmo de ordenacao do vetor 
void insertionSort(int arr[], int left, int right)
{
    //O vetor é ordenado do índice da esquerda para 
    //para o índice à direita que é de tamanho no máximo do //subvetor
    for (int i = left + 1; i <= right; i++)
    {
      int temp = arr[i];
      int j = i - 1;
      while (arr[j] > temp && j >= left)
      {
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = temp;
    }
}

// Função para concatenar os sub-vetores ordenados 
void merge(int arr[], int l, int m, int r)
{
//O vetor original é dividido em duas partes: esquerda e //direita
  int len1 = m - l + 1, len2 = r - m;
  int left[len1], right[len2];
  for (int i = 0; i < len1; i++)
    left[i] = arr[l + i];
  for (int i = 0; i < len2; i++)
    right[i] = arr[m + 1 + i];

  int i = 0;
  int j = 0;
  int k = l;

// depois de comparar, nós concatenamos esses dois sub-vetores
// em um vetor 
  while (i < len1 && j < len2)
  {
    if (left[i] <= right[j])
    {
        arr[k] = left[i];
        i++;
    }
    else
    {
        arr[k] = right[j];
        j++;
    }
    k++;
  }

// copia os elementos restantes da esquerda, se houver
  while (i < len1)
  {
    arr[k] = left[i];
    k++;
    i++;
  }

 // copia o elemento restante da direita, se houver
  while (j < len2)
  {
    arr[k] = right[j];
    k++;
    j++;
  }
}

//Algoritmo TIMSORT
void timSort(int arr[], int n)
{
    cout <<("Tamanho do vetor de entrada: ") << (n) << endl;
    
    int minRun = calcMinRun(n);                
    cout << ("Tamanho do minRun: ") << (minRun) << endl;

  // Ordena sub-vetores individuais de tamanho minRun
  for (int i = 0; i < n; i+=minRun)
    insertionSort(arr, i, min((i+minRun), (n-1)));

  // inicia a concatençao do tamanho minRun. 
  for (int size = minRun; size < n; size = 2*size)
  {
  // escolhe o ponto inicial do subvetor esquerdo.
  //Após cada iteração, aumentamos a esquerda em 2*tamanho
    for (int left = 0; left < n; left += 2*size)
    {
        // encontra o ponto final do subvetor esquerdo
         // mid+1 é o ponto inicial do subvetor direito
        int mid = left + size - 1;
        int right = min((left + 2*size - 1), (n-1));

        //mescla os dois sub-vetores
        merge(arr, left, mid, right);
    }
  }
}

//função utilitária para imprimir um vetor
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl; 
}

int main()
{
  int arr[] = {36, 92, 66, 60, 36, 83, 39, 100, 35, 39, 24, 60, 87, 57, 56, 37, 60, 74, 3, 57, 49, 68, 19, 67, 64, 99, 89, 31, 40, 78, 90, 12, 13, 75, 20, 17, 72, 99, 56, 37, 19, 25, 34, 26, 24, 36, 99, 56, 33, 75, 66, 59, 78, 85, 88, 83, 10, 78, 92, 79, 19, 60, 3, 100, 56, 13, 44, 82, 60, 84, 16, 94, 57, 2, 52, 66, 70, 79, 47, 63, 48, 32, 77, 97, 23, 76, 96, 60, 33, 70, 14, 25, 50, 5, 63, 66, 42, 31, 61, 15};

  // calcula o tamanho do vetor arr
  int n = sizeof(arr)/sizeof(arr[0]); 
  cout << "Vetor de entrada:" << endl;
  printArray(arr, n);

  timSort(arr, n);

  cout << "Vetor ordenado:" << endl;
  printArray(arr, n);
  return 0;
}

