import queue
def Dijkstra(listaAdjacencia, numVertices , inicio, final ):
	dist = [ float('inf') for i in range(numVertices) ] # monta array de distancia
	q = queue.PriorityQueue()
	dist[inicio] = 0
	q.put((0,inicio))
	while q.qsize() > 0:
		distancia,atual = q.get()
		if distancia > dist[atual]:
			continue		
		for i in range(len(listaAdjacencia[atual])):
			vizinho,custo = listaAdjacencia[atual][i]
			if dist[vizinho] > dist[atual] + custo:
				dist[vizinho] = dist[atual] + custo
				q.put((dist[vizinho],vizinho))
	return dist[final]
	
if __name__ == '__main__':
	T = int(input())
	for ct in range(T): 
		n,m,s,t = map(int,input().split())
		grafo = [[] for i in range(n+2)] #lista de adjacencia
		for i in range(m):
			a,b,c = map(int,input().split())
			grafo[a].append((b,c))
			grafo[b].append((a,c))
		ans = Dijkstra(grafo,n+2,s,t)
		print('Case #%s: %s'%(ct+1,'unreachable' if ans == float('inf') else ans))
	
