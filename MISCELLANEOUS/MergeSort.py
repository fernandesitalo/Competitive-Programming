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
	for i in vetorAux:
		vetor[idx] = i
		idx += 1

def mergeSort(vetor,l,r): #divide o vetor na descida da recursao e na subida e os junta de forma ordenada
	if r > l:
		middle = (l+r)//2  # divisao inteira, meio do vetor
		mergeSort(vetor,l,middle)
		mergeSort(vetor,middle+1,r)
		merge(vetor,l,r,middle)
	
if __name__ == '__main__':
	a = [10,2,7,4,2,8,0,31,4,5]
	mergeSort(a,0,len(a)-1)	
	print(a)					
