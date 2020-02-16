# Alunos : Bruno Almeda e Italo Fernandes
# problema : ordenacao de um vetor 
# solucao : Algoritmo MergeSort  - O(nlgn)
def merge(vetor,l,r,m): #junta dois vetores de forma ordenada
	pta = l
	ptb = m+1
	vetorAux = []
	while pta <= m and ptb <= r:
		if vetor[pta] < vetor[ptb]:
			vetorAux.append(vetor[pta])
			pta += 1
		else:
			vetorAux.append(vetor[ptb])
			ptb += 1
	for i in range(pta,m+1):
		vetorAux.append(vetor[i])
	for i in range(ptb,r+1):
		vetorAux.append(vetor[i])
	idx = l
	for i in vetorAux: #copia vetor ordenado para o vetor original
		vetor[idx] = i
		idx += 1

def mergeSort(vetor,l,r): #divide o vetor na descida da recursao e na subida e os junta de forma ordenada
	if r > l:
		middle = (l+r)//2  # divisao inteira, meio do vetor
		mergeSort(vetor,l,middle)	# metade da esquerda do vetor
		mergeSort(vetor,middle+1,r)	# metade da direita do vetor
		merge(vetor,l,r,middle)		# uniao das metades ordenadas
	
if __name__ == '__main__':
	a = [10,2,7,4,2,8,0,31,4,5] # teste alfa
	mergeSort(a,0,len(a)-1)		# chamada da funcao
	print(a)					# imprime vetor ordenado
	
